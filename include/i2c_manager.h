#ifndef I2C_MANAGER_H
#define I2C_MANAGER_H

#include <Arduino.h>

void initializeI2C();
bool isI2CDeviceConnected(uint8_t address);
void writeToI2C(uint8_t address, const uint8_t* data, size_t length);
void readFromI2C(uint8_t address, uint8_t* data, size_t length);

#endif // I2C_MANAGER_H
