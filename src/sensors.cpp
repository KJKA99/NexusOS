#include "sensors.h"
#include "humidity.h"
#include "proximity.h"
#include "light.h"
#include "temperature.h"
//#include "audio.h"
#include "motion.h"
#include "pressure.h"
#include "logging.h"

void initializeSensors() {
    bool success = true;

    success &= initializeHumiditySensor();
    success &= initializeProximitySensor();
    success &= initializeLightSensor();
    success &= initializeTemperatureSensor();
   // success &= initializeAudioSensor();
    success &= initializeMotionSensor();
    success &= initializePressureSensor();

    if (success) {
        logMessage(LOG_LEVEL_INFO, "All sensors initialized successfully.");
    } else {
        logMessage(LOG_LEVEL_ERROR, "Some sensors failed to initialize.");
    }
}
