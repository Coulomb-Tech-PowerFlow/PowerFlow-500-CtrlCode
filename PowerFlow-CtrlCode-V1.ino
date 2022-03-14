#include "ScreenTask.h"

ScreenCtrl::ScreenTask CtrlScreen;

void setup() {
  Serial.begin(115200);
  CtrlScreen.IntScreen();
  CtrlScreen.SysMeasurements.SysInit();
  CtrlScreen.WelcomeMessage();
  CtrlScreen.DrawDefaultScreen();

}

void loop() {
  CtrlScreen.OperationalTask();
}
