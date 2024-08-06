#include "visualization.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

String ssid;
String password;
const char* serverName = "https://yourserver.com/api/data";

WiFiClientSecure secureClient;

void connectToWiFi() {
    Serial.println("Enter SSID: ");
    while (Serial.available() == 0) {
        // Wait for user input
    }
    String ssid = Serial.readStringUntil('\n');
    ssid.trim(); // Remove any trailing newline characters

    Serial.println("Enter Password: ");
    while (Serial.available() == 0) {
        // Wait for user input
    }
    String password = Serial.readStringUntil('\n');
    password.trim(); // Remove any trailing newline characters

    Serial.println("Attempting to connect to WiFi...");
    WiFi.begin(ssid.c_str(), password.c_str());

    unsigned long startAttemptTime = millis();

    // Wait for connection with timeout
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
        delay(500);
        Serial.print(".");
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nConnected to WiFi");
    } else {
        Serial.println("\nFailed to connect to WiFi");
    }
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
