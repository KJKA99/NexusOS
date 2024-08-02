/*#ifndef I2S_QUEUE_H
#define I2S_QUEUE_H

#include <queue>
#include <Arduino.h>
#include "i2s_manager.h"

struct I2SDevice {
    uint8_t bus;
    uint8_t channel;
};

extern std::queue<I2SDevice> i2sQueue;

void addToQueue(uint8_t bus, uint8_t channel);
void processQueue();

#endif*/
