#include "light.h"
#include <Wire.h>
#include <Adafruit_TSL2591.h>
#include "logging.h"

Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591);

bool initializeLightSensor() {
    if (!tsl.begin()) {
        logMessage(LOG_LEVEL_ERROR, "Couldn't find TSL2591 sensor!");
        return false;
    }
    tsl.setGain(TSL2591_GAIN_MED);
    tsl.setTiming(TSL2591_INTEGRATIONTIME_100MS);
    logMessage(LOG_LEVEL_INFO, "TSL2591 sensor initialized.");
    return true;
}

float readLight() {
    uint16_t light = tsl.getFullLuminosity();
    logSensorData("Light", light);
    return light;
}