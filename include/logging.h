#ifndef LOGGING_H
#define LOGGING_H

#include <Arduino.h>

enum LogLevel {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR
};

void logMessage(LogLevel level, const char* message); // Use const char*
void logSensorData(const char* sensorName, float value); // Use const char*

#endif
