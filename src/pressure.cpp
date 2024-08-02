#include "pressure.h"
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include "logging.h"

Adafruit_BMP280 bmp;

bool initializePressureSensor() {
    if (!bmp.begin(0x76)) {
        logMessage(LOG_LEVEL_ERROR, "Couldn't find BMP280 sensor!");
        return false;
    }
    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                    Adafruit_BMP280::SAMPLING_X2,
                    Adafruit_BMP280::SAMPLING_X16,
                    Adafruit_BMP280::FILTER_X16,
                    Adafruit_BMP280::STANDBY_MS_500);
    logMessage(LOG_LEVEL_INFO, "BMP280 sensor initialized.");
    return true;
}

float readPressure() {
    float pressure = bmp.readPressure();
    logSensorData("Pressure", pressure);
    return pressure;
}
