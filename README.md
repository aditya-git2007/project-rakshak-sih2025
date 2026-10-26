# Project "RAKSHAK" — Advanced All-Terrain Disaster Response Rover

> **Smart India Hackathon (SIH) 2025 Submission**  
> **Problem Statement ID:** 25117 / 25122 | **Theme:** Robotics, Drones & Disaster Management | **Team Name:** Quantum Sparks  

---

## 🚀 Overview
**RAKSHAK** (Rescuer) is an advanced, semi-autonomous ground robotic platform engineered as a first-responder asset for disaster management and high-risk operations (designed for agencies like the NDRF)[cite: 10]. It autonomously maps hazardous environments, detects survivors, and establishes a vital communication link before any human first-responder enters a dangerous area[cite: 10].

---

## 🛠️ Key Architectural Features

### 1. Mechanical & Mobility Design
* **Chassis:** 6-wheel rocker-bogie suspension system inspired by Chandrayaan-3 and NASA's Mars rovers, ensuring high mobility and stability over unstructured rubble and rough terrain[cite: 11].
* **Energy System:** Dual 4000 mAh Li-ion battery packs in a hot-swappable configuration, supplemented by an onboard solar panel for extended field standby and an automated **"Return to Base"** low-battery failsafe[cite: 9, 10, 11].

### 2. Hybrid Dual-Controller Architecture (Core Innovation)
* **High-Level Brain (ESP32):** Runs MicroPython/Python for complex task management, sensor data fusion, GPS coordinate parsing, and real-time dashboard data streaming over Wi-Fi[cite: 9, 10, 11].
* **Low-Level Motor Controller (Arduino Mega/Uno):** Runs highly optimized C/C++ code for immediate, precise real-time motor control, drive commands, and low-latency obstacle handling[cite: 9, 10, 11].
* **Inter-Controller Link:** Reliable Serial (UART) communication protocol with error checking between the ESP32 and Arduino[cite: 9, 10].

### 3. Comprehensive Sensor Suite (>10 Sensors)
* **Hazard Detection:** Gas, methane, smoke, flame, temperature, pressure, vibration, and water-level sensors feeding into an intelligent **"Air Quality Score"** algorithm[cite: 11].
* **Survivor Detection:** PIR motion sensors and thermal-assisted detection signatures[cite: 11].
* **Talk-Back Communication System:** Integrated microphone, speakers, and display providing a direct conduit for psychological support to trapped victims and real-time intelligence gathering for rescuers[cite: 10, 11].
* **Aerial Support Integration:** A compact, lightweight support drone deployed from the rover for aerial reconnaissance and environmental mapping[cite: 10, 11].

### 4. Command Center & Software Dashboard
* **Dashboard Interface:** Dynamic, browser-based command and control dashboard built with HTML/JS/CSS[cite: 9, 10, 11].
* **Connectivity:** Resilient wireless streaming via WebSockets over Wi-Fi for persistent, low-latency telemetry[cite: 9, 10, 11].
* **Navigation:** Live GPS breadcrumb trail map display logging explored terrain to prevent redundant searches[cite: 9, 10, 11].

---

## 📂 Tech Stack & Tools
* **Microcontrollers:** ESP32 (MicroPython / Python) & Arduino (C / C++)[cite: 9, 10, 11]
* **Communication:** Wi-Fi, WebSockets, UART[cite: 9, 10, 11]
* **Frontend Dashboard:** HTML5, CSS3, JavaScript[cite: 9, 10, 11]
* **Hardware Modules:** NEO-6M GPS, PIR, Gas/Flame/Smoke sensors, Ultra HD Camera, Dual Li-ion Packs, Solar Panel[cite: 9, 10, 11]
