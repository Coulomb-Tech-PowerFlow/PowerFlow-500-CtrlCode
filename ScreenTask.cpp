#include "ScreenTask.h"
#include "customImages.h"

using namespace ScreenCtrl;

void ScreenTask::IntScreen(){
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
}

void ScreenTask::WelcomeMessage(){

    tft.setTextColor(TFT_WHITE);  tft.setTextSize(3);
    tft.setCursor(130, 115);
    tft.drawBitmap(80, 95, plogo, 50, 43, TFT_SPECIAL);
    tft.print("OWER");
    tft.setCursor(190, 140);
    tft.print("FLOW");
    // delay(1500);
    // PowerMode(0);
    // tft.fillScreen(TFT_BLACK);
}