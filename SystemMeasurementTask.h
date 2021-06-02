#pragma once

namespace ScreenCtrl {

#define SampleBat PA8
#define SampleInventerTemp PA11
#define SampleChargeCurrent PA12
#define SampleLoadCurrent PA15
#define FlashLightCtrl PB5
#define FlashLightBtn PB3
#define PowerButton PB4
#define InverterFaultSense PB8
#define InverterCtrl PB6
#define InverterFanCtrl PB1

enum class SystemState {
  None,
  Normal,
  Charging,
  Overload,
  BatteryLow
};

class SystemMeasurementTask {

  public:
    SystemMeasurementTask() {};
    ~SystemMeasurementTask() {};

    int LoadPwr{0},
        ChargePwr{0},
        BatteryPercentage{37}; // TEST

    float LoadCurrent{0},
          SmpsCurrent{0},
          BatteryVoltage{0};

    bool flashUpdate{false},
         defaultLoad{true},
         falseShutdown{true},
         charge{false};

    SystemState screenState{SystemState::Charging}; //TEST

    void ChargingStatus();

  private:
};

} // end of namespaces
