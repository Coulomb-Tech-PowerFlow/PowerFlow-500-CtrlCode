#include "ScreenTask.h"
#include "customImages.h"

using namespace ScreenCtrl;

void ScreenTask::IntScreen() {
  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.setRotation(3);
  tft.setTextFont(0);
}

void ScreenTask::WelcomeMessage() {

#define White tft.color565(252,252,252)
#define Black tft.color565(0, 0, 0)

  tft.setTextColor(White);  tft.setTextSize(3);
  tft.setCursor(130, 115);
  tft.drawBitmap(80, 95, plogo_bmp, 50, 43, TFT_SPECIAL);
  tft.print("OWER");
  tft.setCursor(190, 140);
  tft.print("FLOW");
  delay(1500);
  PowerMode(0);
  this->SysMeasurements.SysMode = SystemMode::OFF;
  tft.fillScreen(TFT_BLACK);
}

void ScreenTask::BatteryLowMessage()
{
  tft.setTextColor(tft.color565(180, 0, 0));  tft.setTextSize(3);
  tft.setCursor(80, 115);
  tft.print("Battery Low");
  tft.setCursor(100, 140);
  tft.setTextColor(tft.color565(252, 252, 252));
  tft.print("System Down");
}

void ScreenTask::OverLoadMessage()
{
  tft.setTextColor(tft.color565(180, 0, 0));  tft.setTextSize(3);
  tft.setCursor(80, 115);
  tft.print("OverLoad");
  tft.setCursor(100, 140);
  tft.setTextColor(tft.color565(252, 252, 252));
  tft.print("System Down");
}

void ScreenTask::DrawDefaultScreen() {

#define Green tft.color565(46,170,113)

  tft.fillRoundRect(139, 69, 40, 10, 0, tft.color565(60, 60, 60)); //head 60 60 60 darkgrey
  tft.fillRoundRect(110 , 80, 100, 150, 20, tft.color565(60, 60, 60));
  tft.fillRoundRect(115 , 85, 90, 140, 20, White);

  tft.drawBitmap(265, 40, socket_bmp, 40, 40, White);
  tft.setCursor(263, 85); tft.setTextColor(White); tft.setTextSize(2);
  String loadPwr = String(this->SysMeasurements.LoadPwr)+"W";
  tft.print(loadPwr);

  tft.drawBitmap(15, 40, adapter_bmp, 40, 40, Green);
  tft.setCursor(13, 85); tft.setTextColor(Green);  tft.setTextSize(2);
  String chargePwr = String(this->SysMeasurements.ChargePwr)+"W";
  tft.print(chargePwr);

  if (this->SysMeasurements.screenState == SystemState::Normal)
    tft.drawBitmap(280, 210, power_bmp, 20, 21, Green);
  else if (this->SysMeasurements.screenState == SystemState::Charging)
    tft.drawBitmap(280, 210, power_bmp, 20, 21, tft.color565(60, 60, 60)); //Test
}

void ScreenTask::LoadLine(decltype(TFT_WHITE) color)
{
  tft.drawFastVLine(285, 112, 30, color);
  tft.drawFastHLine(210, 148, 70, color);
  tft.drawPixel(285, 142, color);
  tft.drawPixel(284, 143, color);
  tft.drawPixel(283, 144, color);
  tft.drawPixel(282, 145, color);
  tft.drawPixel(281, 146, color);
  tft.drawPixel(280, 147, color);
  tft.drawPixel(279, 148, color);
}

void ScreenTask::ChargeLine(decltype(TFT_WHITE) color)
{
    tft.drawFastVLine(35, 112, 30, color);
    tft.drawFastHLine(41, 148, 70, color);
    tft.drawPixel(35, 142, color);
    tft.drawPixel(36, 143, color);
    tft.drawPixel(37, 144, color);
    tft.drawPixel(38, 145, color);
    tft.drawPixel(39, 146, color);
    tft.drawPixel(40, 147, color);
    tft.drawPixel(41, 148, color);
}

void ScreenTask::PowerflowGraph() {

  if (this->SysMeasurements.LoadPwr >= 10) {

    this->DrawLoadLine(White);

    if ((millis() - this->LoadAnimatetimer) >= 500) {
      this->loadAnimate = !this->loadAnimate;
      if (this->loadAnimate) {
        tft.drawRoundRect(255, 30, 60, 83, 20, White); //load
        if (this->BatNormBit.bit5 && this->SysMeasurements.screenState == SystemState::Normal) {
          tft.drawBitmap(140, 120, caution_bmp, 40, 40, tft.color565(255, 218, 28));
          this->CautionFlag = true;
        }
      }//
      else {
        tft.drawRoundRect(255, 30, 60, 83, 20, TFT_BLACK);
        if (this->CautionFlag) {
          tft.drawBitmap(140, 120, caution_bmp, 40, 40, White); //Test
          this->CautionFlag = false;
        }
      }//
      this->LoadAnimatetimer = millis();
    }//
  }//

  else {
    tft.drawRoundRect(255, 30, 60, 83, 20, TFT_BLACK);
    this->LoadAnimatetimer = millis();
    this->LoadLine(TFT_BLACK);
    tft.drawLine(LoadArrowPos.ArrowPosXOrigins, LoadArrowPos.PrevArrowPosYOrigins, LoadArrowPos.arrowPosx0, LoadArrowPos.PrevarrowPosy0, TFT_BLACK);
    tft.drawLine(LoadArrowPos.ArrowPosXOrigins, LoadArrowPos.PrevArrowPosYOrigins, LoadArrowPos.arrowPosx1, LoadArrowPos.PrevarrowPosy1, TFT_BLACK);
    tft.drawLine(LoadArrowPos.ArrowPosXOrigins, LoadArrowPos.ArrowPosYOrigins, LoadArrowPos.arrowPosx0, LoadArrowPos.arrowPosy0, TFT_BLACK);
    tft.drawLine(LoadArrowPos.ArrowPosXOrigins, LoadArrowPos.ArrowPosYOrigins, LoadArrowPos.arrowPosx1, LoadArrowPos.arrowPosy1, TFT_BLACK);
    tft.drawLine(LoadArrowPos.PrevArrowPosXOrigins, LoadArrowPos.ArrowPosYOrigins, LoadArrowPos.PrevarrowPosx0, LoadArrowPos.arrowPosy0, TFT_BLACK);
    tft.drawLine(LoadArrowPos.PrevArrowPosXOrigins, LoadArrowPos.ArrowPosYOrigins, LoadArrowPos.PrevarrowPosx1, LoadArrowPos.arrowPosy1, TFT_BLACK);
    tft.drawLine(LoadArrowPos.ArrowPosXOrigins, LoadArrowPos.PrevArrowPosYOrigins, LoadArrowPos.arrowPosx0, LoadArrowPos.PrevarrowPosy0, TFT_BLACK);
    tft.drawLine(LoadArrowPos.ArrowPosXOrigins, LoadArrowPos.PrevArrowPosYOrigins, LoadArrowPos.arrowPosx1, LoadArrowPos.PrevarrowPosy1, TFT_BLACK);
  }

  if (this->SysMeasurements.ChargePwr >= 10) {

    this->DrawChargeLine(Green);

    if ((millis() - this->ChargeAnimatetimer) >= 500) {
      this->ChargeAnimate = !this->ChargeAnimate;
      this->BatChargeTask();
      if (this->ChargeAnimate)
        tft.drawRoundRect(5, 30, 60, 83, 20, Green); //smps
      else
        tft.drawRoundRect(5, 30, 60, 83, 20, TFT_BLACK);
      this->ChargeAnimatetimer = millis();
    } //
  }//

  else {
    tft.drawRoundRect(5, 30, 60, 83, 20, TFT_BLACK);
    this->ChargeAnimatetimer = millis();
    this->ChargeLine(TFT_BLACK);
    tft.drawLine(ChargeArrowPos.PrevArrowPosXOrigins, ChargeArrowPos.ArrowPosYOrigins, ChargeArrowPos.PrevarrowPosx0, ChargeArrowPos.arrowPosy0, TFT_BLACK);
    tft.drawLine(ChargeArrowPos.PrevArrowPosXOrigins, ChargeArrowPos.ArrowPosYOrigins, ChargeArrowPos.PrevarrowPosx1, ChargeArrowPos.arrowPosy1, TFT_BLACK);
    tft.drawLine(ChargeArrowPos.ArrowPosXOrigins, ChargeArrowPos.ArrowPosYOrigins, ChargeArrowPos.arrowPosx0, ChargeArrowPos.arrowPosy0, TFT_BLACK);
    tft.drawLine(ChargeArrowPos.ArrowPosXOrigins, ChargeArrowPos.ArrowPosYOrigins, ChargeArrowPos.arrowPosx1, ChargeArrowPos.arrowPosy1, TFT_BLACK);
    tft.drawLine(ChargeArrowPos.ArrowPosXOrigins, ChargeArrowPos.PrevArrowPosYOrigins, ChargeArrowPos.arrowPosx0, ChargeArrowPos.PrevarrowPosy0, TFT_BLACK);
    tft.drawLine(ChargeArrowPos.ArrowPosXOrigins, ChargeArrowPos.PrevArrowPosYOrigins, ChargeArrowPos.arrowPosx1, ChargeArrowPos.PrevarrowPosy1, TFT_BLACK);
  }
}// 

void ScreenTask::DrawLoadLine(decltype(TFT_WHITE) color) {

  this->LoadLine(color);

  if (color != TFT_BLACK) {

    if ((millis() - this->LoadArrowTimer) >= 10) {

      if (LoadArrowPos.PrevArrowPosXOrigins != -1 && !this->LoadarrowSwitch) {
        tft.drawLine(LoadArrowPos.PrevArrowPosXOrigins, LoadArrowPos.ArrowPosYOrigins, LoadArrowPos.PrevarrowPosx0, LoadArrowPos.arrowPosy0, TFT_BLACK);
        tft.drawLine(LoadArrowPos.PrevArrowPosXOrigins, LoadArrowPos.ArrowPosYOrigins, LoadArrowPos.PrevarrowPosx1, LoadArrowPos.arrowPosy1, TFT_BLACK);
      }
      else if (this->LoadarrowSwitch) {
        tft.drawLine(LoadArrowPos.ArrowPosXOrigins, LoadArrowPos.PrevArrowPosYOrigins, LoadArrowPos.arrowPosx0, LoadArrowPos.PrevarrowPosy0, TFT_BLACK);
        tft.drawLine(LoadArrowPos.ArrowPosXOrigins, LoadArrowPos.PrevArrowPosYOrigins, LoadArrowPos.arrowPosx1, LoadArrowPos.PrevarrowPosy1, TFT_BLACK);
      }

      tft.drawLine(LoadArrowPos.ArrowPosXOrigins, LoadArrowPos.ArrowPosYOrigins, LoadArrowPos.arrowPosx0, LoadArrowPos.arrowPosy0, color);
      tft.drawLine(LoadArrowPos.ArrowPosXOrigins, LoadArrowPos.ArrowPosYOrigins, LoadArrowPos.arrowPosx1, LoadArrowPos.arrowPosy1, color);

      LoadArrowPos.PrevarrowPosx0 = LoadArrowPos.arrowPosx0;
      LoadArrowPos.PrevarrowPosx1 = LoadArrowPos.arrowPosx1;
      LoadArrowPos.PrevArrowPosXOrigins = LoadArrowPos.ArrowPosXOrigins;

      if (LoadArrowPos.ArrowPosXOrigins == 280) {

        this->LoadarrowSwitch = true;
        tft.drawLine(LoadArrowPos.ArrowPosXOrigins, LoadArrowPos.ArrowPosYOrigins, LoadArrowPos.arrowPosx0, LoadArrowPos.arrowPosy0, TFT_BLACK);
        tft.drawLine(LoadArrowPos.ArrowPosXOrigins, LoadArrowPos.ArrowPosYOrigins, LoadArrowPos.arrowPosx1, LoadArrowPos.arrowPosy1, TFT_BLACK);

        LoadArrowPos.ArrowPosXOrigins = 285;
        LoadArrowPos.arrowPosx0 = 279;
        LoadArrowPos.arrowPosx1 = 291;
        LoadArrowPos.ArrowPosYOrigins = 136;
        LoadArrowPos.arrowPosy0 = 142;
        LoadArrowPos.arrowPosy1 = 142;
      }
      if (!this->LoadarrowSwitch) {
        LoadArrowPos.ArrowPosXOrigins += 1;
        LoadArrowPos.arrowPosx0 += 1;
        LoadArrowPos.arrowPosx1 += 1;
      }

      if (this->LoadarrowSwitch) {
        LoadArrowPos.PrevArrowPosYOrigins = LoadArrowPos.ArrowPosYOrigins;
        LoadArrowPos.PrevarrowPosy0 = LoadArrowPos.arrowPosy0;
        LoadArrowPos.PrevarrowPosy1 = LoadArrowPos.arrowPosy1;
        LoadArrowPos.ArrowPosYOrigins -= 1;
        LoadArrowPos.arrowPosy0 -= 1;
        LoadArrowPos.arrowPosy1 -= 1;

        if (LoadArrowPos.ArrowPosYOrigins < 112) {

          tft.drawLine(LoadArrowPos.ArrowPosXOrigins, LoadArrowPos.PrevArrowPosYOrigins, LoadArrowPos.arrowPosx0, LoadArrowPos.PrevarrowPosy0, TFT_BLACK);
          tft.drawLine(LoadArrowPos.ArrowPosXOrigins, LoadArrowPos.PrevArrowPosYOrigins, LoadArrowPos.arrowPosx1, LoadArrowPos.PrevarrowPosy1, TFT_BLACK);

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

void ScreenTask::DrawChargeLine(decltype(TFT_GREEN) color) {

  this->ChargeLine(color);

  if (color != TFT_BLACK) {

    if ((millis() - this->ChargeArrowTimer) >= 40) {

      if (ChargeArrowPos.PrevArrowPosYOrigins != -1 && !this->ChargearrowSwitch) {
        tft.drawLine(ChargeArrowPos.ArrowPosXOrigins, ChargeArrowPos.PrevArrowPosYOrigins, ChargeArrowPos.arrowPosx0, ChargeArrowPos.PrevarrowPosy0, TFT_BLACK);
        tft.drawLine(ChargeArrowPos.ArrowPosXOrigins, ChargeArrowPos.PrevArrowPosYOrigins, ChargeArrowPos.arrowPosx1, ChargeArrowPos.PrevarrowPosy1, TFT_BLACK);
      }
      else if (this->ChargearrowSwitch) {
        tft.drawLine(ChargeArrowPos.PrevArrowPosXOrigins, ChargeArrowPos.ArrowPosYOrigins, ChargeArrowPos.PrevarrowPosx0, ChargeArrowPos.arrowPosy0, TFT_BLACK);
        tft.drawLine(ChargeArrowPos.PrevArrowPosXOrigins, ChargeArrowPos.ArrowPosYOrigins, ChargeArrowPos.PrevarrowPosx1, ChargeArrowPos.arrowPosy1, TFT_BLACK);
      }

      tft.drawLine(ChargeArrowPos.ArrowPosXOrigins, ChargeArrowPos.ArrowPosYOrigins, ChargeArrowPos.arrowPosx0, ChargeArrowPos.arrowPosy0, color);
      tft.drawLine(ChargeArrowPos.ArrowPosXOrigins, ChargeArrowPos.ArrowPosYOrigins, ChargeArrowPos.arrowPosx1, ChargeArrowPos.arrowPosy1, color);

      ChargeArrowPos.PrevarrowPosy0 = ChargeArrowPos.arrowPosy0;
      ChargeArrowPos.PrevarrowPosy1 = ChargeArrowPos.arrowPosy1;
      ChargeArrowPos.PrevArrowPosYOrigins = ChargeArrowPos.ArrowPosYOrigins;

      if (ChargeArrowPos.ArrowPosYOrigins == 142) {

        this->ChargearrowSwitch = true;
        tft.drawLine(ChargeArrowPos.ArrowPosXOrigins, ChargeArrowPos.ArrowPosYOrigins, ChargeArrowPos.arrowPosx0, ChargeArrowPos.arrowPosy0, TFT_BLACK);
        tft.drawLine(ChargeArrowPos.ArrowPosXOrigins, ChargeArrowPos.ArrowPosYOrigins, ChargeArrowPos.arrowPosx1, ChargeArrowPos.arrowPosy1, TFT_BLACK);

        ChargeArrowPos.ArrowPosXOrigins = 46;
        ChargeArrowPos.arrowPosx0 = 40;
        ChargeArrowPos.arrowPosx1 = 40;
        ChargeArrowPos.ArrowPosYOrigins = 148;
        ChargeArrowPos.arrowPosy0 = 142;
        ChargeArrowPos.arrowPosy1 = 154;
      }

      if (!this->ChargearrowSwitch) {
        ChargeArrowPos.ArrowPosYOrigins += 1;
        ChargeArrowPos.arrowPosy0 += 1;
        ChargeArrowPos.arrowPosy1 += 1;
      }

      if (this->ChargearrowSwitch) {
        ChargeArrowPos.PrevArrowPosXOrigins = ChargeArrowPos.ArrowPosXOrigins;
        ChargeArrowPos.PrevarrowPosx0 = ChargeArrowPos.arrowPosx0;
        ChargeArrowPos.PrevarrowPosx1 = ChargeArrowPos.arrowPosx1;
        ChargeArrowPos.ArrowPosXOrigins += 1;
        ChargeArrowPos.arrowPosx0 += 1;
        ChargeArrowPos.arrowPosx1 += 1;

        if (ChargeArrowPos.ArrowPosXOrigins > 110) {

          tft.drawLine(ChargeArrowPos.PrevArrowPosXOrigins, ChargeArrowPos.ArrowPosYOrigins, ChargeArrowPos.PrevarrowPosx0, ChargeArrowPos.arrowPosy0, TFT_BLACK);
          tft.drawLine(ChargeArrowPos.PrevArrowPosXOrigins, ChargeArrowPos.ArrowPosYOrigins, ChargeArrowPos.PrevarrowPosx1, ChargeArrowPos.arrowPosy1, TFT_BLACK);

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

void ScreenTask::BatteryModeTask() {

  if (this->SysMeasurements.screenState == SystemState::Normal) {

  if((millis() - this->BatRefreshTimer) >= 500) 
  {
    this->BatNormBit.bit1 = (this->SysMeasurements.BatteryPercentage >= 76 && this->SysMeasurements.BatteryPercentage <= 100) ? true : false;
    this->BatNormBit.bit2 = (this->SysMeasurements.BatteryPercentage >= 56 && this->SysMeasurements.BatteryPercentage <= 75) ? true : false;
    this->BatNormBit.bit3 = (this->SysMeasurements.BatteryPercentage >= 36 && this->SysMeasurements.BatteryPercentage <= 55) ? true : false;
    this->BatNormBit.bit4 = (this->SysMeasurements.BatteryPercentage >= 16 && this->SysMeasurements.BatteryPercentage <= 35) ? true : false;
    this->BatNormBit.bit5 = (this->SysMeasurements.BatteryPercentage >= 1 && this->SysMeasurements.BatteryPercentage <= 15) ? true : false;

    if (this->BatNormBit.bit1 && this->BatNormPrevState != PrevStateBits::bit1_state) {
      this->BatNormPrevState = PrevStateBits::bit1_state;
      this->FillBat(White, true);
      this->BatteryBits.Flags = 0x1f;
      this->FillBat(Green);
    }//

    else if (this->BatNormBit.bit2 && this->BatNormPrevState != PrevStateBits::bit2_state) {
      this->BatNormPrevState = PrevStateBits::bit2_state;
      this->FillBat(White, true);
      this->BatteryBits.Flags = 0x1E;
      this->FillBat(Green);
    }

    else if (this->BatNormBit.bit3 && this->BatNormPrevState != PrevStateBits::bit3_state) {
      this->BatNormPrevState = PrevStateBits::bit3_state;
      this->FillBat(White, true);
      this->BatteryBits.Flags = 0x1C;
      this->FillBat(Green);
    }

    else if (this->BatNormBit.bit4 && this->BatNormPrevState != PrevStateBits::bit4_state) {
      this->BatNormPrevState = PrevStateBits::bit4_state;
      this->FillBat(White, true);
      this->BatteryBits.Flags = 0x18;
      this->FillBat(Green);
    }

    else if (this->BatNormBit.bit5 && this->BatNormPrevState != PrevStateBits::bit5_state) {
      this->BatNormPrevState = PrevStateBits::bit5_state;
      this->FillBat(White, true);
      this->BatteryBits.Flags = 0x10;
      this->FillBat(tft.color565(180, 0, 0));
    }

    this->BatRefreshTimer = millis();
  }//Milli

  }//Normal-State

  if (this->SysMeasurements.screenState != SystemState::Charging)
    this->ChargePrevState = PrevStateBits::clear_state;
}//

void ScreenTask::BatChargeTask() {

  if (this->SysMeasurements.screenState == SystemState::Charging) {

    if (this->ChargePrevState == PrevStateBits::clear_state) {
      this->BatteryBits.Flags = 0x1f;
      this->FillBat(White);
      this->ChargePrevState = PrevStateBits::Empty;
      if(this->SysMeasurements.SysMode == SystemMode::OFF)
        tft.drawBitmap(280, 210, power_bmp, 20, 21, tft.color565(60, 60, 60));
      else
      tft.drawBitmap(280, 210, power_bmp, 20, 21, tft.color565(46,170,113));
    }

    this->SegChargeBits.bit1 = (this->SysMeasurements.BatteryPercentage >= 76 && this->SysMeasurements.BatteryPercentage <= 100) ? true : false;
    this->SegChargeBits.bit2 = (this->SysMeasurements.BatteryPercentage >= 56 && this->SysMeasurements.BatteryPercentage <= 75) ? true : false;
    this->SegChargeBits.bit3 = (this->SysMeasurements.BatteryPercentage >= 36 && this->SysMeasurements.BatteryPercentage <= 55) ? true : false;
    this->SegChargeBits.bit4 = (this->SysMeasurements.BatteryPercentage >= 16 && this->SysMeasurements.BatteryPercentage <= 35) ? true : false;
    this->SegChargeBits.bit5 = (this->SysMeasurements.BatteryPercentage >= 1 && this->SysMeasurements.BatteryPercentage <= 15) ? true : false;

    if (this->SegChargeBits.bit5) {

      this->ChargeBits.bit4 = !this->ChargeBits.bit4;
      if (this->ChargeBits.bit4)
        tft.fillRoundRect(120 , 172, 80, 23, 7, Green);
      else
        tft.fillRoundRect(120 , 172, 80, 23, 7, White);

      if (this->ChargePrevState != PrevStateBits::bit5_state) {
        this->ChargePrevState = PrevStateBits::bit5_state;
        this->BatteryBits.Flags = 0x10;
        this->FillBat(Green);
      }//
    }//

    else if (this->SegChargeBits.bit4) {

      this->ChargeBits.bit3 = !this->ChargeBits.bit3;
      if (this->ChargeBits.bit3)
        tft.fillRoundRect(120 , 147, 80, 23, 7, Green);
      else
        tft.fillRoundRect(120 , 147, 80, 23, 7, White);

      if (this->ChargePrevState != PrevStateBits::bit4_state) {
        this->ChargePrevState = PrevStateBits::bit4_state;
        this->BatteryBits.Flags = 0x18;
        this->FillBat(Green);
      }//
    }//

    else if (this->SegChargeBits.bit3) {

      this->ChargeBits.bit2 = !this->ChargeBits.bit2;
      if (this->ChargeBits.bit2)
        tft.fillRoundRect(120 , 122, 80, 23, 7, Green);
      else
        tft.fillRoundRect(120 , 122, 80, 23, 7, White);

      if (this->ChargePrevState != PrevStateBits::bit3_state) {
        this->ChargePrevState = PrevStateBits::bit3_state;
        this->BatteryBits.Flags = 0x1C;
        this->FillBat(Green);
      }//
    }//

    else if (this->SegChargeBits.bit2) {

      this->ChargeBits.bit1 = !this->ChargeBits.bit1;
      if (this->ChargeBits.bit1)
        tft.fillRoundRect(120 , 97, 80, 23, 7, Green);
      else
        tft.fillRoundRect(120 , 97, 80, 23, 7, White);

      if (this->ChargePrevState != PrevStateBits::bit2_state) {
        this->ChargePrevState = PrevStateBits::bit2_state;
        this->BatteryBits.Flags = 0x1E;
        this->FillBat(Green);
      }//
    }//

    else if (this->SegChargeBits.bit1) {

      if (this->ChargePrevState != PrevStateBits::bit1_state) {
        this->ChargePrevState = PrevStateBits::bit1_state;
        this->BatteryBits.Flags = 0x1f;
        this->FillBat(Green);
      }//
    }//
  }//Charge-State

}//

void ScreenTask::OperationalTask() {
  this->SysMeasurements.SystemTask();
  this->PowerflowGraph();
  this->BatteryModeTask();
  this->DisplayData();
  this->PowerOnCommand();

  if (this->SysMeasurements.BatteryVoltage < this->SysMeasurements.lowBattery &&
    this->SysMeasurements.BatteryPercentage == 0 && 
    this->SysMeasurements.screenState != SystemState::Charging)
  {
    digitalWrite(InverterCtrl, LOW);
    this->SysMeasurements.screenState = SystemState::BatteryLow;
    this->SysMeasurements.SysMode = SystemMode::OFF;
    tft.fillScreen(TFT_BLACK);
    BatteryLowMessage();
  }
}//

void ScreenTask::DisplayData()
{
  if((millis() - this->DataRefreshTimer) >= 400) 
  {
    if(this->prevCharge != this->SysMeasurements.ChargePwr)
    {
      tft.setCursor(13, 85);
      tft.fillRect(13, 85, 48, 20, Black); // clear charge
      tft.setCursor(13, 85); tft.setTextColor(Green);  tft.setTextSize(2);
      String chargePwr = String(this->SysMeasurements.ChargePwr)+"W";
      tft.print(chargePwr);
      this->prevCharge = this->SysMeasurements.ChargePwr;
    }

    if(this->PrevLoad!=this->SysMeasurements.LoadPwr)
    {    
      tft.setCursor(263, 85);
      tft.fillRect(263, 85,48,20,Black); // clear load
      tft.setCursor(263, 85); tft.setTextColor(White); tft.setTextSize(2);
      String loadPwr = String(this->SysMeasurements.LoadPwr)+"W";
      tft.print(loadPwr);
      this->PrevLoad = this->SysMeasurements.LoadPwr;
    }

    this->DataRefreshTimer = millis();

    if(this->SysMeasurements.InternalTemp >=40)
        digitalWrite(InverterFanCtrl, HIGH);
    else
        digitalWrite(InverterFanCtrl, LOW); 
  }//
  
}

void ScreenTask::PowerOnCommand()
{

  if(this->SysMeasurements.screenState == SystemState::BatteryLow)
    {
      PowerMode(0);
      this->SysMeasurements.screenState = SystemState::Normal;
      tft.fillScreen(TFT_BLACK);
      this->DrawDefaultScreen();
      this->BatNormPrevState = PrevStateBits::clear_state;
      this->ChargePrevState = PrevStateBits::clear_state;
      return;
    }

  if (digitalRead( PowerButton) == HIGH)
  {
    delay(100);
    while(digitalRead(PowerButton) == HIGH){}

    if (this->SysMeasurements.SysMode == SystemMode::OFF)
    {
      PowerMode(1);
      digitalWrite(InverterCtrl, HIGH);
      this->SysMeasurements.SysMode = SystemMode::ON;
      tft.drawBitmap(280, 210, power_bmp, 20, 21, Green);
    }
    else
    {
      digitalWrite(InverterCtrl, LOW);
      PowerMode(0);
      this->IntScreen();
      tft.fillScreen(TFT_BLACK);
      PowerMode(0);
      this->SysMeasurements.SysMode = SystemMode::OFF;
      this->DrawDefaultScreen();
      this->BatNormPrevState = PrevStateBits::clear_state;
      this->ChargePrevState = PrevStateBits::clear_state;
      tft.drawBitmap(280, 210, power_bmp, 20, 21, tft.color565(60, 60, 60));
    }
  }

  if (digitalRead(FlashLightBtn) == HIGH)
  {
      delay(100);
      while(digitalRead(FlashLightBtn) == HIGH){}
    
    if(this->SysMeasurements.flashUpdate==true)
      {
        digitalWrite(FlashLightCtrl, LOW);
        this->SysMeasurements.flashUpdate = false;
      }
    else
      {
        digitalWrite(FlashLightCtrl, HIGH);
        this->SysMeasurements.flashUpdate = true;
      }
  }//

}

void ScreenTask::FillBat(decltype(TFT_GREEN) color, bool Override) {

  if (BatteryBits.States.bit1 || Override)
    tft.fillRoundRect(120 , 97, 80, 23, 7, color); //100%

  if (BatteryBits.States.bit1 || BatteryBits.States.bit2 || Override)
    tft.fillRoundRect(120 , 122, 80, 23, 7, color); //80%

  if (BatteryBits.States.bit1 || BatteryBits.States.bit2 || BatteryBits.States.bit3 || Override)
    tft.fillRoundRect(120 , 147, 80, 23, 7, color); //60%

  if (BatteryBits.States.bit1 || BatteryBits.States.bit2 || BatteryBits.States.bit3 ||
      BatteryBits.States.bit4 || Override)
    tft.fillRoundRect(120 , 172, 80, 23, 7, color); //40%

  if (BatteryBits.States.bit1 || BatteryBits.States.bit2 || BatteryBits.States.bit3 ||
      BatteryBits.States.bit4 || BatteryBits.States.bit5 || Override)
    tft.fillRoundRect(120 , 197, 80, 23, 7, color); //20%
}//
