#ifndef OUTPUTMANAGER_H
#define OUTPUTMANAGER_H

#include <HardwareSerial.h>
#include <TFT_eSPI.h>

class OutputManager
{
private:
    TFT_eSPI tft;

public:
    OutputManager();
    ~OutputManager();

    void init();

    template <class T>
    void println(T message)
    {
        Serial.println(message);
        Serial.flush();
        tft.println(message);
    }

    void reset();

    template <class... Args>
    void printf(Args... args)
    {
        Serial.printf(args...);
        Serial.flush();
        tft.printf(args...);
    }

    void newline();

    void message(String message);
};

#endif