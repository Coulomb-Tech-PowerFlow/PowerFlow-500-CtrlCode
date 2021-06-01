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
    void DrawLoadLine(decltype(TFT_WHITE));
    void DrawChargeLine(decltype(TFT_GREEN));
    SystemMeasurementTask SysMeasurements;

    unsigned long LoadAnimatetimer{0},
        ChargeAnimatetimer{0},
        LoadArrowTimer{0};

    int PrevLoad{-1},
        prevCharge{-1},
        LoadarrowPosx0{230},
        PrevLoadarrowPosx0{-1},
        LoadarrowPosx1{220},
        PrevLoadarrowPosx1{-1};

    bool loadAnimate{false}, 
        ChargeAnimate{false};
};

}//end of namespace
