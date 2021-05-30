#pragma once

#include "SPI.h"
#include "TFT_eSPI.h"
#include "SystemMeasurementTask.hpp"
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

private:
    TFT_eSPI tft = TFT_eSPI();
    void fillBat();
    SystemMeasurementTask SysMeasurements;

    int PrevLoad{-1}, 
        PrevSmps{-1}, 
        prevSolar{-1};

    bool loadAnimate{false}, 
        solarAnimate{false}, 
        smpsAnimate{false};
};

}//end of namespace
