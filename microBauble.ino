#include "TinyMAX7219.h"
TinyMAX7219<3, 0, 2> disp;  // CS, MOSI, SCK

void setup() {
  disp.begin();
  disp.setBright(5);
}

void loop() {
  snow();
  delay(200);
}

void snow() {
  for (byte i = 0; i < 7; i++) {
    disp.buf[7 - i] = disp.buf[7 - i - 1];
  }
  disp.buf[0] = bit(random(0, 8));
  disp.update();
}