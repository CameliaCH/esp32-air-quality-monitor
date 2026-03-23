# esp32-air-quality-monitor
Low-cost air quality monitor using ESP32, MQ135, and DHT11 — reads gas, temperature, and humidity via a self-hosted Wi-Fi webpage.

# Low-Cost Air Pollution Analyser

A simple, low-cost air quality monitoring system using an **ESP32**, **MQ135 gas sensor**, and **DHT11 temperature/humidity sensor**. Sensor readings are served via a Wi-Fi hosted webpage that auto-refreshes every 3 seconds.

---

## Components Required

| Component | Quantity |
|-----------|----------|
| ESP32 Dev Board | 1 |
| MQ135 Gas Sensor | 1 |
| DHT11 Temp & Humidity Sensor | 1 |
| Jumper Wires | Several |
| Breadboard | 1 |
| USB Cable (for power/programming) | 1 |

---

## Wiring / Pin Connections

### MQ135 Gas Sensor
| MQ135 Pin | ESP32 Pin |
|-----------|-----------|
| A0 | GPIO34 |
| VCC | 5V |
| GND | GND |

### DHT11 Temperature & Humidity Sensor
| DHT11 Pin | ESP32 Pin |
|-----------|-----------|
| DATA | GPIO4 |
| VCC | 3.3V |
| GND | GND |

---

## Required Libraries

Install these via the **Arduino IDE Library Manager** (`Sketch → Include Library → Manage Libraries`):

- **DHT sensor library** by Adafruit
- **Adafruit Unified Sensor** (dependency for DHT)

---

## How to Use

1. Wire the components as shown in the table above.
2. Open the code in Arduino IDE.
3. Replace the Wi-Fi credentials with your own.
4. Select your ESP32 board under `Tools → Board`.
5. Upload the sketch.
6. Open the **Serial Monitor** at `115200` baud.
7. Once connected, the IP address will be printed — open it in any browser on the same Wi-Fi network.
8. The webpage will auto-refresh every 3 seconds with live sensor data.

---

## Output

The web dashboard displays:
- **Temperature** (°C)
- **Humidity** (%)
- **Gas Value** (analog reading from MQ135)

---

## ⚠️ Notes

- The MQ135 outputs a **raw analog value** (0–4095 on ESP32's 12-bit ADC). For actual PPM readings, calibration is required.
- The DHT11 has ±2°C temperature accuracy and ±5% humidity accuracy.
- Make sure the MQ135 is **warmed up** for at least 24 hours before relying on readings.

---

## License

This project is open source. Feel free to use, modify, and distribute it.
