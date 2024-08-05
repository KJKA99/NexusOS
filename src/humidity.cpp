#include "humidity.h"
#include "i2c_manager.h"
#include <Wire.h>
#include <Adafruit_SHT31.h>
#include "logging.h"

Adafruit_SHT31 sht31 = Adafruit_SHT31();
bool sht31Initialized = false;

bool initializeHumiditySensor() {
    if (!isI2CDeviceConnected(0x44)) {
        logMessage(LOG_LEVEL_WARN, "SHT31 sensor not connected.");
        sht31Initialized = false;
        return false;
    }
    if (!sht31.begin(0x44)) {
        logMessage(LOG_LEVEL_ERROR, "Couldn't find SHT31 sensor!");
        sht31Initialized = false;
        return false;
    }
    sht31Initialized = true;
    logMessage(LOG_LEVEL_INFO, "SHT31 sensor initialized.");
    return true;
}

float readHumidity() {
    if (!sht31Initialized || !isI2CDeviceConnected(0x44)) {  // Check initialization and connection
        logMessage(LOG_LEVEL_WARN, "SHT31 sensor not connected.");
        return NAN;
    }
    float humidity = sht31.readHumidity();
    logSensorData("Humidity", humidity);
    return humidity;
}
