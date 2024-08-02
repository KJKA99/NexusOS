/*#include "i2s_queue.h"
#include "i2s.h"
#include "logging.h"
#include "i2c_manager.h"

std::queue<I2SDevice> i2sQueue;

void addToQueue(uint8_t bus, uint8_t channel) {
    I2SDevice device = {bus, channel};
    i2sQueue.push(device);
    logMessage(LOG_LEVEL_DEBUG, "Added to I2S queue: bus " + String(bus) + ", channel " + String(channel));
}

void processQueue() {
    if (!i2sQueue.empty()) {
        I2SDevice device = i2sQueue.front();
        selectI2SDevice(device.bus, device.channel);
        i2sQueue.pop();
        logMessage(LOG_LEVEL_INFO, "Processing I2S queue: bus " + String(device.bus) + ", channel " + String(device.channel));
    }
}
*/