import network
import socket
import time
from machine import Pin, UART, I2C

# Initialize Wi-Fi Access Point / Station
WIFI_SSID = "RAKSHAK_Command"
WIFI_PASS = "rescue2025"

def setup_wifi():
    ap = network.WLAN(network.AP_IF)
    ap.active(True)
    ap.config(essid=WIFI_SSID, password=WIFI_PASS)
    print(f"Network active. Connect to {WIFI_SSID} for Dashboard.")

# Initialize UART Serial Communication with Arduino
uart = UART(2, baudrate=9600, tx=17, rx=16)

# Initialize Sensors & Peripherals
pir_sensor = Pin(13, Pin.IN)
flame_sensor = Pin(12, Pin.IN)
led_signal = Pin(2, Pin.OUT)

def read_sensor_metrics():
    # Gather data from environmental sensors and PIR
    motion_detected = pir_sensor.value()
    hazard_detected = flame_sensor.value()
    
    # Calculate dummy Air Quality Score (0-100 scale)
    air_quality_score = 85 if not hazard_detected else 35
    
    return {
        "motion": bool(motion_detected),
        "hazard": bool(hazard_detected),
        "airQualityScore": air_quality_score,
        "batteryLevel": 88  # Percentage placeholder from ADC
    }

def main():
    setup_wifi()
    print("RAKSHAK Master Controller (ESP32) Initialized.")
    
    while True:
        metrics = read_sensor_metrics()
        
        # Send motion/drive commands to Arduino via UART if needed
        if metrics["hazard"]:
            uart.write(b"CMD:STOP_HAZARD\n")
            led_signal.value(1) # Flash warning LED
        else:
            led_signal.value(0)
            
        print(f"Telemetry Data: {metrics}")
        time.sleep(1.0)

if __name__ == "__main__":
    main()
