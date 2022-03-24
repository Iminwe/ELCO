#ifndef _SYSTEMLIB_H_ // if this is not defined
#define _SYSTEMLIB_H_ // it will be defined

//------------------------------------------------------------------------
// CLARIFICATIONS
//------------------------------------------------------------------------
// But if it is already defined, it does not re-execute that part of the block.

//------------------------------------------------------------------------
// LEDS
//------------------------------------------------------------------------

// Which pin on the Arduino is connected to the NeoPixels?
#define GPIO_LEDS               15

// How many NeoPixels are attached to the Arduino?
#define LEDS_NUMPIXELS          19

// Time (in milliseconds) to pause between pixels
#define LEDS_DELAY              500 

//------------------------------------------------------------------------
// DFplayer
//------------------------------------------------------------------------

// Which pin on the Arduino is connected to the DFplayer?

#define GPIO_DFPLAYER_RX        5       // Pin receiving info from DFplayer
#define GPIO_DFPLAYER_TX        4       // Pin transmiting info to DFplayer

//------------------------------------------------------------------------
// GLOBAL VARIABLE DECLARATIONS
//------------------------------------------------------------------------
// declare global var
extern int button_position;

#endif /* SYSTEMLIB_H_ */