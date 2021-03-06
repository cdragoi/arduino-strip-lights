#include <Adafruit_NeoPixel.h>

#define PIN 6


// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(20, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  strip.begin();
  strip.show();
}

void loop()
{
  headlight(strip.Color(255,255,200),0);
  
}
void headlight(uint32_t c, uint8_t)
{
  int i = 0;
  while (i < 20)
  {
    strip.setPixelColor(i, c);
    i++;
  }
  strip.setBrightness(255);
  strip.show();
 
}
