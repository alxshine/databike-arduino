#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include <Wire.h>
#include "OutputManager.h"
#include "SensorValues.h"

class SensorManager
{
private:
    int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
    OutputManager &outputManager;

public:
    static const int MPU = 0x68;

    SensorManager(OutputManager &OutputManager);
    ~SensorManager();
    void init();
    void updateSensorValues();
    SensorValues getSensorValues();
};

#endif