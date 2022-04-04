#ifndef _GAME_H_
#define _GAME_H_

//------------------------------------------------------------------------
// CLARIFICATIONS
//------------------------------------------------------------------------
// MODE1:
// When a button is pressed, it lights up and the corresponding audio 
// sounds

// MODE2:
// Same as Mode1 but in English

// MODE3:
// - A random audio sounds
// - You have to press the button that corresponds to that audio
// - If you press the right button --> A "RIGHT ANSWER" audio is played 
//   and the corresponding LED lights up
// - If you press the wrong button --> A "WRONG ANSWER" audio is played
// - If you have not responded within the time, another random audio is 
//   played to play again

// MODE4:
// - 4 random buttons with 4 different colours light up
// - An audio plays with the colour to look for
// - If you press the right button --> A "RIGHT ANSWER" audio is played 
//   and the corresponding LED lights up
// - If you press the wrong button --> A "WRONG ANSWER" audio is played
// - If you have not responded within the time, another 4 buttons with 
//   4 different colours light up and another random colour sounds to 
//   play again

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