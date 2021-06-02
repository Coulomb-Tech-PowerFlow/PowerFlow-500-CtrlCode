#pragma once

#include "SPI.h"
#include "TFT_eSPI.h"
#include "SystemStructs.h"
#include "SystemMeasurementTask.h"
#include <Arduino.h>
// #include "Lib/Fontslib.h"

#define PowerMode(x)  digitalWrite(TFT_BL, x)

namespace ScreenCtrl {

class ScreenTask {

  public:
    ScreenTask() { BatteryBits.Flags = 0x00;}
    ~ScreenTask() {}

    void IntScreen();
    void WelcomeMessage();
    void DrawDefaultScreen();
    void OperationalTask();

  private:
    TFT_eSPI tft = TFT_eSPI();
    void FillBat(decltype(TFT_GREEN),bool Override = false);
    void PowerflowGraph();
    void DrawLoadLine(decltype(TFT_WHITE));
    void DrawChargeLine(decltype(TFT_GREEN));
    void BatteryModeTask();
    SystemMeasurementTask SysMeasurements;
    BatSegFields BatteryBits;

    unsigned long LoadAnimatetimer{0},
             ChargeAnimatetimer{0},
             LoadArrowTimer{0},
             ChargeArrowTimer{0};

    int PrevLoad{ -1},
        prevCharge{ -1};

    ArrowposDat LoadArrowPos = ArrowposDat(224, 218, 218, 148, 142, 154);
    ArrowposDat ChargeArrowPos = ArrowposDat(35, 29, 41, 124, 118, 118);
    StateBits BatNormBit;
    PrevStateBits BatNormPrevState{PrevStateBits::clear_state};

    bool loadAnimate{false},
         ChargeAnimate{false},
         LoadarrowSwitch{false},
         ChargearrowSwitch{false};
};

}//end of namespace
