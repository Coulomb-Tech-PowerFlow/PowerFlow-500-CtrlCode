#include "ScreenTask.hpp"

ScreenCtrl::ScreenTask CtrlScreen;

void setup() {
  Serial.begin(115200);
  CtrlScreen.IntScreen();
  CtrlScreen.WelcomeMessage();
  CtrlScreen.DrawDefaultScreen();
}

void loop() {
  CtrlScreen.OperationalTask();
}
