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


    template<class T>
    void println(T message){
        Serial.println(message);
        Serial.flush();
        tft.println(message);
    }

    void reset();
};

#endif