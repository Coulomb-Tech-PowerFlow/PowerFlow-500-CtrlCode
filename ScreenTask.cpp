#include "ScreenTask.h"

using namespace ScreenCtrl;

void ScreenTask::IntScreen(){
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
}

void ScreenTask::WelcomeMessage(){

    tft.setCursor(100, 110);
    tft.setTextColor(TFT_WHITE);  tft.setTextSize(2);
    tft.println("Hello World!");
    delay(1500);
    PowerMode(0);
    tft.fillScreen(TFT_BLACK);
}