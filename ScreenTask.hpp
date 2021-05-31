#pragma once

#include "SPI.h"
#include "TFT_eSPI.h"
#include "SystemMeasurementTask.hpp"
#include <Arduino.h>
// #include "Lib/Fontslib.h"

#define PowerMode(x)  digitalWrite(TFT_BL, x)

namespace ScreenCtrl{

class ScreenTask{

public:
    ScreenTask(){}
    ~ScreenTask(){}

    void IntScreen();
    void WelcomeMessage();
    void DrawDefaultScreen();
    void OperationalTask();

private:
    TFT_eSPI tft = TFT_eSPI();
    void fillBat();
    void PowerflowGraph();
    SystemMeasurementTask SysMeasurements;

    unsigned long LoadAnimatetimer{0},
            ChargeAnimatetimer{0};

    int PrevLoad{-1}, 
        prevCharge{-1};

    bool loadAnimate{false}, 
        ChargeAnimate{false};
};

}//end of namespace
