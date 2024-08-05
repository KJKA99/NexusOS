#include "spi_manager.h"
#include <SPI.h>
#include "logging.h"
#include "gpio_expander.h"

void initializeSPI() {
    SPI.begin();
}

bool isSPIDeviceConnected(uint8_t csPin) {
    // Attempt to communicate with the SPI device
    // Set the pin low, attempt to communicate, then set high
    writeGPIOpin(csPin, LOW);  // Use GPIO expander to manage CS line
    delay(1);  // Short delay to let device settle
    bool deviceConnected = (spiRead(csPin, 0x00) != -1);
    writeGPIOpin(csPin, HIGH);  // Use GPIO expander to manage CS line
    return deviceConnected;
}

void spiWrite(uint8_t csPin, uint8_t reg, uint8_t data) {
   for (int attempt = 0; attempt < 3; ++attempt) {
        writeGPIOpin(csPin, LOW);  // Use GPIO expander to manage CS line
        SPI.transfer(reg);
        SPI.transfer(data);
        writeGPIOpin(csPin, HIGH);  // Use GPIO expander to manage CS line
        logMessage(LOG_LEVEL_DEBUG, ("Data written to SPI at CS pin: " + String(csPin)).c_str());
        return;
    }
    logMessage(LOG_LEVEL_ERROR, ("Failed to write data to SPI at CS pin: " + String(csPin)).c_str());
}


int spiRead(uint8_t csPin, uint8_t reg) {
    for (int attempt = 0; attempt < 3; ++attempt) {
        writeGPIOpin(csPin, LOW);  // Use GPIO expander to manage CS line
        SPI.transfer(reg);
        uint8_t result = SPI.transfer(0x00);
        writeGPIOpin(csPin, HIGH);  // Use GPIO expander to manage CS line
        logMessage(LOG_LEVEL_DEBUG, ("Data read from SPI at CS pin: " + String(csPin)).c_str());
        return result;
    }
    logMessage(LOG_LEVEL_ERROR, ("Failed to read data from SPI at CS pin: " + String(csPin)).c_str());
    return -1;
}
