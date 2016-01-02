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
 
//Array of pixels in order of animation - 70 in total
// int sine[] = {4, 3, 2, 1, 0, 15, 14, 13, 12, 20, 21, 22, 23, 24, 25, 26, 27, 28, 36, 35, 34, 33, 32, 47, 46, 45, 44, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 48, 49, 50, 51, 52, 44, 43, 42, 41, 40, 39, 38, 37, 36, 28, 29, 30, 31, 16, 17, 18, 19, 20, 12, 11, 10, 9, 8, 7, 6, 5}; 
int sine[] = {22,21,20,19,18,17,16,15,14,13,23,12,11,10,9,8,7,6,5,4,3,2,29,30,31,32,38,39,40,41,42,43,44,45,46,47,48,49,50,51,36,37,33,34,35,24,25,26,27,28,1,0}; 
 
void setup() {
  strip.begin();
  strip.setBrightness(10); //adjust brightness here
  strip.show(); // Initialize all pixels to 'off'
}
 
void loop() {
for(int i=0; i<52; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<10; j++){
    strip.setPixelColor(sine[(i + j + 1)%52], strip.Color(5+j*30, 250-j*20, 200 - j * 20)); //change RGB color value here
    }
  strip.show();
  delay(120);
 }
}

// hello
