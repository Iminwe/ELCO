#ifndef _CAPACITIVE_BUTTONS_H_
#define _CAPACITIVE_BUTTONS_H_

//------------------------------------------------------------------------
// CLARIFICATIONS
//------------------------------------------------------------------------
// For this code to work correctly:
// - The capacitive fabric sensors have to be connected to GND 
// and to the MPR121 board channel.
// - The touch buttons have to be low active. 
// That means that point A has to be soldered on the board.
// - MPR121 default address is 0x5A.
// - MPR121 address pin tied to 3.3V its 0x5B.
// - MPR121 address pin tied to SDA its 0x5C.
// - MPR121 address pin tied to SCL its 0x5D.

//------------------------------------------------------------------------
// LIBRARIES
//------------------------------------------------------------------------
#include <Arduino.h>
#include <systemLib.h>

#include <Wire.h>
#include "Adafruit_MPR121.h"

//------------------------------------------------------------------------
// INITIALIZATION FUNCTIONS 
//------------------------------------------------------------------------
void buttons_setup();

//------------------------------------------------------------------------
// ACTION FUNCTIONS 
//------------------------------------------------------------------------
void buttons_read(int *button_position);

#endif /* _CAPACITIVE_BUTTONS_H_ */