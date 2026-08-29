# Arduino & C++ Smart Parking Sensor

![Circuit Diagram](Spectacular%20Krunk.png)

A smart parking sensor system developed using C/C++ on Arduino Uno, featuring an HC-SR04 ultrasonic distance sensor, status LEDs, a buzzer, and an ON/OFF toggle push button.

## Features
- **Power Control (System Toggle):** Turn the system ON and OFF using a push button via internal `INPUT_PULLUP` logic (simulates turning off the car engine).
- **Non-Blocking Timing:** Built using `millis()` instead of `delay()` to ensure the system remains completely responsive without freezing execution.
- **Visual & Audio Distance Alerts:**
  - 🟢 **Green LED (>30cm):** Safe distance zone (Buzzer stays silent).
  - 🟡 **Yellow LED (15cm - 30cm):** Warning zone (Buzzer beeps once every 3 seconds).
  - 🔴 **Red LED (<15cm):** Danger zone (Buzzer emits continuous alert sound).

## Schematics & Documentation
📄 You can view and download the official circuit schematic PDF here: 
[Download Circuit Schematic (PDF)](arduino%20smart%20parking%20sensor.pdf)

## Components Used
- Arduino Uno
- HC-SR04 Ultrasonic Distance Sensor
- 3x LEDs (Red, Yellow, Green) & 220Ω Resistors
- Active/Passive Buzzer
- Push Button

## Circuit Pins Configuration
| Component | Arduino Pin | Description |
|---|---|---|
| Push Button | Pin 2 | Input (Internal Pull-Up) |
| HC-SR04 (Trig) | Pin 3 | Output |
| HC-SR04 (Echo) | Pin 4 | Input |
| Green LED | Pin 8 | Output |
| Yellow LED | Pin 9 | Output |
| Red LED | Pin 10 | Output |
| Buzzer | Pin 11 | Output |
