#include "diagnostics.h"
#include "humidity.h"
#include "proximity.h"
#include "light.h"
#include "temperature.h"
//#include "audio.h"
#include "motion.h"
#include "pressure.h"
#include "logging.h"

void runDiagnostics() {
    logMessage(LOG_LEVEL_INFO, "Running diagnostics...");

    bool humidityStatus = initializeHumiditySensor();
    logMessage(humidityStatus ? LOG_LEVEL_INFO : LOG_LEVEL_ERROR, ("Humidity sensor diagnostic " + String(humidityStatus ? "passed" : "failed")).c_str());

    bool proximityStatus = initializeProximitySensor();
    logMessage(proximityStatus ? LOG_LEVEL_INFO : LOG_LEVEL_ERROR, ("Proximity sensor diagnostic " + String(proximityStatus ? "passed" : "failed")).c_str());

    bool lightStatus = initializeLightSensor();
    logMessage(lightStatus ? LOG_LEVEL_INFO : LOG_LEVEL_ERROR, ("Light sensor diagnostic " + String(lightStatus ? "passed" : "failed")).c_str());

    bool temperatureStatus = initializeTemperatureSensor();
    logMessage(temperatureStatus ? LOG_LEVEL_INFO : LOG_LEVEL_ERROR, ("Temperature sensor diagnostic " + String(temperatureStatus ? "passed" : "failed")).c_str());

   /* bool audioStatus = initializeAudioSensor();
    logMessage(audioStatus ? LOG_LEVEL_INFO : LOG_LEVEL_ERROR, ("Audio sensor diagnostic " + String(audioStatus ? "passed" : "failed")).c_str());*/

    bool motionStatus = initializeMotionSensor();
    logMessage(motionStatus ? LOG_LEVEL_INFO : LOG_LEVEL_ERROR, ("Motion sensor diagnostic " + String(motionStatus ? "passed" : "failed")).c_str());

    bool pressureStatus = initializePressureSensor();
    logMessage(pressureStatus ? LOG_LEVEL_INFO : LOG_LEVEL_ERROR, ("Pressure sensor diagnostic " + String(pressureStatus ? "passed" : "failed")).c_str());

    logMessage(LOG_LEVEL_INFO, "Diagnostics completed.");
}
