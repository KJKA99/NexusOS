#include "device_management.h"
#include "i2c_manager.h"
#include "spi_manager.h"
#include "logging.h"

std::vector<Device> NexusConnectedDevices;

void initializeDeviceManagement() {
    // Initial device management setup if needed
    logMessage(LOG_LEVEL_INFO, "Device management initialized.");
}

void verifyDevices() {
    logMessage(LOG_LEVEL_DEBUG, "Verifying devices...");

    // Scan I2C bus
    for (int address = 1; address <= 126; ++address) {
        if (isI2CDeviceConnected(address)) {
            // Check if device is already in the vector
            bool exists = false;
            for (const auto& device : NexusConnectedDevices) {
                if (device.busType == "I2C" && device.addressOrCS == address) {
                    exists = true;
                    break;
                }
            }
            if (!exists && NexusConnectedDevices.size() < 6) {
                addI2CDevice(address, "Unknown I2C Device");
            }
        } else {
            removeDevice("I2C", address);
        }
    }

    // Scan SPI bus
    for (int csPin = 1; csPin <= 6; ++csPin) {
        if (isSPIDeviceConnected(csPin)) {
            bool exists = false;
            for (const auto& device : NexusConnectedDevices) {
                if (device.busType == "SPI" && device.addressOrCS == csPin) {
                    exists = true;
                    break;
                }
            }
            if (!exists && NexusConnectedDevices.size() < 6) {
                addSPIDevice(csPin, "Unknown SPI Device");
            }
        } else {
            removeDevice("SPI", csPin);
        }
    }

    logConnectedDevices();
}

void addI2CDevice(int address, const std::string& name) {
    if (NexusConnectedDevices.size() < 6) {
        NexusConnectedDevices.push_back({"I2C", address, name});
        logMessage(LOG_LEVEL_INFO, ("Added I2C device at address " + std::to_string(address)).c_str());
    } else {
        logMessage(LOG_LEVEL_WARN, "Device list full, cannot add I2C device.");
    }
}

void addSPIDevice(int csPin, const std::string& name) {
    if (NexusConnectedDevices.size() < 6) {
        NexusConnectedDevices.push_back({"SPI", csPin, name});
        logMessage(LOG_LEVEL_INFO, ("Added SPI device at CS pin " + std::to_string(csPin)).c_str());
    } else {
        logMessage(LOG_LEVEL_WARN, "Device list full, cannot add SPI device.");
    }
}

void removeDevice(const std::string& busType, int addressOrCS) {
    for (auto it = NexusConnectedDevices.begin(); it != NexusConnectedDevices.end(); ++it) {
        if (it->busType == busType && it->addressOrCS == addressOrCS) {
            logMessage(LOG_LEVEL_INFO, ("Removed " + busType + " device at address/CS " + std::to_string(addressOrCS)).c_str());
            NexusConnectedDevices.erase(it);
            break;
        }
    }
}

void logConnectedDevices() {
    logMessage(LOG_LEVEL_INFO, "Currently connected devices:");
    for (const auto& device : NexusConnectedDevices) {
        logMessage(LOG_LEVEL_INFO, ("- " + device.busType + " device at address/CS " + std::to_string(device.addressOrCS)).c_str());
    }
}
