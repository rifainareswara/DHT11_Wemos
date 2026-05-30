# Visual — Task 7 (DHT11 + Wemos D1 Mini)

Kumpulan visual yang menggambarkan seluruh project Task 7.

## Isi

| File | Isi |
|------|-----|
| [visual.html](visual.html) | Halaman utama — buka di browser. Berisi 4 visual: diagram wiring (SVG), alur data/arsitektur HTTPS, dashboard suhu & kelembapan (mode demo), dan tabel koneksi. |
| [wokwi/diagram.json](wokwi/diagram.json) | File rangkaian untuk simulasi di [wokwi.com](https://wokwi.com) tanpa hardware. |

## Cara buka dashboard

```bash
open docs/visual.html        # macOS
# atau klik dua kali file-nya
```

## Cara simulasi di Wokwi

1. Buka <https://wokwi.com/projects/new/wokwi-esp8266>
2. Tab `diagram.json` → paste isi [wokwi/diagram.json](wokwi/diagram.json)
3. Tab `sketch.ino` → paste isi `src/main.cpp` (Wokwi pakai Arduino IDE; ganti WiFi ke `Wokwi-GUEST`)
4. Klik ▶ Start

> Catatan: Wokwi belum punya part DHT11 native, jadi dipakai `wokwi-dht22`
> yang pin-nya identik (VCC / GND / DATA). DATA tetap ke **D3 (GPIO0)** sesuai
> `#define DHTPIN 0` di [src/main.cpp](../src/main.cpp).

## Ringkasan wiring

```
DHT11 VCC  ──(merah)──►  Wemos 3V3
DHT11 GND  ──(hitam)──►  Wemos GND
DHT11 DATA ──(kuning)─►  Wemos D3 (GPIO0)
```
