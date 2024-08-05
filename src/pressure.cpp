#include "pressure.h"
#include "i2c_manager.h"
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include "logging.h"

Adafruit_BMP280 bmp;
bool bmpInitialized = false;

bool initializePressureSensor() {
    if (!isI2CDeviceConnected(0x76)) {
        logMessage(LOG_LEVEL_WARN, "BMP280 sensor not connected.");
        bmpInitialized = false;
        return false;
    }
    if (!bmp.begin(0x76)) {
        logMessage(LOG_LEVEL_ERROR, "Couldn't find BMP280 sensor!");
        bmpInitialized = false;
        return false;
    }
    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                    Adafruit_BMP280::SAMPLING_X2,
                    Adafruit_BMP280::SAMPLING_X16,
                    Adafruit_BMP280::FILTER_X16,
                    Adafruit_BMP280::STANDBY_MS_500);
    bmpInitialized = true;
    logMessage(LOG_LEVEL_INFO, "BMP280 sensor initialized.");
    return true;
}

float readPressure() {
    if (!bmpInitialized || !isI2CDeviceConnected(0x76)) {  // Check initialization and connection
        logMessage(LOG_LEVEL_WARN, "BMP280 sensor not connected.");
        return NAN;
    }
    float pressure = bmp.readPressure();
    logSensorData("Pressure", pressure);
    return pressure;
}
