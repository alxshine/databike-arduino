#ifndef SENSORVALUES_H
#define SENSORVALUES_H

#include <cstdlib>
#include <string>

struct SensorValues
{
    int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;

    std::string to_string();
};

#endif