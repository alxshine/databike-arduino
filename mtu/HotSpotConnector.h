#ifndef HOTSPOTCONNECTOR_H
#define HOTSPOTCONNECTOR_H

#include <string>

#include "WiFi.h"
#include <TFT_eSPI.h>

class HotspotConnector
{
public:
    HotspotConnector(TFT_eSPI &tft);
    ~HotspotConnector();

private:
    const std::string ssid = "databike";
    const std::string password = "databike1337";

    wl_status_t status = WL_IDLE_STATUS;
    TFT_eSPI &tft;
};
#endif