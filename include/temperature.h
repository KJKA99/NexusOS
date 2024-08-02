#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <Wire.h>
#include <SparkFunTMP102.h>

extern TMP102 tempSensor;

bool initializeTemperatureSensor();
float readTemperature();

#endif
