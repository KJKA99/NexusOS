#include "proximity.h"
#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#include "logging.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

bool initializeProximitySensor() {
    if (!lox.begin()) {
        logMessage(LOG_LEVEL_ERROR, "Couldn't find VL53L0X sensor!");
        return false;
    }

    // Set the sensor for continuous ranging
    lox.startRangeContinuous(100);

    logMessage(LOG_LEVEL_INFO, "VL53L0X sensor initialized.");
    return true;
}

float readProximity() {
    VL53L0X_RangingMeasurementData_t measure;
    lox.rangingTest(&measure, false);

    if (measure.RangeStatus != 4) {  // if not out of range
        float proximity = measure.RangeMilliMeter;
        logSensorData("Proximity", proximity);
        return proximity;
    } else {
        logMessage(LOG_LEVEL_WARN, "Proximity measurement out of range!");
        return -1.0;  // indicate an error or out of range value
    }
}
