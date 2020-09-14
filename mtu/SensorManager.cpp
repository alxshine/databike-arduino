#include "SensorManager.h"

#include <Wire.h>

SensorManager::SensorManager(OutputManager &outputManager) : outputManager(outputManager)
{
}

SensorManager::~SensorManager()
{
}

void SensorManager::init()
{
    outputManager.println("Initializing I2C");

    Wire.begin(26, 27);
    Wire.beginTransmission(SensorManager::MPU);
    Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission(true);

    outputManager.println("I2C initialized");
}

void SensorManager::updateSensorValues()
{
    Wire.beginTransmission(MPU);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 12, (int)true);
    AcX = Wire.read() << 8 | Wire.read();
    AcY = Wire.read() << 8 | Wire.read();
    AcZ = Wire.read() << 8 | Wire.read();
    GyX = Wire.read() << 8 | Wire.read();
    GyY = Wire.read() << 8 | Wire.read();
    GyZ = Wire.read() << 8 | Wire.read();
}

SensorValues SensorManager::getSensorValues()
{
    return {millis(), AcX, AcY, AcZ, GyX, GyY, GyZ};
}