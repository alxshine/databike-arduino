#include <memory>

#include <TFT_eSPI.h>

#include "OutputManager.h"
#include "NetworkManager.h"

using namespace std;


OutputManager outputManager;
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
    
    espDelay(1000);

    Serial.println("Beginning WiFi connection");
    outputManager.println("Hello, this is the outputManager");
    outputManager.println(2);
    // networManager = unique_ptr<NetworkManager>(new NetworkManager(tft));
}

void loop()
{
    Serial.println("Loop");
    espDelay(10000);
}