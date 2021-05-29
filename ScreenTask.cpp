#include "ScreenTask.h"
#include "customImages.h"

using namespace ScreenCtrl;

void ScreenTask::IntScreen(){
    tft.init();
    tft.fillScreen(TFT_BLACK);
    tft.setRotation(1);
}

void ScreenTask::WelcomeMessage(){

    tft.setTextColor(TFT_WHITE);  tft.setTextSize(3);
    tft.setCursor(130, 115);
    tft.drawBitmap(80, 95, plogo_bmp, 50, 43, TFT_SPECIAL);
    tft.print("OWER");
    tft.setCursor(190, 140);
    tft.print("FLOW");
    delay(1500);
    // PowerMode(0);
    tft.fillScreen(TFT_BLACK);
}

void ScreenTask::DrawDefaultScreen(){

    #define Green tft.color565(46,204,113)

    tft.fillRoundRect(139, 69, 40, 10, 0, tft.color565(60,60,60));//head 60 60 60 darkgrey
    tft.fillRoundRect(110 ,80,100,150, 20, tft.color565(60,60,60));
    tft.fillRoundRect(115 ,85,90,140, 20, TFT_WHITE	);

    tft.drawBitmap(265,40, socket_bmp, 40, 40, Green);
    // tft.drawRoundRect(255, 30, 60,83, 20,Green); //load
    tft.setCursor(265, 85); tft.setTextColor(Green); tft.setTextSize(2);
    tft.print("0W");
    
    tft.drawBitmap(15,40, adapter_bmp, 40, 40, TFT_WHITE);
    // tft.drawRoundRect(5, 30, 60,83, 20, TFT_WHITE); //smps
    tft.setCursor(15, 85); tft.setTextColor(TFT_WHITE);  tft.setTextSize(2);
    tft.print("0W");


}