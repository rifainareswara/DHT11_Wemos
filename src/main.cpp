/*
 * Mid-Term Project IoT (2026), UNSIA
 * Task 7: Secure HTTPS Data Transmission using Wemos D1 Mini (ESP8266)
 *
 * Reads DHT11 sensor and sends temperature + humidity via HTTPS GET
 * to iot.learnina.org/dht.php using BearSSL with SHA-1 fingerprint pinning.
 *
 * NOTE: Per task requirement, this does NOT use client.setInsecure().
 *       Instead, the server certificate is validated against the SHA-1
 *       fingerprint of iot.learnina.org using client->setFingerprint().
 *
 * Wiring:
 *   DHT11 VCC  -> 3V3
 *   DHT11 GND  -> GND
 *   DHT11 DATA -> GPIO 0  (pin labelled "0" on Wemos D1 Mini V4,
 *                          or "D3" on older Wemos D1 Mini boards)
 */

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>
#include <DHT.h>

#define DHTPIN 0
#define DHTTYPE DHT11

#ifndef STASSID
#define STASSID "ZFOLD 6 Rifai"
#define STAPSK "RNRif@i1212"
#endif

#define STUDENTID "230401010231" // Rifai's NIM

const char *ssid = STASSID;
const char *password = STAPSK;
const char *server = "https://iot.learnina.org/dht.php";
const char *stationid = STUDENTID;

// SHA-1 fingerprint of iot.learnina.org server certificate
const uint8_t fingerprint[] = {
    0xF6, 0x4E, 0x19, 0x85, 0xE1, 0xFE, 0x27, 0x65,
    0x42, 0xD8, 0x16, 0x11, 0x25, 0x47, 0xFF, 0xDD,
    0x10, 0xF0, 0xFC, 0x46};

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);
  delay(100);
  Serial.println();
  Serial.println(F("Task 7: Secure HTTPS DHT11 transmission"));
  Serial.print(F("Connecting to WiFi: "));
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print(F("WiFi connected. IP: "));
  Serial.println(WiFi.localIP());

  dht.begin();
}

void loop()
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    delay(2000);
    return;
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    // Secure client with SHA-1 fingerprint pinning (not setInsecure!)
    std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);
    client->setFingerprint(fingerprint);

    HTTPClient https;

    String url = String(server) + "?stationid=" + stationid + "&temperature=" + String(temperature, 1) + "&humidity=" + String(humidity, 1);

    Serial.print(F("Requesting URL: "));
    Serial.println(url);

    if (https.begin(*client, url))
    {
      int httpCode = https.GET();
      if (httpCode > 0)
      {
        String payload = https.getString();
        Serial.print(F("HTTP code   : "));
        Serial.println(httpCode);
        Serial.print(F("Server reply: "));
        Serial.println(payload);
      }
      else
      {
        Serial.print(F("HTTPS GET failed: "));
        Serial.println(https.errorToString(httpCode));
      }
      https.end();
    }
    else
    {
      Serial.println(F("[HTTPS] begin() failed -- fingerprint mismatch?"));
    }
  }

  delay(10000); // wait 10 seconds before next reading
}
