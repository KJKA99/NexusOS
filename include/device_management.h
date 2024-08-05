#ifndef DEVICE_MANAGEMENT_H
#define DEVICE_MANAGEMENT_H

#include <vector>
#include <string>

struct Device {
    std::string busType; // "I2C" or "SPI"
    int addressOrCS;
    std::string name;
};

extern std::vector<Device> NexusConnectedDevices;

void initializeDeviceManagement();
void verifyDevices();
void addI2CDevice(int address, const std::string& name);
void addSPIDevice(int csPin, const std::string& name);
void removeDevice(const std::string& busType, int addressOrCS);
void logConnectedDevices();

#endif // DEVICE_MANAGEMENT_H
