#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <string>

#include "WiFi.h"
#include <TFT_eSPI.h>

class NetworkManager
{
public:
    NetworkManager(TFT_eSPI &tft);
    ~NetworkManager();

private:
    const std::string ssid = "databike";
    const std::string password = "databike1337";

    wl_status_t status = WL_IDLE_STATUS;
    TFT_eSPI &tft;
};
#endif