#include "humidity.h"
#include <Wire.h>
#include <Adafruit_SHT31.h>
#include "logging.h"

Adafruit_SHT31 sht31 = Adafruit_SHT31();

bool initializeHumiditySensor() {
    if (!sht31.begin(0x44)) {
        logMessage(LOG_LEVEL_ERROR, "Couldn't find SHT31 sensor!");
        return false;
    }
    logMessage(LOG_LEVEL_INFO, "SHT31 sensor initialized.");
    return true;
}

float readHumidity() {
    float humidity = sht31.readHumidity();
    logSensorData("Humidity", humidity);
    return humidity;
}
