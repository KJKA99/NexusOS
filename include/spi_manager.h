#ifndef SPI_MANAGER_H
#define SPI_MANAGER_H

#include <Arduino.h>

void initializeSPI();
void spiWrite(uint8_t csPin, uint8_t reg, uint8_t data);
int spiRead(uint8_t csPin, uint8_t reg);

#endif
