l//Purpose: switches between 2 tones to demo the reflectiveness of tinfoil 
/* Based off of Strandtest example code modified Jan 2021 Doug Whitton
 *  This example is a barebones version of the Adafruit sample code
 *  It lights up a strip of 3 neopixels  
 *  The colour is random 
 *  Thee colorWipe method is called from the loop()
 *  strip is a variable name for an Adafruit_NeoPixel object
 *  
*/

#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6

// only uses 2 out of 3 LEDs
#define LED_COUNT 2

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// setup() function -- runs once at startup --------------------------------

void setup() {
  
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(80); // Set BRIGHTNESS to about 1/5 (max = 255)
}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {
  // set colours -- red + blue with RGB values    
  colorWipe(strip.Color(0,0,255), 1000);  
  colorWipe(strip.Color(255,0,0), 1000);   
}


//passes red + blue, then delays for 3 secs 
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                       //  Update strip to match
    delay(wait);  //pauses 
    }      
  //stays the same colour for 1 secs before wiping to the next colour
  delay(1000);

}

               
