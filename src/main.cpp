//------------------------------------------------------------------------
// LIBRARIES
//------------------------------------------------------------------------
#include <Arduino.h>                // Necessary library to use our board
#include <systemLib.h>              // Global library with pin definition

#include "capacitive_buttons.h"     // Header file to use the buttons
#include "leds_ws2812.h"            // Header file to use the leds
#include "dfplayer.h"               // Header file to use the DFplayer

#include "fsm.h"                    // Header file to use the FSM
#include "game.h"                   // Header file to play the game

//------------------------------------------------------------------------
// GLOBAL VARIABLE DEFINITIONS
//------------------------------------------------------------------------
// define global var ONCE
int button_position = -1;
int audio_folder = 0;
int audio_position = -1;
int button_mode = 0;
int currentState = -1;

//------------------------------------------------------------------------
// INITIALIZATION FUNCTIONS 
//------------------------------------------------------------------------
void setup() {

    Serial.begin(9600);               // Serial initialization

    buttons_setup();                  // Buttons initialization
    leds_setup();                     // Leds initialization
    dfplayer_setup();                 // DFplayer initialization
    
    fsm_setup();	                    // FSM initialization

}

//------------------------------------------------------------------------
// ACTION FUNCTIONS 
//------------------------------------------------------------------------
void loop() {
    // Read the buttons to see if any of them have been touched
    // and save the position of the button touched
    buttons_read(&button_position);

    // If the mode button is pressed
    if (button_position == 23) {
        button_mode = 1;
    } else {
        button_mode = 0;
    }
  
    fsm_update(&currentState);
    game_play(&currentState);

    delay(1000); // delay to debug, TO DELETE WHEN CODE IS RUNNING!!

    // Switch off the LEDs
    button_position = -1; 
  
}