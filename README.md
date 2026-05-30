# DHT11_Wemos — Task 6 (UNSIA IoT 2026)

PlatformIO project for reading DHT11 sensor on Wemos D1 Mini.

## Wiring

| DHT11 | Wemos D1 Mini |
|-------|---------------|
| VCC   | 3.3V          |
| GND   | GND           |
| DATA  | D3 (GPIO 0)   |

## How to use in VSCode + PlatformIO

1. Open VSCode
2. Install the **PlatformIO IDE** extension if not already installed
3. File -> Open Folder -> select this `DHT11_Wemos` folder
4. PlatformIO will auto-detect `platformio.ini` and install dependencies
5. Click **Build** (the checkmark icon, bottom toolbar) to compile
6. With Wemos D1 Mini connected via USB: click **Upload** (the right arrow icon)
7. Open **Serial Monitor** (the plug icon) to see readings at 115200 baud

## Expected output

```
DHT11 Sensor Reader -- Task 6 (PlatformIO + Wemos D1 Mini)
Reading every 5 seconds...

Humidity: 58.0 %    Temperature: 27.3 C
Humidity: 58.1 %    Temperature: 27.3 C
Humidity: 58.0 %    Temperature: 27.4 C
...
```

## No hardware? Just verify build

Per task instructions, if you don't have a Wemos board:
- Click **Build** only (do not Upload)
- Screenshot the "SUCCESS" build output from the terminal
- That is acceptable for submission
