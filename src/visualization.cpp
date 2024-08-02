#include "visualization.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";
const char* serverName = "https://yourserver.com/api/data";

WiFiClientSecure secureClient;

void connectToWiFi() {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}

void processAndSendData(float humidity, float proximity, float light, float temperature, float audio, float motion, float pressure) {
    if (WiFi.status() != WL_CONNECTED) {
        connectToWiFi();
    }

    HTTPClient http;
    http.begin(secureClient, serverName); // Use secure client
    http.addHeader("Content-Type", "application/json");

    String jsonData = "{";
    if (humidity != -1) jsonData += "\"humidity\":" + String(humidity) + ",";
    if (proximity != -1) jsonData += "\"proximity\":" + String(proximity) + ",";
    if (light != -1) jsonData += "\"light\":" + String(light) + ",";
    if (temperature != -1) jsonData += "\"temperature\":" + String(temperature) + ",";
    if (audio != -1) jsonData += "\"audio\":" + String(audio) + ",";
    if (motion != -1) jsonData += "\"motion\":" + String(motion) + ",";
    if (pressure != -1) jsonData += "\"pressure\":" + String(pressure);
    jsonData += "}";

    int httpResponseCode = http.POST(jsonData);

    if (httpResponseCode > 0) {
        String response = http.getString();
        Serial.println(httpResponseCode);
        Serial.println(response);
    } else {
        Serial.print("Error on sending POST: ");
        Serial.println(httpResponseCode);
    }

    http.end();
}
