#include "i2c_manager.h"
#include <Wire.h>
#include "logging.h"

void initializeI2C() {
    Wire.begin();
}

bool isI2CDeviceConnected(uint8_t address) {
    Wire.beginTransmission(address);
    return Wire.endTransmission() == 0;
}

void writeToI2C(uint8_t address, const uint8_t* data, size_t length) {
    for (int attempt = 0; attempt < 3; ++attempt) {
        Wire.beginTransmission(address);
        Wire.write(data, length);
        if (Wire.endTransmission() == 0) {
            logMessage(LOG_LEVEL_DEBUG, ("Data written to I2C address: " + String(address)).c_str());
            return;
        }
    }
    logMessage(LOG_LEVEL_ERROR, ("Failed to write data to I2C address: " + String(address)).c_str());
}

void readFromI2C(uint8_t address, uint8_t* data, size_t length) {
    for (int attempt = 0; attempt < 3; ++attempt) {
        Wire.requestFrom(address, length);
        if (Wire.available() == length) {
            for (size_t i = 0; i < length; ++i) {
                data[i] = Wire.read();
            }
            logMessage(LOG_LEVEL_DEBUG, ("Data read from I2C address: " + String(address)).c_str());
            return;
        }
    }
    logMessage(LOG_LEVEL_ERROR, ("Failed to read data from I2C address: " + String(address)).c_str());
}
