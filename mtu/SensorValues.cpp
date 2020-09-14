#include "SensorValues.h"

#include <sstream>

using namespace std;

string SensorValues::to_string()
{
    stringstream ret;
    ret << "{\"time\": " << millis << ", \"AcX\": " << AcX << ", \"AcY\": " << AcY << ", \"AcZ\": "
        << ", \"GyX\": " << GyX << ", \"GyY\": " << GyY << ", \"GyZ\": " << GyZ << "}";
    return ret.str();
}