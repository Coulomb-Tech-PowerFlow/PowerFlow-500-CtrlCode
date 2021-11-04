#pragma once

#include "SPI.h"
#include "TFT_eSPI.h"
#include "SystemStructs.h"
#include "SystemMeasurementTask.h"
#include <Arduino.h>
// #include "Lib/Fontslib.h"

namespace ScreenCtrl {

class ScreenTask {

  public:

    ScreenTask() {
      BatteryBits.Flags = 0x00;
    }
    ~ScreenTask() {}

    void IntScreen();
    void WelcomeMessage();
    void DrawDefaultScreen();
    void OperationalTask();
    void PowerOnCommand();
    SystemMeasurementTask SysMeasurements;

  private:
    TFT_eSPI tft = TFT_eSPI();
    void FillBat(decltype(TFT_GREEN), bool Override = false);
    void PowerflowGraph();
    void DrawLoadLine(decltype(TFT_WHITE));
    void DrawChargeLine(decltype(TFT_GREEN));
    void LoadLine(decltype(TFT_WHITE));
    void ChargeLine(decltype(TFT_WHITE));
    void BatteryModeTask();
    void BatChargeTask();
    void DisplayData();
    void BatteryLowMessage();
    void OverLoadMessage();

    unsigned long LoadAnimatetimer{0},
             ChargeAnimatetimer{0},
             LoadArrowTimer{0},
             DataRefreshTimer{0},
             BatRefreshTimer{0},
             ChargeArrowTimer{0};

    int PrevLoad{ -1},
        prevCharge{ -1};

    BatSegFields BatteryBits;
    ArrowposDat LoadArrowPos = ArrowposDat(224, 218, 218, 148, 142, 154);
    ArrowposDat ChargeArrowPos = ArrowposDat(35, 29, 41, 124, 118, 118);
    StateBits BatNormBit;
    StateBits SegChargeBits;
    StateBits ChargeBits;
    PrevStateBits BatNormPrevState{PrevStateBits::clear_state};
    PrevStateBits ChargePrevState{PrevStateBits::clear_state};

    bool loadAnimate{false},
         ChargeAnimate{false},
         LoadarrowSwitch{false},
         ChargearrowSwitch{false},
         CautionFlag{false},
         InverterFanState{false};
};

}//end of namespace
