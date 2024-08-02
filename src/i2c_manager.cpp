#include "i2c_manager.h"
#include <Wire.h>
#include "logging.h"

void initializeI2C() {
    Wire.begin();
}

void writeToI2C(uint8_t address, const uint8_t* data, size_t length) {
    Wire.beginTransmission(address);
    Wire.write(data, length);
    Wire.endTransmission();
    logMessage(LOG_LEVEL_DEBUG, ("Data written to I2C address: " + String(address)).c_str());
}

void readFromI2C(uint8_t address, uint8_t* data, size_t length) {
    Wire.requestFrom(address, length);
    for (size_t i = 0; i < length && Wire.available(); ++i) {
        data[i] = Wire.read();
    }
    logMessage(LOG_LEVEL_DEBUG, ("Data read from I2C address: " + String(address)).c_str());
}
