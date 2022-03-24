#ifndef _SYSTEMLIB_H_ // if this is not defined
#define _SYSTEMLIB_H_ // I define it

// But if it is already defined, it does not re-execute that part of the block.

//------------------------------------------------------------------------
// LEDS
//------------------------------------------------------------------------

// Which pin on the Arduino is connected to the NeoPixels?
#define GPIO_LEDS                      15

// How many NeoPixels are attached to the Arduino?
#define LEDS_NUMPIXELS               19

#define LEDS_DELAY 500 // Time (in milliseconds) to pause between pixels

//------------------------------------------------------------------------
// DFplayer
//------------------------------------------------------------------------

// Which pin on the Arduino is connected to the DFplayer?
#define GPIO_DFPLAYER_RX 	    5
#define GPIO_DFPLAYER_TX  	    4 		


//------------------------------------------------------------------------
// GLOBAL VARIABLES
//------------------------------------------------------------------------
// declare global var
extern int button_position;


#endif /* SYSTEMLIB_H_ */