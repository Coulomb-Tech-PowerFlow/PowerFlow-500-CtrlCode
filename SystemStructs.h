#pragma once

namespace ScreenCtrl{

union BatSegFields{
  
  struct{
    uint8_t bit1 : 1;
    uint8_t bit2 : 1;
    uint8_t bit3 : 1;
    uint8_t bit4 : 1;
    uint8_t bit5 : 1;
  }States;

  uint8_t Flags;
};

  enum class PrevStateBits
  {
    clear_state,
    bit1_state,
    bit2_state,
    bit3_state,
    bit4_state,
    bit5_state,
    bit6_state,
    Empty
  };

  struct StateBits
  {
    bool bit1{false},
        bit2{false},
        bit3{false},
        bit4{false},
        bit5{false};
    };

struct ArrowposDat {

  int arrowPosx0{0},
      PrevarrowPosx0{ -1},
      arrowPosx1{0},
      PrevarrowPosx1{ -1},
      ArrowPosXOrigins{0},
      PrevArrowPosXOrigins{ -1},
      ArrowPosYOrigins{0},
      PrevArrowPosYOrigins{ -1},
      arrowPosy0{0},
      PrevarrowPosy0{ -1},
      arrowPosy1{0},
      PrevarrowPosy1{ -1};

  ArrowposDat(int xp, int x0, int x1, int yp, int y0, int y1) {
    this->ArrowPosXOrigins = xp;
    this->arrowPosx0 = x0;
    this->arrowPosx1 = x1;
    this->ArrowPosYOrigins = yp;
    this->arrowPosy0 = y0;
    this->arrowPosy1 = y1;
  }
};

}//