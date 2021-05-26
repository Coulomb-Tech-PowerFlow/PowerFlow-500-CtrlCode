#include "ScreenTask.h"
#include "customImages.h"

using namespace ScreenCtrl;

void ScreenTask::IntScreen(){
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
}

void ScreenTask::WelcomeMessage(){

    // tft.setCursor(100, 110); 78 80 99
    // tft.setTextColor(TFT_WHITE);  tft.setTextSize(2);
tft.drawBitmap(10, 90, plogo, 60, 52, TFT_SPECIAL);
tft.drawBitmap(75, 90, flowlogo, 235, 99, TFT_LIGHTGREY);
// delay(1500);
// PowerMode(0);
// tft.fillScreen(TFT_BLACK);
}