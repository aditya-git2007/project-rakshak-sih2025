# Project "RAKSHAK" — Hardware Schematics & Pinout Architecture

## 🔌 System Wiring Overview
RAKSHAK implements a robust **Hybrid Dual-Controller Architecture**[cite: 9, 10, 11] to isolate high-level wireless communication, GPS telemetry, and sensor data fusion (handled by the ESP32) from low-level real-time actuator execution and motor control (handled by the Arduino)[cite: 9, 10, 11].

---

### **1. Controller 1: ESP32 (The High-Level Brain / MicroPython)**
* **Role:** Manages Wi-Fi WebSockets, GPS coordinate parsing, environmental sensor aggregation, and transmits operational commands to the motor controller[cite: 9, 10, 11].
* **Pin Assignments:**
  * `GPIO 16 (RX2)` / `GPIO 17 (TX2)` $\to$ UART Serial Link to Arduino[cite: 9, 10]
  * `GPIO 4 (TX)` / `GPIO 35 (RX)` $\to$ NEO-6M GPS Module[cite: 9, 10, 11]
  * `GPIO 21 (SDA)` / `GPIO 22 (SCL)` $\to$ I2C Bus (Environmental Sensors: BME280 / Gas / Smoke)[cite: 11]
  * `GPIO 13` $\to$ PIR Motion Sensor (Survivor Heat/Motion Detection)[cite: 10, 11]
  * `GPIO 12` $\to$ Flame & Methane Sensor Analog/Digital Inputs[cite: 10, 11]
  * `GPIO 2` $\to$ High-Intensity LED Signaling System & Status Relay[cite: 9, 10, 11]

---

### **2. Controller 2: Arduino Mega / Uno (Low-Level Motor Controller / C++)**
* **Role:** Directly drives the 6-wheel rocker-bogie motors via L298N drivers and executes immediate safety/drive commands[cite: 9, 10, 11].
* **Pin Assignments:**
  * `Digital Pins 2, 3, 4, 5` $\to$ L298N Motor Driver Control Inputs (`IN1`, `IN2`, `IN3`, `IN4`)
  * `PWM Pins 9, 10` $\to$ Motor Speed Control (`ENA`, `ENB`)
  * `TX1 / RX1` $\to$ Serial Feedback Loop to ESP32[cite: 9, 10]
  * `A0 - A5` $\to$ Analog sensor backup / emergency proximity triggers

---

### **3. Power Management & Telemetry**
* **Battery Array:** Dual 4000 mAh Li-ion battery packs wired in parallel/hot-swappable configuration through a Battery Management System (BMS)[cite: 9, 10, 11].
* **Solar Integration:** Onboard solar panel connected via a charge controller module to provide continuous trickle-charging during extended field operations[cite: 9, 10, 11].
* **Failsafe Logic:** Voltage divider connected to an analog pin on the ESP32 to monitor battery levels, triggering an automated "Return to Base" protocol at critical thresholds (<15%)[cite: 9, 10].
