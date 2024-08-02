#include <Arduino.h>
#include "i2c_manager.h"
//#include "i2s_manager.h"
//#include "i2s_queue.h"
#include "spi_manager.h"
#include "humidity.h"
#include "proximity.h"
#include "light.h"
#include "temperature.h"
//#include "audio.h"
#include "motion.h"
#include "pressure.h"
#include "device_management.h"
#include "interrupts.h"
#include "visualization.h"
#include "logging.h"
#include "diagnostics.h"
#include "gpio_expander.h"
#include "multiplexer.h"
#include "sensors.h"
#include "protocols.h"

// Define interrupt pins for each sensor
#define HUMIDITY_INT_PIN 4
#define PROXIMITY_INT_PIN 5
#define LIGHT_INT_PIN 6
#define TEMPERATURE_INT_PIN 7
//#define AUDIO_INT_PIN 8
#define MOTION_INT_PIN 9
#define PRESSURE_INT_PIN 10

volatile bool humidityFlag = false;
volatile bool proximityFlag = false;
volatile bool lightFlag = false;
volatile bool temperatureFlag = false;
//volatile bool audioFlag = false;
volatile bool motionFlag = false;
volatile bool pressureFlag = false;

void setup() {
    Serial.begin(115200);
    initializeProtocols();  // Initialize communication protocols
    initializeSensors();  // Initialize all sensors
    initializeInterrupts();
    initializeDeviceManagement();
    initializeGPIOExpander();
    initializeMultiplexer();
    //initializeI2S();
    initializeSPI();

    pinMode(HUMIDITY_INT_PIN, INPUT_PULLUP);
    pinMode(PROXIMITY_INT_PIN, INPUT_PULLUP);
    pinMode(LIGHT_INT_PIN, INPUT_PULLUP);
    pinMode(TEMPERATURE_INT_PIN, INPUT_PULLUP);
    //pinMode(AUDIO_INT_PIN, INPUT_PULLUP);
    pinMode(MOTION_INT_PIN, INPUT_PULLUP);
    pinMode(PRESSURE_INT_PIN, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(HUMIDITY_INT_PIN), humidityISR, FALLING | ESP_INTR_FLAG_LEVEL1);
    attachInterrupt(digitalPinToInterrupt(PROXIMITY_INT_PIN), proximityISR, FALLING | ESP_INTR_FLAG_LEVEL2);
    attachInterrupt(digitalPinToInterrupt(LIGHT_INT_PIN), lightISR, FALLING | ESP_INTR_FLAG_LEVEL2);
    attachInterrupt(digitalPinToInterrupt(TEMPERATURE_INT_PIN), temperatureISR, FALLING | ESP_INTR_FLAG_LEVEL1);
    //attachInterrupt(digitalPinToInterrupt(AUDIO_INT_PIN), audioISR, FALLING | ESP_INTR_FLAG_LEVEL2);
    attachInterrupt(digitalPinToInterrupt(MOTION_INT_PIN), motionISR, FALLING | ESP_INTR_FLAG_LEVEL3);
    attachInterrupt(digitalPinToInterrupt(PRESSURE_INT_PIN), pressureISR, FALLING | ESP_INTR_FLAG_LEVEL3);

    logMessage(LOG_LEVEL_INFO, "Setup complete.");

    // Run diagnostics on setup
    runDiagnostics();
}

void loop() {
    if (humidityFlag) {
        humidityFlag = false;
        float humidity = readHumidity();
        processAndSendData(humidity, -1, -1, -1, -1, -1, -1);
    }
    if (proximityFlag) {
        proximityFlag = false;
        float proximity = readProximity();
        processAndSendData(-1, proximity, -1, -1, -1, -1, -1);
    }
    if (lightFlag) {
        lightFlag = false;
        float light = readLight();
        processAndSendData(-1, -1, light, -1, -1, -1, -1);
    }
    if (temperatureFlag) {
        temperatureFlag = false;
        float temperature = readTemperature();
        processAndSendData(-1, -1, -1, temperature, -1, -1, -1);
    }
    /*if (audioFlag) {
        NULL;
        audioFlag = false;
        addToQueue(0, 0); // Example: Adding to I2S queue, adjust as necessary
        processQueue(); // Process the queue to handle the I2S device
        I2SDeviceType deviceType = identifyI2SDevice(0, 0); // Identify the device type
        if (deviceType == I2S_DEVICE_MICROPHONE) {
            float audio = readI2SData();
            processAndSendData(-1, -1, -1, -1, audio, -1, -1);
        } else if (deviceType == I2S_DEVICE_AMPLIFIER) {
            // Implement reading from the amplifier if needed
            // Example: float amplifierData = readAmplifierData();
            // processAndSendData(-1, -1, -1, -1, -1, -1, amplifierData);
        } else {
            logMessage(LOG_LEVEL_WARN, "Unknown I2S device type.");
        }
    }*/
    if (motionFlag) {
        motionFlag = false;
        float motion = readMotion();
        processAndSendData(-1, -1, -1, -1, -1, motion, -1);
    }
    if (pressureFlag) {
        pressureFlag = false;
        float pressure = readPressure();
        processAndSendData(-1, -1, -1, -1, -1, -1, pressure);
    }

    handleInterrupts();
    collectSensorData();
    verifyDevices();
}
