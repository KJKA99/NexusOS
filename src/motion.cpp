#include "motion.h"
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include "logging.h"

Adafruit_MPU6050 mpu;

bool initializeMotionSensor() {
    if (!mpu.begin()) {
        logMessage(LOG_LEVEL_ERROR, "Couldn't find MPU6050 sensor!");
        return false;
    }
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

    logMessage(LOG_LEVEL_INFO, "MPU6050 sensor initialized.");
    return true;
}

float readMotion() {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    float motion = a.acceleration.x;
    logSensorData("Motion", motion);
    return motion;
}
