/*#include "visualization.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

String ssid;
String password;
const char* serverName = "http://10.0.0.6:1880/sensor-data";

WiFiClientSecure secureClient;

void scanWiFi() {
    Serial.println("Scanning for available networks...");
    int n = WiFi.scanNetworks();
    Serial.println("Scan complete");

    if (n == 0) {
        Serial.println("No networks found");
    } else {
        Serial.println("Networks found:");
        for (int i = 0; i < n; ++i) {
            Serial.print(i + 1); // Print network number starting from 1
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.println(" dBm)");
            delay(10);
        }

        // Prompt user to select a network
        Serial.println("Enter the number of the network you wish to connect to:");
        while (Serial.available() == 0) {
            // Wait for user input
        }
        int selectedNetwork = Serial.parseInt();
        if (selectedNetwork > 0 && selectedNetwork <= n) {
            ssid = WiFi.SSID(selectedNetwork - 1);
            Serial.print("Selected network: ");
            Serial.println(ssid);

            // Prompt for password
            Serial.println("Enter Password: ");
            while (Serial.available() == 0) {
                // Wait for user input
            }
            password = Serial.readStringUntil('\n');
            password.trim(); // Remove any trailing newline characters
        } else {
            Serial.println("Invalid selection.");
        }
    }
}

void connectToWiFi() {
    if (ssid.length() == 0 || password.length() == 0) {
        Serial.println("SSID or password not set. Please scan and select a network first.");
        return;
    }

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
}*/