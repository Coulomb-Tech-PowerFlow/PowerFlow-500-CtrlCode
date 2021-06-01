#pragma once

#include "SPI.h"
#include "TFT_eSPI.h"
#include "SystemMeasurementTask.hpp"
#include <Arduino.h>
// #include "Lib/Fontslib.h"

#define PowerMode(x)  digitalWrite(TFT_BL, x)

namespace ScreenCtrl{

struct ArrowposDat
{
    int arrowPosx0{218},
        PrevarrowPosx0{-1},
        arrowPosx1{218},
        PrevarrowPosx1{-1},
        ArrowPosXOrigins{224},
        PrevArrowPosXOrigins{-1},
        ArrowPosYOrigins{148},
        PrevArrowPosYOrigins{-1},
        arrowPosy0{142},
        PrevarrowPosy0{-1},
        arrowPosy1{154},
        PrevarrowPosy1{-1};
};

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
        prevCharge{-1};

    ArrowposDat LoadArrowPos;
    ArrowposDat ChargeArrowPos;

    bool loadAnimate{false},
        ChargeAnimate{false},
        LoadarrowSwitch{false};
};

}//end of namespace
