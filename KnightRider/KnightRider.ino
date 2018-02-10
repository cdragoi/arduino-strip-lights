#include <Adafruit_NeoPixel.h>

// SETUP YOUR OUTPUT PIN AND NUMBER OF PIXELS
#define PIN A5
#define NUM_PIXELS  20
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);
//#############################KITT#######################################################
void knightRider(uint16_t cycles, uint16_t speed, uint8_t width, uint32_t color) {
  uint32_t old_val[NUM_PIXELS]; // up to 256 lights!
  // Larson time baby!
  for(int i = 0; i < cycles; i++){
    for (int count = 1; count<NUM_PIXELS; count++) {
      strip.setPixelColor(count, color);
      old_val[count] = color;
      for(int x = count; x>0; x--) {
        old_val[x-1] = dimColor(old_val[x-1], width);
        strip.setPixelColor(x-1, old_val[x-1]); 
      }
      strip.show();
      delay(speed);
    }
    for (int count = NUM_PIXELS-1; count>=0; count--) {
      strip.setPixelColor(count, color);
      old_val[count] = color;
      for(int x = count; x<=NUM_PIXELS ;x++) {
        old_val[x-1] = dimColor(old_val[x-1], width);
        strip.setPixelColor(x+1, old_val[x+1]);
      }
      strip.show();
      delay(speed);
    }
  }
}
void clearStrip() {
  for( int i = 0; i<NUM_PIXELS; i++){
    strip.setPixelColor(i, 0x000000); strip.show();
  }
}
uint32_t dimColor(uint32_t color, uint8_t width) {
   return (((color&0xFF0000)/width)&0xFF0000) + (((color&0x00FF00)/width)&0x00FF00) + (((color&0x0000FF)/width)&0x0000FF);
}
uint32_t colorWheel(byte WheelPos) {
  byte state = WheelPos / 21;
}
//#############################KITT-END#######################################################
void setup() {
  strip.begin();
  clearStrip(); // Initialize all pixels to 'off'
  delay(1000);
}

void loop() {
  knightRider(3, 40, 4, 0xFF0000); // Cycles, Speed, Width, RGB Color (red)
    }
