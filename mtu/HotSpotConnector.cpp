#include "HotSpotConnector.h"

#include <string>

#include "WiFi.h"
#include <TFT_eSPI.h>

using namespace std;

HotspotConnector::HotspotConnector(TFT_eSPI &tft) : tft(tft)
{
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0,0);
    char buffer[512];
    WiFi.mode(WIFI_STA);
    int16_t n = WiFi.scanNetworks();
    if (n == 0)
    {
        tft.println("No networks found");
    }
    else
    {
        Serial.printf("Found %d networks\n", n);
        for (int i = 0; i < n; ++i)
        {
            sprintf(buffer,
                    "[%d]:%s(%d)",
                    i + 1,
                    WiFi.SSID(i).c_str(),
                    WiFi.RSSI(i));
            tft.println(buffer);
            Serial.println(buffer);
        }
    }
    delay(1000);

    for (int i = 1; status != WL_CONNECTED; ++i)
    {
        tft.fillScreen(TFT_BLACK);
        tft.setCursor(0, 0);
        sprintf(buffer, "Connecting to WiFi: %s", HotspotConnector::ssid.c_str());
        tft.println(buffer);
        sprintf(buffer, "Password: %s", HotspotConnector::password.c_str());
        tft.println(buffer);
        sprintf(buffer, "Try: %d", i);
        tft.println(buffer);
        sprintf(buffer, "Current status: %d", status);
        tft.println(buffer);

        status = WiFi.begin(HotspotConnector::ssid.c_str(), HotspotConnector::password.c_str());
        delay(10000);
        Serial.println(WiFi.status());
    }

    tft.fillScreen(TFT_BLACK);
    tft.drawString("Connected :)", tft.width() / 2, tft.height() / 2);
}

HotspotConnector::~HotspotConnector()
{
    WiFi.disconnect();
}
