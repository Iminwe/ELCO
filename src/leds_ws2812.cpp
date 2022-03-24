#include "leds_ws2812.h"

//------------------------------------------------------------------------
// OBJECTS
//------------------------------------------------------------------------
// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(LEDS_NUMPIXELS, GPIO_LEDS, NEO_GRB + NEO_KHZ800);

//------------------------------------------------------------------------
// INITIALIZATION FUNCTIONS 
//------------------------------------------------------------------------
void leds_setup() {

  pixels.begin(); // Initialize NeoPixel strip object (REQUIRED)
  pixels.show();  // Initialize all pixels to 'off'

}

//------------------------------------------------------------------------
// ACTION FUNCTIONS 
//------------------------------------------------------------------------
void leds_write(int *button_position) {

  pixels.clear(); // Set all pixel colors to 'off'

  // Takes RGB brightness values: from 0,0,0 up to 255,255,255
  pixels.setPixelColor(*button_position, pixels.Color(0, 150, 0));
  // Send the updated pixel colors to the hardware.
  pixels.show();
  // Pause before next pass through loop
  delay(LEDS_DELAY); 

}