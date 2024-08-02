#include "temperature.h"
#include "logging.h"

// Create an instance of the TMP102 sensor
TMP102 tempSensor;

bool initializeTemperatureSensor() {
    Wire.begin();
    if (!tempSensor.begin()) {
        logMessage(LOG_LEVEL_ERROR, "Failed to initialize TMP102 temperature sensor!");
        return false;
    }
    logMessage(LOG_LEVEL_INFO, "TMP102 temperature sensor initialized.");
    return true;
}

float readTemperature() {
    float temperature = tempSensor.readTempC();
    logSensorData("Temperature", temperature);
    return temperature;
}
