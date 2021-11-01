#include "SystemMeasurementTask.h"

using namespace ScreenCtrl;

void SystemMeasurementTask::ChargingStatus() {

  if (this->ChargePwr >= 10) {
    if (this->screenState == SystemState::None)
      this->defaultLoad = true;
    this->chargeing = true;
    this->screenState = SystemState::Charging;

    if (this->SysMode == SystemMode::OFF) {
      PowerMode(1);
    }//
  }

  else {
    if (this->chargeing == true) {
      this->screenState = SystemState::Normal;
      this->chargeing = false;
      if (this->SysMode == SystemMode::OFF)
        PowerMode(0);
    }
  }//
}//

void SystemMeasurementTask::GetSystemParams() {

  float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
  Batvol = Ntc = Charge = Load = 0;

  for (int i = 0; i < this->MaxSampleTime; ++i) {
    this->Batvol += analogRead(SampleBat);
    this->Ntc += analogRead(SampleInventerTemp);
    this->Charge += analogRead(SampleChargeCurrent);
    this->Load += analogRead(SampleLoadCurrent);
  }//

  this->Batvol /= this->MaxSampleTime;
  this->Ntc /= this->MaxSampleTime;
  this->Charge /= this->MaxSampleTime;
  this->Load /= this->MaxSampleTime;

  this->BatteryVoltage = ((3.3f / 4095.0f) * this->Batvol) * 6.f;  //2k 6.0f
  this->BatteryPercentage = ((this->BatteryVoltage - this->lowBattery) / this->batCal) * 100;
  this->LoadCurrent = (this->Load - LoadOffset) * this->ACS_Sensitivity;
  this->ChargeCurrent = (this->Charge - ChargeOffset) * this->ACS_Sensitivity;

  this->BatteryPercentage = (this->BatteryPercentage < 0) ? 0 : this->BatteryPercentage;
  this->BatteryPercentage = (this->BatteryPercentage > 100) ? 100 : this->BatteryPercentage;
  this->LoadPwr = (int)(this->LoadCurrent * this->BatteryVoltage);
  this->ChargePwr = (int)(this->ChargeCurrent * this->BatteryVoltage);
  this->LoadPwr = (this->LoadPwr < 0) ? 0 : this->LoadPwr;
  this->ChargePwr = (this->ChargePwr < 0) ? 0 : this->ChargePwr;

  float r2 = 10000 * (4095 / (float)this->Ntc - 1.0);
  float logr2 = log(r2);
  this->InternalTemp = (1.0 / (c1 + c2*logr2 + c3*logr2*logr2*logr2));
  this->InternalTemp = this->InternalTemp - 273.15;

#ifdef DEBUG
  Log(this->BatteryVoltage);
  Log(this->InternalTemp);
  Log(this->Load);
  Log(this->Charge);
  Log(this->BatteryPercentage);
#endif //DEBUG
}//

void SystemMeasurementTask::SystemTask() {
  this->ChargingStatus();
  this->GetSystemParams();
}//

void SystemMeasurementTask::SysInit() {
  pinMode(InverterCtrl, OUTPUT);
  pinMode(InverterFanCtrl, OUTPUT);
  pinMode(FlashLightCtrl, OUTPUT);
  pinMode(FlashLightBtn, INPUT);
  pinMode(PowerButton, INPUT);
  pinMode(SampleBat, INPUT_ANALOG);
  pinMode(SampleInventerTemp, INPUT_ANALOG);
  pinMode(SampleChargeCurrent, INPUT_ANALOG);
  pinMode(SampleLoadCurrent, INPUT_ANALOG);
  analogReadResolution(12);
}
