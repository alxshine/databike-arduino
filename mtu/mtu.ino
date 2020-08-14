#include <memory>

#include "OutputManager.h"
#include "NetworkManager.h"
#include "SensorManager.h"

using namespace std;

OutputManager outputManager{};
NetworkManager networkManager{outputManager};
SensorManager sensorManager{outputManager};

void espDelay(unsigned long ms)
{
    esp_sleep_enable_timer_wakeup(ms * 1000);
    esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_ON);
    esp_light_sleep_start();
}

void setup()
{
    outputManager.init();
    // networkManager.init();
    sensorManager.init();

    delay(1000);
}

void loop()
{
    sensorManager.updateSensorValues();
    auto values = sensorManager.getSensorValues();

    outputManager.reset();
    outputManager.println("Accelerometer");
    outputManager.printf("X = %d\nY = %d\nZ = %d\n", values.AcX, values.AcY, values.AcZ);
    outputManager.newline();
    outputManager.println("Gyroscope");
    outputManager.printf("X = %d\nY = %d\nZ = %d\n", values.GyX, values.GyY, values.GyZ);
    outputManager.println(values.to_string());
    delay(333);
}