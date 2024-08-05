#include "temperature.h"
#include "i2c_manager.h"
#include <Wire.h>
#include "logging.h"

// Create an instance of the TMP102 sensor
TMP102 tempSensor;
bool tempInitialized = false;

bool initializeTemperatureSensor() {
    if (!isI2CDeviceConnected(0x48)) {
        logMessage(LOG_LEVEL_WARN, "TMP102 temperature sensor not connected.");
        tempInitialized = false;
        return false;
    }
    Wire.begin();
    if (!tempSensor.begin()) {
        logMessage(LOG_LEVEL_ERROR, "Failed to initialize TMP102 temperature sensor!");
        tempInitialized = false;
        return false;
    }
    tempInitialized = true;
    logMessage(LOG_LEVEL_INFO, "TMP102 temperature sensor initialized.");
    return true;
}

float readTemperature() {
    if (!tempInitialized || !isI2CDeviceConnected(0x48)) {  // Check initialization and connection
        logMessage(LOG_LEVEL_WARN, "TMP102 temperature sensor not connected.");
        return NAN;
    }
    float temperature = tempSensor.readTempC();
    logSensorData("Temperature", temperature);
    return temperature;
}
