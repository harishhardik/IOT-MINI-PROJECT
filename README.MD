# 🌿 Air Quality Alert System

### Arduino-Based Gas Level Monitoring and Alert System with LCD Display and LED Status Indication

The **Air Quality Alert System** is an Arduino-based IoT and sensor technology project designed to monitor relative gas levels in the surrounding environment. It uses an MQ gas sensor, Arduino Uno, a 16×2 I2C LCD, and green and red LEDs to display sensor readings and indicate normal or high-gas conditions.

The system continuously reads sensor values, processes them using predefined thresholds, and provides real-time visual alerts.

## 📌 Project Overview

- **Project Name:** Air Quality Alert System
- **Domain:** Internet of Things (IoT) and Embedded Systems
- **Controller:** Arduino Uno
- **Programming Language:** Embedded C/C++
- **Sensor:** MQ Gas Sensor Module
- **Display:** 16×2 I2C LCD
- **Alert Mechanism:** Green and Red LEDs
- **Institution:** Sri Sairam Engineering College, Chennai
- **Department:** Artificial Intelligence and Data Science
- **Academic Year:** 2026–2027
- **Subject:** IoT and Sensor Technologies
- **Subject Code:** 24AIPC501

## 👥 Team Members

| S.No. | Team Member | Student ID |
|---|---|---|
| 1 | Navashanth N S | SEC24AD044 |
| 2 | Sharukesh V | SEC24AD119 |
| 3 | Jason Devaraj J | SEC24AD095 |
| 4 | Harish S T | SEC24AD139 |
| 5 | Anbuselvan S | SEC24AD159 |

## 🎯 Objectives

- Monitor relative gas sensor readings continuously.
- Display live sensor readings and status messages on an LCD.
- Provide immediate visual alerts when readings exceed the selected threshold or enter the configured high-level range.
- Demonstrate the integration of sensors, microcontrollers, displays, and output indicators.
- Develop a foundation for future air-quality monitoring projects.

## 🛠️ Hardware Components

| Component | Purpose |
|---|---|
| Arduino Uno | Reads sensor values and controls the outputs |
| MQ Gas Sensor Module | Detects changes in gas-sensitive sensor output |
| 16×2 I2C LCD | Displays gas readings and system status |
| Green LED | Indicates normal or low-to-moderate status |
| Red LED | Indicates a high-level alert |
| 220Ω or 330Ω resistors × 2 | Limit LED current |
| Breadboard | Supports circuit prototyping |
| Jumper wires | Connect the components |
| USB cable | Powers the Arduino and uploads the program |

## 🔌 Circuit Connections

### MQ Gas Sensor

| Sensor Pin | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| A0 | A0 |
| D0 | Not connected |

### I2C LCD

| LCD Pin | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

**I2C address:** `0x3F`

### LED Connections

| LED | Connection |
|---|---|
| Green LED anode | Arduino D7 through a 220Ω or 330Ω resistor |
| Red LED anode | Arduino D8 through a 220Ω or 330Ω resistor |
| Both LED cathodes | GND |

Ensure all components share a common ground.

## 💻 Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software)
- Arduino Uno board support
- `Wire.h` library
- `LiquidCrystal_I2C.h` library
- USB connection for programming and serial monitoring

### Libraries Used

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```

The LCD is initialized using:

```cpp
LiquidCrystal_I2C lcd(0x3F, 16, 2);
```

## ⚙️ Working Principle

1. The Arduino Uno powers the MQ gas sensor and initializes the LCD and LEDs.
2. The sensor's analog output is read through pin A0 using `analogRead()`.
3. The raw sensor reading is displayed on the LCD and printed to the Serial Monitor.
4. The program evaluates the reading using the configured threshold or status bands.
5. The LCD displays the corresponding gas-level status.
6. The LEDs indicate the system's current status.
7. The monitoring cycle repeats every second.

### System Status

| Status | LCD Message | Green LED | Red LED |
|---|---|---|---|
| Normal | `Status: NORMAL` | ON | OFF |
| Gas high alert | `ALERT: GAS HIGH` | OFF | ON |

The updated source code in the technical report also demonstrates three relative sensor-level bands: LOW, MODERATE, and HIGH.

## 📊 Sensor Reading and Threshold

The Arduino Uno reads analog values in the range of **0–1023**. The project report records clean-air readings of approximately 104–114 and describes a raw-reading threshold of 120 for demonstrating the alert logic.

The updated example program instead normalizes readings against a configurable maximum value of 500 and classifies them into three bands:

| Relative Level | Normalized Value | Indication |
|---|---|---|
| LOW | Below 30% | Normal |
| MODERATE | 30% to below 60% | Caution |
| HIGH | 60% or above | Alert |

**Implementation note:** The fixed raw threshold of 120 and the three-band percentage classification are two different approaches described in the report. Ensure the README, source code, and actual hardware behavior match the version committed to this repository.

The displayed percentage is a relative sensor scale, not a calibrated gas concentration or parts-per-million (ppm) measurement.

## 🖥️ Example Serial Monitor Output

```text
================================
   GAS LEVEL MONITORING SYSTEM
================================
Raw Sensor Value: 80 | Gas Level: 16%
Status: LOW - NORMAL
--------------------------------
```

Example readings in the report also illustrate MODERATE and HIGH states. These are illustrative values rather than calibrated measurements.

## 📷 Hardware Results

The prototype was assembled on a breadboard and tested with an Arduino Uno.

- **Normal condition:** The LCD displays a normal status and the green LED turns on.
- **Alert condition:** The LCD displays a high-gas alert and the red LED turns on.
- **Live monitoring:** The LCD and Serial Monitor update approximately once per second.

If available, add your actual hardware photographs to the repository under `images/` and display them here:

```markdown
![Normal Condition](images/normal-condition.jpg)

![Gas High Alert](images/gas-high-alert.jpg)
```

## 🚀 Getting Started

1. Clone this repository:

   ```bash
   git clone https://github.com/harishhardik/IOT-MINI-PROJECT.git
   ```

2. Open the project folder.

3. Open the Arduino `.ino` source file in Arduino IDE.

4. Install the required libraries through the Arduino IDE Library Manager.

5. Connect the MQ gas sensor, LCD, and LEDs according to the circuit connections above.

6. Select **Arduino Uno** under Tools → Board and choose the correct serial port.

7. Upload the program to the Arduino Uno.

8. Open Serial Monitor and set the baud rate to `9600`.

9. Observe the LCD readings and LED status during testing.


## 🌍 Applications

- Educational demonstrations of sensor-based monitoring.
- Indoor environmental monitoring prototypes.
- IoT and embedded-systems laboratory projects.
- Basic gas-level indication in controlled demonstrations.
- A starting point for more advanced environmental monitoring systems.

## 🔮 Future Enhancements

- Add a buzzer for audible alerts.
- Calibrate sensor readings against a suitable reference instrument.
- Implement moving averages to reduce reading fluctuations.
- Add hysteresis to prevent rapid status changes near thresholds.
- Integrate Wi-Fi or IoT dashboards for remote monitoring.
- Store readings and visualize trends over time.
- Add suitable sensors for specific target gases and environmental parameters.

## ⚠️ Limitations and Safety

This project is an educational prototype. The sensor readings are relative and have not been calibrated against a reference instrument. The system is **not a certified gas detector or a safety-grade air-quality measurement device**.

Do not rely on this prototype for detecting dangerous gas leaks or protecting people. Use appropriately certified detection equipment for real-world safety applications.

## 📚 References

- [Arduino Official Website](https://www.arduino.cc/)
- [Arduino Language Reference](https://docs.arduino.cc/language-reference/)
- [Arduino Wire Library](https://docs.arduino.cc/language-reference/en/functions/communication/wire/)
- [LiquidCrystal_I2C Library](https://github.com/johnrickman/LiquidCrystal_I2C)
