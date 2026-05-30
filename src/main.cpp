/*
 * Mid-Term Project IoT (2026), UNSIA
 * Task 6: DHT11 Sensor Reading on Wemos D1 Mini using PlatformIO
 *
 * Wiring:
 *   DHT11 VCC  -> 3.3V
 *   DHT11 GND  -> GND
 *   DHT11 DATA -> GPIO 0 (D3 on Wemos D1 Mini board)
 *
 * Behavior:
 *   - Reads temperature and humidity every 5 seconds
 *   - Prints readings to the Serial Monitor at 115200 baud
 */

#include <Arduino.h>
#include <DHT.h>

#define DHTPIN  0       // GPIO 0 (labeled D3 on the Wemos D1 Mini)
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println();
  Serial.println(F("DHT11 Sensor Reader -- Task 6 (PlatformIO + Wemos D1 Mini)"));
  Serial.println(F("Reading every 5 seconds..."));
  Serial.println();

  dht.begin();
}

void loop() {
  // Wait 5 seconds between readings (per task requirement)
  delay(5000);

  float humidity    = dht.readHumidity();
  float temperature = dht.readTemperature();   // Celsius by default

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(humidity, 1);
  Serial.print(F(" %    Temperature: "));
  Serial.print(temperature, 1);
  Serial.println(F(" C"));
}
