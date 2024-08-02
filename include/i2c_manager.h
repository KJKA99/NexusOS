#ifndef I2C_MANAGER_H
#define I2C_MANAGER_H

#include <Arduino.h>  // Ensure Arduino library is included for uint8_t and size_t types

void initializeI2C();
void writeToI2C(uint8_t address, const uint8_t* data, size_t length);
void readFromI2C(uint8_t address, uint8_t* data, size_t length);

#endif
