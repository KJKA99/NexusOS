#include "light.h"
#include "i2c_manager.h"
#include <Wire.h>
#include <Adafruit_TSL2591.h>
#include "logging.h"

Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591);
bool tslInitialized = false;

bool initializeLightSensor() {
    if (!isI2CDeviceConnected(0x29)) {
        logMessage(LOG_LEVEL_WARN, "TSL2591 sensor not connected.");
        tslInitialized = false;
        return false;
    }
    if (!tsl.begin()) {
        logMessage(LOG_LEVEL_ERROR, "Couldn't find TSL2591 sensor!");
        tslInitialized = false;
        return false;
    }
    tsl.setGain(TSL2591_GAIN_MED);
    tsl.setTiming(TSL2591_INTEGRATIONTIME_100MS);
    tslInitialized = true;
    logMessage(LOG_LEVEL_INFO, "TSL2591 sensor initialized.");
    return true;
}

float readLight() {
    if (!tslInitialized || !isI2CDeviceConnected(0x29)) {  // Check initialization and connection
        logMessage(LOG_LEVEL_WARN, "TSL2591 sensor not connected.");
        return 0.0;
    }
    uint16_t light = tsl.getFullLuminosity();
    logSensorData("Light", light);
    return light;
}
