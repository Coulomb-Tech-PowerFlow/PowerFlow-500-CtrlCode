#include "ScreenTask.hpp"
#include "customImages.h"

using namespace ScreenCtrl;

void ScreenTask::IntScreen(){
    tft.init();
    tft.fillScreen(TFT_BLACK);
    tft.setRotation(1);
    tft.setTextFont(1);
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

    tft.drawBitmap(265,40, socket_bmp, 40, 40, TFT_WHITE);
    tft.setCursor(265, 85); tft.setTextColor(TFT_WHITE); tft.setTextSize(2);
    tft.print("0W");
    
    tft.drawBitmap(15,40, adapter_bmp, 40, 40, Green);
    tft.setCursor(15, 85); tft.setTextColor(Green);  tft.setTextSize(2);
    tft.print("0W");

    //12 11 10 9
}

void ScreenTask::PowerflowGraph(){

    if(true){
        DrawLoadLine(TFT_WHITE);
        if((millis()-this->LoadAnimatetimer) >= 500){
            this->loadAnimate = !loadAnimate;
            if(loadAnimate)
			    tft.drawRoundRect(255, 30, 60,83, 20,TFT_WHITE); //load
		    else 
		        tft.drawRoundRect(255, 30, 60,83, 20, TFT_BLACK);
            this->LoadAnimatetimer = millis();
        }//
    }//

    else{ 
	    tft.drawRoundRect(255, 30, 60,83, 20, TFT_BLACK);
        this->LoadAnimatetimer = millis();
        DrawLoadLine(TFT_BLACK);
    }
    
    if(this->SysMeasurements.ChargePwr>=5){

        if((millis()-this->ChargeAnimatetimer) >= 500){
            this->ChargeAnimate = !this->ChargeAnimate;
            if(this->ChargeAnimate)
		        tft.drawRoundRect(5, 30, 60,83, 20, Green); //smps
		    else 
		        tft.drawRoundRect(5, 30, 60,83, 20, TFT_BLACK);
            this->ChargeAnimatetimer = millis();
        } // 
    }//
    else{ 
	    tft.drawRoundRect(5, 30, 60,83, 20, TFT_BLACK);
        this->ChargeAnimatetimer = millis();
    }


}//

void ScreenTask::DrawLoadLine(decltype(TFT_WHITE) color){
    
    tft.drawFastVLine(285,112,30,color);
    tft.drawFastHLine(210,148,70,color);
    tft.drawPixel(285, 142, color);
    tft.drawPixel(284, 143, color);
    tft.drawPixel(283, 144, color);
    tft.drawPixel(282, 145, color);
    tft.drawPixel(281, 146, color);
    tft.drawPixel(280, 147, color);
    tft.drawPixel(279, 148, color);
}

void ScreenTask::OperationalTask(){
    this->PowerflowGraph();
}//

void ScreenTask::fillBat(){

    #define Green tft.color565(46,204,113)

    tft.fillRoundRect(120 ,97,80,23,7,Green); //100%
	tft.fillRoundRect(120 ,122,80,23,7,Green); //80%
	tft.fillRoundRect(120 ,147,80,23,7,Green);//60%
	tft.fillRoundRect(120 ,172,80,23,7,Green);//40%
	tft.fillRoundRect(120 ,197,80,23,7,Green);//20%
}