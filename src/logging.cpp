#include "logging.h"
#include <Arduino.h>

void logMessage(LogLevel level, const char* message) {
    const char* levelString;

    switch (level) {
        case LOG_LEVEL_DEBUG:
            levelString = "DEBUG";
            break;
        case LOG_LEVEL_INFO:
            levelString = "INFO";
            break;
        case LOG_LEVEL_WARN:
            levelString = "WARN";
            break;
        case LOG_LEVEL_ERROR:
            levelString = "ERROR";
            break;
        default:
            levelString = "UNKNOWN";
            break;
    }

    Serial.print("[");
    Serial.print(levelString);
    Serial.print("] ");
    Serial.println(message);
}

void logSensorData(const char* sensor, float value) {
    Serial.print("[INFO] ");
    Serial.print(sensor);
    Serial.print(" sensor reading: ");
    Serial.println(value);
}
