#include <Arduino.h>

#pragma once

namespace ScreenCtrl {

/*
TFT_MOSI A7
TFT_MIS0 A6
TFT_SCK A5
TFT_CS PA2 
TFT_DC PA3 
TFT_RST PA4 
*/

#define SampleBat PA0
#define SampleInventerTemp PB0
#define SampleChargeCurrent PA1 //B0
#define SampleLoadCurrent PB1
#define FlashLightCtrl PB5
#define FlashLightBtn PB3
#define PowerButton PB4
#define InverterFaultSense PB8
#define InverterCtrl PB6
#define InverterFanCtrl PB7
#define TFT_Led PB10

#define PowerMode(x)  digitalWrite(TFT_Led, x)
#define DEBUG true
#define Log(x) Serial.println(x);

  enum class SystemState
  {
    None,
    Normal,
    Charging,
    Overload,
    BatteryLow
  };

  enum class SystemMode
  {
    OFF,
    ON
  };

  class SystemMeasurementTask
  {

  public:
    SystemMeasurementTask() {};
    ~SystemMeasurementTask() {};

    int LoadPwr{0},
        ChargePwr{0},
        BatteryPercentage{10}; // TEST

    float LoadCurrent{0},
          ChargeCurrent{0},
          BatteryVoltage{0};

    SystemState screenState{SystemState::Normal}; //TEST
    SystemMode SysMode{SystemMode::OFF};
    
    void SystemTask();
    void SysInit();

  private:
    void ChargingStatus();
    void GetSystemParams();
    
    bool flashUpdate{false},
         defaultLoad{true},
         falseShutdown{true},
         chargeing{false};

    const int MaxSampleTime = 300,
          ChargeOffset = 2032,
          LoadOffset = 2031;

    const float ACS_Sensitivity = 0.030518f;
    const float lowBattery = 12.2f;
    const float fullBattery = 15.0f;
    const float batCal = (fullBattery - lowBattery);

    int Batvol{0}, 
        Ntc{0}, 
        Charge{0}, 
        Load{0};
};

} // end of namespaces
