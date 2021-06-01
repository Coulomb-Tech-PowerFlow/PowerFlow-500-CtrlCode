#include "SystemMeasurementTask.hpp"

using namespace ScreenCtrl;

void SystemMeasurementTask::ChargingStatus() {

  if (this->ChargePwr >= 10) {
    if (this->screenState == SystemState::None)
      this->defaultLoad = true;
    this->charge = true;
    this->screenState = SystemState::Charging;
  }

  else {
    if (this->charge == true) {
      this->screenState = SystemState::Charging;
      this->charge = false;
      // if (!screenState){
      //         ScreenTask(0);
      // }
    }
  }//
}//
