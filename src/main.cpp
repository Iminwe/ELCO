//------------------------------------------------------------------------
// LIBRARIES
//------------------------------------------------------------------------
#include <Arduino.h>                // Necessary library to use our board
#include <systemLib.h>              // Global library with pin definition

#include "capacitive_buttons.h"     // Header file to use the buttons
#include "leds_ws2812.h"            // Header file to use the leds
#include "dfplayer.h"               // Header file to use the DFplayer

//------------------------------------------------------------------------
// GLOBAL VARIABLE DEFINITIONS
//------------------------------------------------------------------------
// define global var ONCE
int button_position = -1;

//------------------------------------------------------------------------
// INITIALIZATION FUNCTIONS 
//------------------------------------------------------------------------
void setup() {
  
  Serial.begin(9600);               // Serial initialization
  
  buttons_setup();                  // Buttons initialization
  leds_setup();                     // Leds initialization
  dfplayer_setup();                 // DFplayer initialization

}

//------------------------------------------------------------------------
// ACTION FUNCTIONS 
//------------------------------------------------------------------------
void loop() {

  // Read the buttons to see if any of them have been touched
  // and save the position of the button touched
  buttons_read(&button_position);

  // Turn on the led in the "button_position"
  leds_write(&button_position);

  // Play the audio in the "button_position" of SD card
  dfplayer_play(&button_position);

  delay(1000); // delay to debug, TO DELETE WHEN CODE IS RUNNING!!

  // Switch off the LEDs
  button_position = -1; 
  
}