#include <SPI.h>
#include <spi_manager.h>
#include <Arduino.h>

void initializeSPI() {
    SPI.begin();
}

void spiWrite(uint8_t csPin, uint8_t reg, uint8_t data) {
    digitalWrite(csPin, LOW);
    SPI.transfer(reg);
    SPI.transfer(data);
    digitalWrite(csPin, HIGH);
}

int spiRead(uint8_t csPin, uint8_t reg) {
    digitalWrite(csPin, LOW);
    SPI.transfer(reg);
    uint8_t result = SPI.transfer(0x00);
    digitalWrite(csPin, HIGH);
    return result;
}