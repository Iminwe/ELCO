#include <Arduino.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define BUTTON_PIN 34

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN_LEDS    15 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 5 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN_LEDS, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

boolean oldState = LOW;
int pixel_position = -1;

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<pixels.numPixels(); i++) { // For each pixel in strip...
    pixels.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    pixels.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void setup() {
  Serial.begin(9600);
  
  pinMode(BUTTON_PIN, INPUT);
  
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();  // Initialize all pixels to 'off'

}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  
  // Get current button state.
  boolean newState = digitalRead(BUTTON_PIN);

  Serial.println(digitalRead(BUTTON_PIN));

  // Check if state changed from high to low (button press).
  if((newState == HIGH) && (oldState == LOW)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState = digitalRead(BUTTON_PIN);
    if(newState == HIGH) {      // Yes, still low
      if(++pixel_position > 4) pixel_position = 0; // Advance to next mode, wrap around after #4
        switch(pixel_position) {           // Start the new animation...
          case -1:
            colorWipe(pixels.Color(  0,   0,   0), 50);    // Black/off
            break;
          case 0:
            pixels.setPixelColor(pixel_position, pixels.Color(0, 150, 0)); // Takes RGB values, from 0,0,0 up to 255,255,255
            pixels.show();   // Send the updated pixel colors to the hardware.
            delay(DELAYVAL); // Pause before next pass through loop
            break;
          case 1:
            pixels.setPixelColor(pixel_position, pixels.Color(0, 150, 0)); // Takes RGB values, from 0,0,0 up to 255,255,255
            pixels.show();   // Send the updated pixel colors to the hardware.
            delay(DELAYVAL); // Pause before next pass through loop
            break;
          case 2:
            pixels.setPixelColor(pixel_position, pixels.Color(0, 150, 0)); // Takes RGB values, from 0,0,0 up to 255,255,255
            pixels.show();   // Send the updated pixel colors to the hardware.
            delay(DELAYVAL); // Pause before next pass through loop
            break;
          case 3:
            pixels.setPixelColor(pixel_position, pixels.Color(0, 150, 0)); // Takes RGB values, from 0,0,0 up to 255,255,255
            pixels.show();   // Send the updated pixel colors to the hardware.
            delay(DELAYVAL); // Pause before next pass through loop
            break;
          case 4:
            pixels.setPixelColor(pixel_position, pixels.Color(0, 150, 0)); // Takes RGB values, from 0,0,0 up to 255,255,255
            pixels.show();   // Send the updated pixel colors to the hardware.
            delay(DELAYVAL); // Pause before next pass through loop
            break;
        }          
      }
    }
    
  // Set the last-read button state to the old state.
  oldState = newState;
}