# MAX170X Battery Monitor with ESP8266

This repository provides a module to integrate the MAX170X battery fuel gauge with an ESP8266. The module reads battery status (voltage, percentage, and health) and sends the data to a connected system, such as a home automation platform or a connected remote control.

## Features
- Reads battery voltage and state of charge (SOC) using MAX170X (e.g., MAX17043, MAX17048).
- Integrates with ESP8266 via I2C.
- Sends battery data to a central system (e.g., Homebridge, MQTT, etc.).

## Requirements
- **Hardware**:
  - ESP8266 (e.g., NodeMCU, Wemos D1 Mini)
  - MAX170X sensor module
  - Battery (Li-Ion or LiPo)

- **Software**:
  - Arduino IDE or PlatformIO
  - MAX170X library (included in this repository)

## Wiring Diagram
![Wiring Diagram](docs/schematic.png)

| MAX170X Pin | ESP8266 Pin |
|-------------|-------------|
| SDA         | D2 (GPIO4)  |
| SCL         | D1 (GPIO5)  |
| VCC         | 3.3V        |
| GND         | GND         |

## Usage
1. Clone this repository:
   ```bash
   git clone https://github.com/AnisZiadi/max170x-battery-monitor-esp8266.git

