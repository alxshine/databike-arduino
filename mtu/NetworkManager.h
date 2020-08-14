#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <string>

#include "WiFi.h"
#include "OutputManager.h"
#include "SensorValues.h"

class NetworkManager
{
public:
    NetworkManager(OutputManager &outputManager);
    ~NetworkManager();

    void init();
    void sendHello();
    void sendSensorValues(SensorValues values);
private:
    const std::string ssid = "databike";
    const std::string password = "databike1337";

    wl_status_t status = WL_IDLE_STATUS;
    OutputManager &outputManager;
    WiFiUDP udp;
    IPAddress broadCastIp;
};
#endif