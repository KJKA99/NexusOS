#include "spi_manager.h"
#include <SPI.h>
#include "logging.h"
#include "gpio_expander.h"

void initializeSPI() {
    SPI.begin();
}

bool isSPIDeviceConnected(uint8_t csPin) {
    // Attempt to communicate with the SPI device
    writeGPIOpin(csPin, LOW);  // Use GPIO expander to manage CS line
    delay(1);  // Short delay to let device settle
    uint8_t result = spiRead(csPin, 0x00);
    writeGPIOpin(csPin, HIGH);  // Use GPIO expander to manage CS line

    // Check if the result is valid (e.g., not -1) and meaningful
    bool deviceConnected = (result != 0xFF && result != 0x00);
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
    int result = -1; // Default to -1 to indicate failure
    for (int attempt = 0; attempt < 3; ++attempt) {
        writeGPIOpin(csPin, LOW);  // Use GPIO expander to manage CS line
        SPI.transfer(reg);
        result = SPI.transfer(0x00); // Capture result
        writeGPIOpin(csPin, HIGH);  // Use GPIO expander to manage CS line

        // Only return the result if it's not default, skip logging if successful
        if (result != -1 && result != 0xFF && result != 0x00) {
            return result;
        }
    }
    // Log only if all attempts failed to read meaningful data
    logMessage(LOG_LEVEL_ERROR, ("Failed to read data from SPI at CS pin: " + String(csPin)).c_str());
    return result;
}
