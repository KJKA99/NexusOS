#include <Arduino.h>
#include "i2c_manager.h"
#include "spi_manager.h"
#include "humidity.h"
#include "proximity.h"
#include "light.h"
#include "temperature.h"
#include "motion.h"
#include "pressure.h"
#include "device_management.h"
#include "visualization.h"
#include "logging.h"
#include "sensors.h"
#include "protocols.h"

// Uncomment these includes if you plan to use I2S in the future
// #include "i2s_manager.h"
// #include "i2s_queue.h"

// Define maximum number of devices to manage
#define MAX_DEVICES 6

void setup() {
    Serial.begin(115200);
    delay(2000);
    //scanWiFi();
    connectToWiFi();
    initializeProtocols();  // Initialize communication protocols
    initializeSensors();    // Initialize all sensors
    initializeDeviceManagement(); // Initialize device management
    

    logMessage(LOG_LEVEL_INFO, "Setup complete.");

    // Initial verification of devices
    verifyDevices();
}

void loop() {
    // Periodically verify connected devices
    static unsigned long lastDeviceCheck = 0;
    if (millis() - lastDeviceCheck > 5000) { // Check every 5 seconds
        verifyDevices();
        lastDeviceCheck = millis();
    }

    // Collect and send sensor data periodically
    static unsigned long lastDataSend = 0;
    if (millis() - lastDataSend > 10000) { // Send data every 10 seconds
        float humidity = readHumidity();
        float proximity = readProximity();
        float light = readLight();
        float temperature = readTemperature();
        float motion = readMotion();
        float pressure = readPressure();

        // Send data to the visualization tool
        processAndSendData(humidity, proximity, light, temperature, -1, motion, pressure);
        
        lastDataSend = millis();
    }
}

