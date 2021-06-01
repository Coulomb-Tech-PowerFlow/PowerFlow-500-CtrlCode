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
    tft.fillRoundRect(115 ,85,90,140, 20, TFT_WHITE);

    tft.drawBitmap(265,40, socket_bmp, 40, 40, TFT_WHITE);
    tft.setCursor(265, 85); tft.setTextColor(TFT_WHITE); tft.setTextSize(2);
    tft.print("0W");
    
    tft.drawBitmap(15,40, adapter_bmp, 40, 40, Green);
    tft.setCursor(15, 85); tft.setTextColor(Green);  tft.setTextSize(2);
    tft.print("0W");

    this->fillBat();//test

    //12 11 10 9
}

void ScreenTask::PowerflowGraph(){

    if(this->SysMeasurements.LoadPwr>=5 || true){

        this->DrawLoadLine(TFT_WHITE);

        if((millis()-this->LoadAnimatetimer) >= 500){
            this->loadAnimate = !this->loadAnimate;
            if(this->loadAnimate)
			    tft.drawRoundRect(255, 30, 60,83, 20,TFT_WHITE); //load
		    else
                tft.drawRoundRect(255, 30, 60,83, 20, TFT_BLACK);
            this->LoadAnimatetimer = millis();
        }//
    }//

    else{ 
	    tft.drawRoundRect(255, 30, 60,83, 20, TFT_BLACK);
        this->LoadAnimatetimer = millis();
        this->DrawLoadLine(TFT_BLACK);
    }
    
    if(this->SysMeasurements.ChargePwr>=5 || true){

        this->DrawChargeLine(tft.color565(46,204,113));

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
        this->DrawChargeLine(TFT_BLACK);
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

    if(color!=TFT_BLACK){

        if((millis()-this->LoadArrowTimer) >= 40){

            if(LoadArrowPos.PrevArrowPosXOrigins!=-1 && !this->LoadarrowSwitch){
                tft.drawLine(LoadArrowPos.PrevArrowPosXOrigins,LoadArrowPos.ArrowPosYOrigins,LoadArrowPos.PrevarrowPosx0, LoadArrowPos.arrowPosy0, TFT_BLACK);
                tft.drawLine(LoadArrowPos.PrevArrowPosXOrigins,LoadArrowPos.ArrowPosYOrigins,LoadArrowPos.PrevarrowPosx1, LoadArrowPos.arrowPosy1, TFT_BLACK);
            }
            else if(this->LoadarrowSwitch){
                tft.drawLine(LoadArrowPos.ArrowPosXOrigins,LoadArrowPos.PrevArrowPosYOrigins,LoadArrowPos.arrowPosx0, LoadArrowPos.PrevarrowPosy0, TFT_BLACK);
                tft.drawLine(LoadArrowPos.ArrowPosXOrigins,LoadArrowPos.PrevArrowPosYOrigins,LoadArrowPos.arrowPosx1, LoadArrowPos.PrevarrowPosy1, TFT_BLACK);
            }

            tft.drawLine(LoadArrowPos.ArrowPosXOrigins,LoadArrowPos.ArrowPosYOrigins,LoadArrowPos.arrowPosx0, LoadArrowPos.arrowPosy0, color);
            tft.drawLine(LoadArrowPos.ArrowPosXOrigins,LoadArrowPos.ArrowPosYOrigins,LoadArrowPos.arrowPosx1, LoadArrowPos.arrowPosy1, color);
            
            LoadArrowPos.PrevarrowPosx0 = LoadArrowPos.arrowPosx0;
            LoadArrowPos.PrevarrowPosx1 = LoadArrowPos.arrowPosx1;
            LoadArrowPos.PrevArrowPosXOrigins = LoadArrowPos.ArrowPosXOrigins;

            if(LoadArrowPos.ArrowPosXOrigins == 280){

                this->LoadarrowSwitch = true;
                tft.drawLine(LoadArrowPos.ArrowPosXOrigins,LoadArrowPos.ArrowPosYOrigins,LoadArrowPos.arrowPosx0, LoadArrowPos.arrowPosy0, TFT_BLACK);
                tft.drawLine(LoadArrowPos.ArrowPosXOrigins,LoadArrowPos.ArrowPosYOrigins,LoadArrowPos.arrowPosx1, LoadArrowPos.arrowPosy1, TFT_BLACK);

                LoadArrowPos.ArrowPosXOrigins = 285;
                LoadArrowPos.arrowPosx0 = 279;
                LoadArrowPos.arrowPosx1 = 291;
                LoadArrowPos.ArrowPosYOrigins = 136;
                LoadArrowPos.arrowPosy0 = 142;
                LoadArrowPos.arrowPosy1 = 142;
            }
            if(!this->LoadarrowSwitch){
                LoadArrowPos.ArrowPosXOrigins += 1;
                LoadArrowPos.arrowPosx0 += 1;
                LoadArrowPos.arrowPosx1 += 1;
            }

            if(this->LoadarrowSwitch){
                LoadArrowPos.PrevArrowPosYOrigins = LoadArrowPos.ArrowPosYOrigins;
                LoadArrowPos.PrevarrowPosy0 = LoadArrowPos.arrowPosy0;
                LoadArrowPos.PrevarrowPosy1 = LoadArrowPos.arrowPosy1;
                LoadArrowPos.ArrowPosYOrigins -= 1;
                LoadArrowPos.arrowPosy0 -= 1;
                LoadArrowPos.arrowPosy1 -= 1;

                if(LoadArrowPos.ArrowPosYOrigins < 112){

                    tft.drawLine(LoadArrowPos.ArrowPosXOrigins,LoadArrowPos.PrevArrowPosYOrigins,LoadArrowPos.arrowPosx0, LoadArrowPos.PrevarrowPosy0, TFT_BLACK);
                    tft.drawLine(LoadArrowPos.ArrowPosXOrigins,LoadArrowPos.PrevArrowPosYOrigins,LoadArrowPos.arrowPosx1, LoadArrowPos.PrevarrowPosy1, TFT_BLACK);

                    this->LoadarrowSwitch = false;
                    LoadArrowPos.ArrowPosXOrigins = 224;
                    LoadArrowPos.arrowPosx0 = 218;
                    LoadArrowPos.arrowPosx1 = 218;
                    LoadArrowPos.ArrowPosYOrigins = 148;
                    LoadArrowPos.arrowPosy0 = 142;
                    LoadArrowPos.arrowPosy1 = 154;
                }
            }

            this->LoadArrowTimer = millis();
        }//
    }//
    else {
        LoadArrowPos.PrevarrowPosx0 = LoadArrowPos.PrevarrowPosx1 = LoadArrowPos.PrevArrowPosXOrigins =
        LoadArrowPos.PrevarrowPosy0 = LoadArrowPos.PrevarrowPosy1 = LoadArrowPos.PrevArrowPosYOrigins = -1;
        LoadArrowPos.ArrowPosXOrigins = 224;
        LoadArrowPos.arrowPosx0 = 218;
        LoadArrowPos.arrowPosx1 = 218;
        LoadArrowPos.ArrowPosYOrigins = 148;
        LoadArrowPos.arrowPosy0 = 142;
        LoadArrowPos.arrowPosy1 = 154;
        this->LoadarrowSwitch = false;
    }
}//

void ScreenTask::DrawChargeLine(decltype(TFT_GREEN) color){

    tft.drawFastVLine(35,112,30,color);
    tft.drawFastHLine(41,148,70,color);
    tft.drawPixel(35, 142, color);
    tft.drawPixel(36, 143, color);
    tft.drawPixel(37, 144, color);
    tft.drawPixel(38, 145, color);
    tft.drawPixel(39, 146, color);
    tft.drawPixel(40, 147, color);
    tft.drawPixel(41, 148, color);

    if(color!=TFT_BLACK){

        if((millis()-this->ChargeArrowTimer) >= 40){

            if(ChargeArrowPos.PrevArrowPosYOrigins!=-1 && !this->ChargearrowSwitch){
                tft.drawLine(ChargeArrowPos.ArrowPosXOrigins,ChargeArrowPos.PrevArrowPosYOrigins,ChargeArrowPos.arrowPosx0, ChargeArrowPos.PrevarrowPosy0, TFT_BLACK);
                tft.drawLine(ChargeArrowPos.ArrowPosXOrigins,ChargeArrowPos.PrevArrowPosYOrigins,ChargeArrowPos.arrowPosx1, ChargeArrowPos.PrevarrowPosy1, TFT_BLACK);
            }
            else if(this->ChargearrowSwitch){
                tft.drawLine(ChargeArrowPos.PrevArrowPosXOrigins,ChargeArrowPos.ArrowPosYOrigins,ChargeArrowPos.PrevarrowPosx0, ChargeArrowPos.arrowPosy0, TFT_BLACK);
                tft.drawLine(ChargeArrowPos.PrevArrowPosXOrigins,ChargeArrowPos.ArrowPosYOrigins,ChargeArrowPos.PrevarrowPosx1, ChargeArrowPos.arrowPosy1, TFT_BLACK);
            }

                tft.drawLine(ChargeArrowPos.ArrowPosXOrigins,ChargeArrowPos.ArrowPosYOrigins,ChargeArrowPos.arrowPosx0, ChargeArrowPos.arrowPosy0, color);
                tft.drawLine(ChargeArrowPos.ArrowPosXOrigins,ChargeArrowPos.ArrowPosYOrigins,ChargeArrowPos.arrowPosx1, ChargeArrowPos.arrowPosy1, color);

                ChargeArrowPos.PrevarrowPosy0 = ChargeArrowPos.arrowPosy0;
                ChargeArrowPos.PrevarrowPosy1 = ChargeArrowPos.arrowPosy1;
                ChargeArrowPos.PrevArrowPosYOrigins = ChargeArrowPos.ArrowPosYOrigins;

                if(ChargeArrowPos.ArrowPosYOrigins == 142){

                    this->ChargearrowSwitch = true;
                    tft.drawLine(ChargeArrowPos.ArrowPosXOrigins,ChargeArrowPos.ArrowPosYOrigins,ChargeArrowPos.arrowPosx0, ChargeArrowPos.arrowPosy0, TFT_BLACK);
                    tft.drawLine(ChargeArrowPos.ArrowPosXOrigins,ChargeArrowPos.ArrowPosYOrigins,ChargeArrowPos.arrowPosx1, ChargeArrowPos.arrowPosy1, TFT_BLACK);

                    ChargeArrowPos.ArrowPosXOrigins = 46;
                    ChargeArrowPos.arrowPosx0 = 40;
                    ChargeArrowPos.arrowPosx1 = 40;
                    ChargeArrowPos.ArrowPosYOrigins = 148;
                    ChargeArrowPos.arrowPosy0 = 142;
                    ChargeArrowPos.arrowPosy1 = 154;
                }

                if(!this->ChargearrowSwitch){
                    ChargeArrowPos.ArrowPosYOrigins += 1;
                    ChargeArrowPos.arrowPosy0 += 1;
                    ChargeArrowPos.arrowPosy1 += 1;
                }

                if(this->ChargearrowSwitch){
                    ChargeArrowPos.PrevArrowPosXOrigins = ChargeArrowPos.ArrowPosXOrigins;
                    ChargeArrowPos.PrevarrowPosx0 = ChargeArrowPos.arrowPosx0;
                    ChargeArrowPos.PrevarrowPosx1 = ChargeArrowPos.arrowPosx1;
                    ChargeArrowPos.ArrowPosXOrigins += 1;
                    ChargeArrowPos.arrowPosx0 += 1;
                    ChargeArrowPos.arrowPosx1 += 1;

                if(ChargeArrowPos.ArrowPosXOrigins > 110){
                    
                    tft.drawLine(ChargeArrowPos.PrevArrowPosXOrigins,ChargeArrowPos.ArrowPosYOrigins,ChargeArrowPos.PrevarrowPosx0, ChargeArrowPos.arrowPosy0, TFT_BLACK);
                    tft.drawLine(ChargeArrowPos.PrevArrowPosXOrigins,ChargeArrowPos.ArrowPosYOrigins,ChargeArrowPos.PrevarrowPosx1, ChargeArrowPos.arrowPosy1, TFT_BLACK);
               
                    this->ChargearrowSwitch = false;
                    ChargeArrowPos.ArrowPosXOrigins = 35;
                    ChargeArrowPos.arrowPosx0 = 29;
                    ChargeArrowPos.arrowPosx1 = 41;
                    ChargeArrowPos.ArrowPosYOrigins = 124;
                    ChargeArrowPos.arrowPosy0 = 118;
                    ChargeArrowPos.arrowPosy1 = 118;
                }
            }

                this->ChargeArrowTimer = millis();
        }//
    }//

}//


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