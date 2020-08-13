#include <memory>

#include <TFT_eSPI.h>

#include "NetworkManager.h"

using namespace std;


unique_ptr<NetworkManager> networManager;
TFT_eSPI tft = TFT_eSPI(135, 240);

void espDelay(unsigned long ms)
{
    esp_sleep_enable_timer_wakeup(ms * 1000);
    esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_ON);
    esp_light_sleep_start();
}

void setup()
{
    Serial.begin(115200);
    while (!Serial)
        delay(100);

    Serial.println("Setting up TFT screen");
    tft.init();
    tft.setRotation(0);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(1);
    tft.setTextColor(TFT_GREEN);
    tft.setCursor(0, 0);
    tft.setTextDatum(MC_DATUM);

    if (TFT_BL > 0) {                           // TFT_BL has been set in the TFT_eSPI library in the User Setup file TTGO_T_Display.h
        pinMode(TFT_BL, OUTPUT);                // Set backlight pin to output mode
        digitalWrite(TFT_BL, TFT_BACKLIGHT_ON); // Turn backlight on. TFT_BACKLIGHT_ON has been set in the TFT_eSPI library in the User Setup file TTGO_T_Display.h
    }

    tft.setSwapBytes(true);

    tft.fillScreen(TFT_BLUE);
    espDelay(1000);

    Serial.println("Beginning WiFi connection");
    networManager = unique_ptr<NetworkManager>(new NetworkManager(tft));
}

void loop()
{
    Serial.println("Loop");
    espDelay(10000);
}