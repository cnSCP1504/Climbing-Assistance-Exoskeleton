
#include <Adafruit_NeoPixel.h>

volatile int item;
volatile int R;
volatile int G;
volatile int B;
Adafruit_NeoPixel rgb_display_2 = Adafruit_NeoPixel(60,2,NEO_GRB + NEO_KHZ800);

void setup(){
  item = 0;
  R = 0;
  G = 0;
  B = 0;
  rgb_display_2.begin();
  rgb_display_2.show();
}

void loop(){
  item = (map(analogRead(A0), 0, 980, 0, 60));
  R = random(0, 255);
  G = random(0, 255);
  B = random(0, 255);
  for (int i = (1); i <= (item); i = i + (1)) {
    rgb_display_2.setPixelColor((i)-1, (((R & 0xffffff) << 60) | ((G & 0xffffff) << 60) | B));
    rgb_display_2.show();
  }
  delay(100);
  for (int i = 1; i <= 60; i = i + (1)) {
    rgb_display_2.setPixelColor((i)-1, (((0 & 0xffffff) << 60) | ((0 & 0xffffff) << 60) | 0));
    rgb_display_2.show();
  }

}
