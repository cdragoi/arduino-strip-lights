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
  hazard(strip.Color(255,40,0),200);
  hazard(strip.Color(0, 0, 0), 30);
  delay(600);
}
void hazard(uint32_t c, uint8_t wait)
{
  int i = 0;
  int j=19;
  while (i < 5)
  {
    strip.setPixelColor(i, c);
    i++;
  }
  while (j > 14)
  {
    strip.setPixelColor(j, c);
    j--;
  }
  strip.setBrightness(255);
  strip.show();
  delay(wait);
}
