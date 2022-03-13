#include "leds_ws2812.h"

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels (LEDS_NUMPIXELS, GPIO_LEDS, NEO_GRB + NEO_KHZ800);

void leds_setup () {
  
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();  // Initialize all pixels to 'off'

}

void leds_write (int *button_position) {

    pixels.clear(); // Set all pixel colors to 'off'

    //r  Red brightness,    0 = minimum (off), 255 = maximum.
    //g  Green brightness,  0 = minimum (off), 255 = maximum.
    //b  Blue brightness,   0 = minimum (off), 255 = maximum.
    pixels.setPixelColor(*button_position, pixels.Color(0, 150, 0)); // Takes RGB values, from 0,0,0 up to 255,255,255
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(LEDS_DELAY); // Pause before next pass through loop

}