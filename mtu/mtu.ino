#include <memory>

#include <TFT_eSPI.h>

#include "OutputManager.h"
#include "NetworkManager.h"

using namespace std;

OutputManager outputManager{};
NetworkManager networkManager{outputManager};

void espDelay(unsigned long ms)
{
    esp_sleep_enable_timer_wakeup(ms * 1000);
    esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_ON);
    esp_light_sleep_start();
}

void setup()
{
    outputManager.println("Hello, this is the outputManager");
    outputManager.println(2);

    networkManager.init();
    // networManager = unique_ptr<NetworkManager>(new NetworkManager(tft));
}

void loop()
{
    networkManager.sendHello();
    delay(1000);
}