#ifndef _GAME_H_
#define _GAME_H_

//------------------------------------------------------------------------
// CLARIFICATIONS
//------------------------------------------------------------------------

// MODE1:


// FOLDER 04: COLOURS
    // RED_SOUND,
    // GREEN_SOUND,
    // BLUE_SOUND,
    // YELLOW_SOUND


//------------------------------------------------------------------------
// LIBRARIES
//------------------------------------------------------------------------
#include <Arduino.h>
#include <systemLib.h>

#include "leds_ws2812.h"            // Header file to use the leds
#include "dfplayer.h"               // Header file to use the DFplayer

//------------------------------------------------------------------------
// INITIALIZATION FUNCTIONS 
//------------------------------------------------------------------------


//------------------------------------------------------------------------
// ACTION FUNCTIONS 
//------------------------------------------------------------------------
void game_play(int *currentState);
void game_MODE1();
void game_MODE2();
void game_MODE3();
void game_MODE4();

#endif /* _GAME_H_ */