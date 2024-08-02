#include "device_management.h"
#include "humidity.h"
#include "proximity.h"
#include "light.h"
#include "temperature.h"
//#include "audio.h"
#include "motion.h"
#include "pressure.h"
#include "logging.h"
#include "visualization.h"

void initializeDeviceManagement() {
    // Initial device management setup if needed
    logMessage(LOG_LEVEL_INFO, "Device management initialized.");
}

void verifyDevices() {
    // Verify each device to ensure it is active
    logMessage(LOG_LEVEL_DEBUG, "Verifying devices...");

    // Example verification for each sensor:
    if (!initializeHumiditySensor()) {
        logMessage(LOG_LEVEL_WARN, "Humidity sensor verification failed!");
    }
    if (!initializeProximitySensor()) {
        logMessage(LOG_LEVEL_WARN, "Proximity sensor verification failed!");
    }
    if (!initializeLightSensor()) {
        logMessage(LOG_LEVEL_WARN, "Light sensor verification failed!");
    }
    if (!initializeTemperatureSensor()) {
        logMessage(LOG_LEVEL_WARN, "Temperature sensor verification failed!");
    }
    /* if (!initializeAudioSensor()) {
        logMessage(LOG_LEVEL_WARN, "Audio sensor verification failed!");
    }*/
    if (!initializeMotionSensor()) {
        logMessage(LOG_LEVEL_WARN, "Motion sensor verification failed!");
    }
    if (!initializePressureSensor()) {
        logMessage(LOG_LEVEL_WARN, "Pressure sensor verification failed!");
    }

    logMessage(LOG_LEVEL_INFO, "Device verification completed.");
}

void collectSensorData() {
    // Collect data from all sensors and send it
    logMessage(LOG_LEVEL_DEBUG, "Collecting sensor data...");

    float humidity = readHumidity();
    float proximity = readProximity();
    float light = readLight();
    float temperature = readTemperature();
    // float audio = readAudio();
    float motion = readMotion();
    float pressure = readPressure();

    // Use 0.0 or NaN to indicate missing audio data
    float audioPlaceholder = 0.0;  // or NAN for Not-a-Number, if you prefer

    processAndSendData(humidity, proximity, light, temperature, motion, audioPlaceholder, pressure);

    logMessage(LOG_LEVEL_INFO, "Sensor data collection completed.");
}
