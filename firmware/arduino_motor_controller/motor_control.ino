// RAKSHAK Low-Level Motor & Actuator Controller (Arduino C/C++)

// Motor Driver Pin Definitions (L298N)
const int ENA = 9;
const int ENB = 10;
const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

// Status LED / Buzzer
const int BUZZER_PIN = 7;

void setup() {
  // Setup motor control pins
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Initialize Serial communication with ESP32
  Serial.begin(9600);
  stopRover();
}

void loop() {
  // Check for commands from ESP32 master brain
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "CMD:STOP_HAZARD") {
      stopRover();
      triggerAlarm();
    } else if (command == "CMD:MOVE_FORWARD") {
      moveForward(200); // PWM Speed
    } else if (command == "CMD:MOVE_BACKWARD") {
      moveBackward(200);
    }
  }
}

void moveForward(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopRover() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void triggerAlarm() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(BUZZER_PIN, LOW);
}
