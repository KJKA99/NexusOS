/*#include "interrupts.h"
#include <Arduino.h>

// Define interrupt pins for each sensor
#define HUMIDITY_INT_PIN 4
#define PROXIMITY_INT_PIN 5
#define LIGHT_INT_PIN 6
#define TEMPERATURE_INT_PIN 7
//#define AUDIO_INT_PIN 8
#define MOTION_INT_PIN 9
#define PRESSURE_INT_PIN 10

extern volatile bool humidityFlag;
extern volatile bool proximityFlag;
extern volatile bool lightFlag;
extern volatile bool temperatureFlag;
//extern volatile bool audioFlag;
extern volatile bool motionFlag;
extern volatile bool pressureFlag;

void IRAM_ATTR humidityISR() {
    humidityFlag = true;
}

void IRAM_ATTR proximityISR() {
    proximityFlag = true;
}

void IRAM_ATTR lightISR() {
    lightFlag = true;
}

void IRAM_ATTR temperatureISR() {
    temperatureFlag = true;
}

/*void IRAM_ATTR audioISR() {
    audioFlag = true;
}

void IRAM_ATTR motionISR() {
    motionFlag = true;
}

void IRAM_ATTR pressureISR() {
    pressureFlag = true;
}

void initializeInterrupts() {
    attachInterrupt(digitalPinToInterrupt(HUMIDITY_INT_PIN), humidityISR, FALLING | ESP_INTR_FLAG_LEVEL1);
    attachInterrupt(digitalPinToInterrupt(PROXIMITY_INT_PIN), proximityISR, FALLING | ESP_INTR_FLAG_LEVEL2);
    attachInterrupt(digitalPinToInterrupt(LIGHT_INT_PIN), lightISR, FALLING | ESP_INTR_FLAG_LEVEL2);
    attachInterrupt(digitalPinToInterrupt(TEMPERATURE_INT_PIN), temperatureISR, FALLING | ESP_INTR_FLAG_LEVEL1);
   // attachInterrupt(digitalPinToInterrupt(AUDIO_INT_PIN), audioISR, FALLING | ESP_INTR_FLAG_LEVEL2);
    attachInterrupt(digitalPinToInterrupt(MOTION_INT_PIN), motionISR, FALLING | ESP_INTR_FLAG_LEVEL3);
    attachInterrupt(digitalPinToInterrupt(PRESSURE_INT_PIN), pressureISR, FALLING | ESP_INTR_FLAG_LEVEL3);
}

void handleInterrupts() {
    // Handle each flag here
    if (humidityFlag) {
        // Process humidity
        humidityFlag = false;  // Reset flag after processing
    }
    if (proximityFlag) {
        // Process proximity
        proximityFlag = false;  // Reset flag after processing
    }
    if (lightFlag) {
        // Process light
        lightFlag = false;  // Reset flag after processing
    }
    if (temperatureFlag) {
        // Process temperature
        temperatureFlag = false;  // Reset flag after processing
    }
    if (audioFlag) {
        // Process audio
        audioFlag = false;  // Reset flag after processing
    }
    if (motionFlag) {
        // Process motion
        motionFlag = false;  // Reset flag after processing
    }
    if (pressureFlag) {
        // Process pressure
        pressureFlag = false;  // Reset flag after processing
    }
}*/
