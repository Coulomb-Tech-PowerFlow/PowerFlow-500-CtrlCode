#pragma once

#include "SPI.h"
#include "TFT_eSPI.h"

#define PowerMode(x)  digitalWrite(TFT_BL, x)

namespace ScreenCtrl{

class ScreenTask{

public:

ScreenTask(){

}

void IntScreen();
void WelcomeMessage();

private:
TFT_eSPI tft = TFT_eSPI();
};

}
