#ifndef _LEDS_WS2812_H_
#define _LEDS_WS2812_H_

//------------------------------------------------------------------------
// CLARIFICATIONS
//------------------------------------------------------------------------


//------------------------------------------------------------------------
// LIBRARIES
//------------------------------------------------------------------------
#include <Arduino.h>
#include <systemLib.h>

#include <Adafruit_NeoPixel.h>

//------------------------------------------------------------------------
// INITIALIZATION FUNCTIONS 
//------------------------------------------------------------------------
void leds_setup ();

//------------------------------------------------------------------------
// ACTION FUNCTIONS 
//------------------------------------------------------------------------
void leds_write (int *button_position);

#endif /* _LEDS_WS2812_H_ */