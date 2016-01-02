//Figure-Eight animation for Neopixel Ring Bangle Bracelet
//By Dano Wall and Becky Stern for Adafruit Industries
#include <Adafruit_NeoPixel.h>
 
#define PIN 10 //marked D1 on GEMMA
 
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
// NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
// NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(52, PIN, NEO_GRB + NEO_KHZ800);
 
//Array of pixels in order of animation - 51 in total
// int sine[] = {4, 3, 2, 1, 0, 15, 14, 13, 12, 20, 21, 22, 23, 24, 25, 26, 27, 28, 36, 35, 34, 33, 32, 47, 46, 45, 44, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 48, 49, 50, 51, 52, 44, 43, 42, 41, 40, 39, 38, 37, 36, 28, 29, 30, 31, 16, 17, 18, 19, 20, 12, 11, 10, 9, 8, 7, 6, 5}; 

 
void setup() {
  strip.begin();
  strip.setBrightness(20); //adjust brightness here
  strip.show(); // Initialize all pixels to 'off'
}
 
void loop() {
  for (int i = 0; i < 52; i++) {
    strip.setPixelColor(sine[i], strip.Color(i*3, 255-i*3, 255-i*3));
    strip.setPixelColor(52-sine[i], strip.Color(0, 0, 0));
    strip.show();
    delay(50);
  }

}
