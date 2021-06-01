#pragma once

#include "SPI.h"
#include "TFT_eSPI.h"
#include "SystemMeasurementTask.hpp"
#include <Arduino.h>
// #include "Lib/Fontslib.h"

#define PowerMode(x)  digitalWrite(TFT_BL, x)

namespace ScreenCtrl{

struct ArrowposDat{

    int arrowPosx0{0},
        PrevarrowPosx0{-1},
        arrowPosx1{0},
        PrevarrowPosx1{-1},
        ArrowPosXOrigins{0},
        PrevArrowPosXOrigins{-1},
        ArrowPosYOrigins{0},
        PrevArrowPosYOrigins{-1},
        arrowPosy0{0},
        PrevarrowPosy0{-1},
        arrowPosy1{0},
        PrevarrowPosy1{-1};

    ArrowposDat(int xp,int x0,int x1,int yp,int y0, int y1){
        this->ArrowPosXOrigins = xp;
        this->arrowPosx0 = x0;
        this->arrowPosx1 = x1;
        this->ArrowPosYOrigins = yp;
        this->arrowPosy0 = y0;
        this->arrowPosy1 = y1;
    }
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
        LoadArrowTimer{0},
        ChargeArrowTimer{0};

    int PrevLoad{-1},
        prevCharge{-1};

    ArrowposDat LoadArrowPos = ArrowposDat(224,218,218,148,142,154);
    ArrowposDat ChargeArrowPos = ArrowposDat(35,29,41,124,118,118);

    bool loadAnimate{false},
        ChargeAnimate{false},
        LoadarrowSwitch{false},
        ChargearrowSwitch{false};
};

}//end of namespace
