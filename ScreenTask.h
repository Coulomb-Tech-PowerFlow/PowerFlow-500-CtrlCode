#pragma once

#include "SPI.h"
#include "TFT_eSPI.h"
// #include "Lib/Fontslib.h"

#define PowerMode(x)  digitalWrite(TFT_BL, x)

namespace ScreenCtrl{

class ScreenTask{

public:

ScreenTask(){}

void IntScreen();
void WelcomeMessage();
void DrawDefaultScreen();

private:
TFT_eSPI tft = TFT_eSPI();
};

}
