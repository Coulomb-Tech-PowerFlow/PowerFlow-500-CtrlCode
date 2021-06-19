#include "SystemMeasurementTask.h"

using namespace ScreenCtrl;

void SystemMeasurementTask::ChargingStatus() {

  if (this->ChargePwr >= 10) {
    if (this->screenState == SystemState::None)
      this->defaultLoad = true;
    this->chargeing = true;
    this->screenState = SystemState::Charging;

    if(this->SysMode == SystemMode::OFF){
        PowerMode(1);
    }//
  }

  else {
    if (this->chargeing == true) {

        this->screenState = SystemState::Charging;
        this->chargeing = false;

        if(this->SysMode == SystemMode::OFF)
            PowerMode(0);
    }
  }//
}//

void SystemMeasurementTask::GetSystemParams(){

    Batvol = Ntc = Charge = Load = 0; 

    for (int i = 0; i<this->MaxSampleTime;++i){
        this->Batvol += analogRead(SampleBat);
        this->Ntc += analogRead(SampleInventerTemp);
        this->Charge += analogRead(SampleChargeCurrent);
        this->Load += analogRead(SampleLoadCurrent);
    }//

    this->Batvol /= this->MaxSampleTime;
    this->Ntc /= this->MaxSampleTime;
    this->Charge /= this->MaxSampleTime;
    this->Load /= this->MaxSampleTime;

    this->BatteryVoltage = ((3.3f / 4095.0f) * this->Batvol) * 5.55f;  //2k 6.0f
    this->LoadCurrent = (this->Load - LoadOffset) * this->ACS_Sensitivity;
    this->ChargeCurrent = (this->Charge - ChargeOffset) * this->ACS_Sensitivity;

    this->LoadPwr = (int)(this->LoadCurrent * this->BatteryVoltage);
    this->ChargePwr = (int)(this->ChargeCurrent * this->BatteryVoltage);
    this->LoadPwr = (this->LoadPwr < 0) ? 0 : this->LoadPwr;
    this->ChargePwr = (this->ChargePwr < 0) ? 0 : this->ChargePwr;

#ifdef DEBUG
    Log(this->BatteryVoltage);
    // Log(this->Ntc);
    Log(this->Load);
    // Log(this->Charge);
#endif //DEBUG
}//

void SystemMeasurementTask::SystemTask(){
    this->ChargingStatus();
    this->GetSystemParams();
}//

void SystemMeasurementTask::SysInit(){
    pinMode(SampleBat, INPUT_ANALOG);
    pinMode(SampleInventerTemp, INPUT_ANALOG);
    pinMode(SampleChargeCurrent, INPUT_ANALOG);
    pinMode(SampleLoadCurrent, INPUT_ANALOG);
    analogReadResolution(12);
}