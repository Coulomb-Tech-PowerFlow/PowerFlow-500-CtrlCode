#pragma once

const unsigned char caution_bmp[] {
  0x00, 0x00, 0x18, 0x00, 0x00,
  0x00, 0x00, 0x3c, 0x00, 0x00,
  0x00, 0x00, 0x3c, 0x00, 0x00,
  0x00, 0x00, 0x7e, 0x00, 0x00,
  0x00, 0x00, 0x7e, 0x00, 0x00,
  0x00, 0x00, 0xff, 0x00, 0x00,
  0x00, 0x00, 0xff, 0x00, 0x00,
  0x00, 0x01, 0xff, 0x80, 0x00,
  0x00, 0x01, 0xff, 0x80, 0x00,
  0x00, 0x03, 0xff, 0xc0, 0x00,
  0x00, 0x03, 0xff, 0xc0, 0x00,
  0x00, 0x07, 0xff, 0xe0, 0x00,
  0x00, 0x07, 0xc1, 0xe0, 0x00,
  0x00, 0x0f, 0xc3, 0xf0, 0x00,
  0x00, 0x0f, 0xc3, 0xf0, 0x00,
  0x00, 0x1f, 0xc3, 0xf8, 0x00,
  0x00, 0x1f, 0xc3, 0xf8, 0x00,
  0x00, 0x3f, 0xc3, 0xfc, 0x00,
  0x00, 0x3f, 0xc3, 0xfc, 0x00,
  0x00, 0x7f, 0xc3, 0xfe, 0x00,
  0x00, 0x7f, 0xc3, 0xfe, 0x00,
  0x00, 0xff, 0xc3, 0xff, 0x00,
  0x00, 0xff, 0xc3, 0xff, 0x00,
  0x01, 0xff, 0xc3, 0xff, 0x80,
  0x01, 0xff, 0xc3, 0xff, 0x80,
  0x03, 0xff, 0xc3, 0xff, 0xc0,
  0x03, 0xff, 0xc3, 0xff, 0xc0,
  0x07, 0xff, 0xc3, 0xff, 0xe0,
  0x07, 0xff, 0xf3, 0xff, 0xe0,
  0x0f, 0xff, 0xff, 0xff, 0xf0,
  0x0f, 0xff, 0xc7, 0xff, 0xf8,
  0x1f, 0xff, 0x83, 0xff, 0xf8,
  0x3f, 0xff, 0x81, 0xff, 0xfc,
  0x3f, 0xff, 0x83, 0xff, 0xfc,
  0x3f, 0xff, 0xc3, 0xff, 0xfc,
  0x7f, 0xff, 0xe7, 0xff, 0xfe,
  0x7f, 0xff, 0xff, 0xff, 0xfe,
  0xff, 0xff, 0xff, 0xff, 0xfe,
  0x7f, 0xff, 0xff, 0xff, 0xfe,
  0x7f, 0xff, 0xff, 0xff, 0xfe
};

const unsigned char power_bmp[] = {
  0x00, 0xf0, 0x00,
  0x00, 0xf0, 0x00,
  0x00, 0xf0, 0x00,
  0x10, 0xf0, 0x00,
  0x38, 0xf0, 0x80,
  0x78, 0xf1, 0xe0,
  0x78, 0xf1, 0xe0,
  0xf0, 0xf0, 0xf0,
  0xf0, 0xf0, 0xf0,
  0xf0, 0xf0, 0xf0,
  0xe0, 0xf0, 0x70,
  0xe0, 0xf0, 0x70,
  0xe0, 0x00, 0x70,
  0xf0, 0x00, 0x70,
  0xf0, 0x00, 0xf0,
  0x78, 0x01, 0xe0,
  0x78, 0x03, 0xe0,
  0x3e, 0x0f, 0xc0,
  0x1f, 0xff, 0x80,
  0x0f, 0xff, 0x00,
  0x03, 0xfc, 0x00
};

const unsigned char adapter_bmp[] = {
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xc0, 0x00,
  0x00, 0x00, 0x01, 0xe0, 0x00,
  0x00, 0x00, 0x03, 0xf0, 0x00,
  0x00, 0x00, 0x07, 0xe0, 0x00,
  0x00, 0x00, 0x0f, 0xc0, 0x00,
  0x00, 0x18, 0x1f, 0x80, 0x00,
  0x00, 0x3c, 0x3f, 0x00, 0x00,
  0x00, 0x7e, 0x7e, 0x00, 0x00,
  0x00, 0x7f, 0xfc, 0x00, 0x00,
  0x00, 0x3f, 0xf8, 0x00, 0x00,
  0x00, 0x1f, 0xf0, 0x00, 0x00,
  0x00, 0x2f, 0xe0, 0x00, 0x18,
  0x00, 0x37, 0xf0, 0x00, 0x3c,
  0x00, 0x7b, 0xf8, 0x00, 0x7e,
  0x00, 0xfd, 0xfc, 0x00, 0xfc,
  0x01, 0xfe, 0xfe, 0x01, 0xf8,
  0x03, 0xff, 0x7f, 0x03, 0xf0,
  0x07, 0xff, 0xbf, 0x87, 0xe0,
  0x0f, 0xff, 0xdf, 0xcf, 0xc0,
  0x1f, 0xff, 0xef, 0xff, 0x80,
  0x1f, 0xff, 0xf7, 0xff, 0x00,
  0x3f, 0xfb, 0xfb, 0xfe, 0x00,
  0x3f, 0xfb, 0xfd, 0xfc, 0x00,
  0x3f, 0xf1, 0xfe, 0xfe, 0x00,
  0x1f, 0xf8, 0x7f, 0x7f, 0x00,
  0x0f, 0xfc, 0xff, 0xbf, 0x80,
  0x07, 0xfc, 0xff, 0xdf, 0xc0,
  0x03, 0xfd, 0xff, 0xef, 0x80,
  0x01, 0xfd, 0xff, 0xf7, 0x00,
  0x06, 0xff, 0xff, 0x82, 0x00,
  0x0f, 0x7f, 0xff, 0x00, 0x00,
  0x1f, 0xbf, 0xfe, 0x00, 0x00,
  0x3f, 0xdf, 0xfc, 0x00, 0x00,
  0x7f, 0x8f, 0xf8, 0x00, 0x00,
  0x3f, 0x07, 0xf0, 0x00, 0x00,
  0x1e, 0x03, 0xe0, 0x00, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char socket_bmp PROGMEM[] = {
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xf3, 0xff, 0x9f, 0xfc,
  0x3f, 0xf3, 0xff, 0x9f, 0xfc,
  0x3f, 0xd3, 0xff, 0x97, 0xfc,
  0x3f, 0x83, 0xff, 0x83, 0xfc,
  0x3f, 0xc3, 0xff, 0x83, 0xfc,
  0x3f, 0xf3, 0xff, 0x9f, 0xfc,
  0x3f, 0xf3, 0xff, 0x9f, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xe7, 0xff, 0xfc,
  0x3f, 0xff, 0xc3, 0xff, 0xfc,
  0x3f, 0xff, 0x83, 0xff, 0xfc,
  0x3f, 0xff, 0x83, 0xff, 0xfc,
  0x3f, 0xff, 0x83, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x3f, 0xff, 0xff, 0xff, 0xfc,
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00
};


const unsigned char plogo_bmp PROGMEM[] = {
  0x00, 0x0f, 0xff, 0xff, 0xff, 0x80, 0x00,
  0x00, 0x1f, 0xff, 0xff, 0xff, 0xe0, 0x00,
  0x00, 0x3f, 0xff, 0xff, 0xff, 0xf8, 0x00,
  0x00, 0x3f, 0xff, 0xff, 0xff, 0xfc, 0x00,
  0x00, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x00,
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x00,
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x80,
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x80,
  0x00, 0x7f, 0xff, 0xff, 0xfd, 0xff, 0x80,
  0x00, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xc0,
  0x00, 0xff, 0xf8, 0x00, 0x01, 0xff, 0xc0,
  0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xc0,
  0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xc0,
  0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xc0,
  0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xc0,
  0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xc0,
  0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xc0,
  0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xc0,
  0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xc0,
  0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80,
  0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,
  0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
  0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
  0x07, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00,
  0x07, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00,
  0x0f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00,
  0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00,
  0x1f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00,
  0x1f, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00,
  0x1f, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00,
  0x1f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00,
  0x3f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00,
  0x3f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00,
  0x3f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00,
  0x3f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x7f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x7f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00
};
