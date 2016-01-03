//Figure-Eight animation for Neopixel Ring Bangle Bracelet
//By Dano Wall and Becky Stern for Adafruit Industries
#include <Adafruit_NeoPixel.h>

 
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
// NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
// NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(110, 10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel single = Adafruit_NeoPixel(1, 8, NEO_GRB + NEO_KHZ800);


//Array of pixels in order of animation - 52 in total
// int sine[] = {4, 3, 2, 1, 0, 15, 14, 13, 12, 20, 21, 22, 23, 24, 25, 26, 27, 28, 36, 35, 34, 33, 32, 47, 46, 45, 44, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 48, 49, 50, 51, 52, 44, 43, 42, 41, 40, 39, 38, 37, 36, 28, 29, 30, 31, 16, 17, 18, 19, 20, 12, 11, 10, 9, 8, 7, 6, 5}; 
int sine[] = {23,12,11,13,10,14,9,15,8,16,17,7,18,6,19,20,5,21,4,22,0,3,1,2,27,26,28,25,29,24,30,35,31,34,33,32,37,36,38,51,39,50,40,49,41,48,42,47,43,46,44,45,}; 
 
void setup() {
  strip.begin();
  strip.show();
    
  single.begin();
  single.show();
  
  single.setBrightness(15);
  strip.setBrightness(10); 
}
 
void loop() {
for(int i=0; i<44; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
  
  // single
  if (i > 10 && i < 20) {
      single.setPixelColor(0, single.Color(110+i*15, 25-i*40, 250-i*25));    
  } else {
      single.setPixelColor(0, single.Color(0,0,0));
  }

  // rings
  for (int j=0; j<8; j++){
    int r = 110+j*15;
    int g = 25+j*40; 
    int b = 250-j*25;

    strip.setPixelColor(sine[(i + j + 1)%52], strip.Color(r, g, b)); //change RGB color value here
  }
  single.show(); 
  strip.show();
  delay(20);
  
 }

 
 
 for(int i=51; i>=0; i--) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
  
  // single
  
  if (i > 30 && i < 40) {
      single.setPixelColor(0, single.Color(110+i*15, 25-i*40, 250-i*25));    
  } else {
      single.setPixelColor(0, single.Color(0,0,0));
  }
  

  // rings
  for (int j=8; j>=0; j--){
    int r = 110+j*15;
    int g = 25+j*40; 
    int b = 250-j*25;

    strip.setPixelColor(sine[(i - j - 1)%52], strip.Color(r, g, b)); //change RGB color value here

  }
  single.show(); 
  strip.show();
  delay(20);
  
  
 }

 
}
 
// hello
