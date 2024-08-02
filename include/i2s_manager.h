/*#ifndef I2S_MANAGER_H
#define I2S_MANAGER_H

#include <driver/i2s.h>

enum class I2SBusConfig {
    MASTER_RX0,  // Configure Bus 0 as Master Receiver
    MASTER_TX0,  // Configure Bus 0 as Master Transmitter
    MASTER_RX1,  // Configure Bus 1 as Master Receiver
    MASTER_TX1   // Configure Bus 1 as Master Transmitter
};

enum I2SDeviceType {
    I2S_DEVICE_AMPLIFIER,
    I2S_DEVICE_MICROPHONE,
    I2S_DEVICE_UNKNOWN
};

void initializeI2S(I2SBusConfig config);
void selectI2SDevice(uint8_t bus, uint8_t channel);
float readI2SData();
I2SDeviceType identifyI2SDevice(uint8_t bus, uint8_t channel);

#endif*/
