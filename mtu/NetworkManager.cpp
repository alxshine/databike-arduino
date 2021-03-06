#include "NetworkManager.h"

#include <string>

#include "WiFi.h"
#include <TFT_eSPI.h>

using namespace std;

NetworkManager::NetworkManager(OutputManager &outputManager) : outputManager(outputManager)
{
}

void NetworkManager::init()
{
    outputManager.reset();
    WiFi.mode(WIFI_STA);
    int16_t n = WiFi.scanNetworks();
    if (n == 0)
    {
        outputManager.println("No networks found");
    }
    else
    {
        outputManager.printf("Found %d networks\n", n);
        for (int i = 0; i < n; ++i)
        {
            outputManager.printf("[%d]:%s(%d)\n", i + 1, WiFi.SSID(i).c_str(), WiFi.RSSI(i));
        }
    }
    delay(1000);

    for (int i = 1; status != WL_CONNECTED; ++i)
    {
        outputManager.reset();
        outputManager.printf("Connecting to WiFi: %s\n", NetworkManager::ssid.c_str());
        outputManager.printf("Password: %s\n", NetworkManager::password.c_str());
        outputManager.printf("Try: %d\n", i);
        outputManager.printf("Current status: %d\n", status);

        status = WiFi.begin(NetworkManager::ssid.c_str(), NetworkManager::password.c_str());
        delay(5000);
        outputManager.println(WiFi.status());
    }

    broadCastIp = WiFi.broadcastIP();

    outputManager.reset();
    outputManager.message("Connected :)");
}

NetworkManager::~NetworkManager()
{
    WiFi.disconnect();
}

void NetworkManager::sendHello()
{
    outputManager.println("Sending UDP hello broadcast");
    udp.beginPacket(broadCastIp, 1337);
    udp.write((uint8_t *)"Hello, this is a UDP Packet", 27);
    udp.endPacket();
}

void NetworkManager::sendSensorValues(SensorValues values)
{
    auto message = values.to_string();
    udp.beginPacket(broadCastIp, 1337);
    udp.write((uint8_t *)message.c_str(), message.size());
    udp.endPacket();
}