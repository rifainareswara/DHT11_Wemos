# DHT11_HTTPS_Wemos — Task 7 (UNSIA IoT 2026)

Secure HTTPS data transmission from Wemos D1 Mini to iot.learnina.org
using BearSSL with SHA-1 fingerprint pinning (no setInsecure!).

## Wiring (same as Task 6)

| DHT11 | Wemos D1 Mini V4 |
|-------|------------------|
| VCC   | 3V3              |
| GND   | GND              |
| DATA  | 0 (= GPIO 0)     |

## Before flashing

Edit `src/main.cpp` -- replace these placeholders:

```cpp
#define STASSID "YOUR_WIFI_SSID"
#define STAPSK  "YOUR_WIFI_PASSWORD"
```

with your actual WiFi credentials.

The student ID is already set:
```cpp
#define STUDENTID "230401010231"
```

## Build & upload

```bash
pio run -t upload && pio device monitor
```

Expected serial output:

```
Task 7: Secure HTTPS DHT11 transmission
Connecting to WiFi: <ssid>
....
WiFi connected. IP: 192.168.x.x
Requesting URL: https://iot.learnina.org/dht.php?stationid=230401010231&temperature=27.3&humidity=58.0
HTTP code   : 200
Server reply: OK
...
```

## Submission

After running and seeing successful HTTPS responses, visit:

```
https://iot.learnina.org/station_data.php?stationid=230401010231
```

Screenshot that page (showing recorded data) and include it in the Word file.

## Curl fallback (if no hardware)

If hardware is unavailable, simulate sending data with curl:

```bash
curl -k "https://iot.learnina.org/dht.php?stationid=230401010231&temperature=24.3&humidity=55.6"
```

Then visit the station_data.php URL as above.
