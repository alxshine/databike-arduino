#include "OutputManager.h"

OutputManager::OutputManager() : tft{135, 240}
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

    if (TFT_BL > 0)
    {                                           // TFT_BL has been set in the TFT_eSPI library in the User Setup file TTGO_T_Display.h
        pinMode(TFT_BL, OUTPUT);                // Set backlight pin to output mode
        digitalWrite(TFT_BL, TFT_BACKLIGHT_ON); // Turn backlight on. TFT_BACKLIGHT_ON has been set in the TFT_eSPI library in the User Setup file TTGO_T_Display.h
    }

    tft.setSwapBytes(true);

    tft.fillScreen(TFT_BLUE);
    delay(1000);
    reset();
}

OutputManager::~OutputManager()
{
}

void OutputManager::reset()
{
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);
}