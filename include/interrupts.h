/*#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <Arduino.h>

void IRAM_ATTR humidityISR();
void IRAM_ATTR proximityISR();
void IRAM_ATTR lightISR();
void IRAM_ATTR temperatureISR();
void IRAM_ATTR audioISR();
void IRAM_ATTR motionISR();
void IRAM_ATTR pressureISR();

void initializeInterrupts();
void handleInterrupts();

#endif*/
