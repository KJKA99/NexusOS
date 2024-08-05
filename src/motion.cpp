#include "motion.h"
#include "i2c_manager.h"
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include "logging.h"

Adafruit_MPU6050 mpu;
bool mpuInitialized = false;

bool initializeMotionSensor() {
    if (!isI2CDeviceConnected(0x68)) {
        logMessage(LOG_LEVEL_WARN, "MPU6050 sensor not connected.");
        mpuInitialized = false;
        return false;
    }
    if (!mpu.begin()) {
        logMessage(LOG_LEVEL_ERROR, "Couldn't find MPU6050 sensor!");
        mpuInitialized = false;
        return false;
    }
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    mpuInitialized = true;
    logMessage(LOG_LEVEL_INFO, "MPU6050 sensor initialized.");
    return true;
}

float readMotion() {
    if (!mpuInitialized || !isI2CDeviceConnected(0x68)) {  // Check initialization and connection
        logMessage(LOG_LEVEL_WARN, "MPU6050 sensor not connected.");
        return NAN;
    }
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    float motion = a.acceleration.x;
    logSensorData("Motion", motion);
    return motion;
}
