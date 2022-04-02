#include "capacitive_buttons.h"

// This is done to compare with a 1 by AND the bit 
// in the position you need and to know if it is on or off 
#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

//------------------------------------------------------------------------
// OBJECTS
//------------------------------------------------------------------------
// You can have up to 4 MPR121 boards on one I2C bus
Adafruit_MPR121 buttons_board1 = Adafruit_MPR121();
Adafruit_MPR121 buttons_board2 = Adafruit_MPR121();

//------------------------------------------------------------------------
// VARIABLES
//------------------------------------------------------------------------
// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint32_t lasttouched = 0;
uint32_t currtouched = 0;

//------------------------------------------------------------------------
// INITIALIZATION FUNCTIONS 
//------------------------------------------------------------------------
void buttons_setup() {

    // MPR121_board1
    if (!buttons_board1.begin(MPR121_ADDRESS1)) {
        Serial.println("MPR121_board1 not found");
        while (1);
    }
    Serial.println("MPR121_board1 found!");

    // MPR121_board2
    if (!buttons_board2.begin(MPR121_ADDRESS2)) {
        Serial.println("MPR121_board2 not found");
        while (1);
    }
    Serial.println("MPR121_board2 found!");
}

//------------------------------------------------------------------------
// ACTION FUNCTIONS 
//------------------------------------------------------------------------
void buttons_read(int *button_position) {

    currtouched = buttons_board2.touched() & 0x0FFF;   // Get the currently touched pads
    currtouched <<= 12;                                // Move buttons_board2 data left by 12 bits
    currtouched |= buttons_board1.touched() & 0x0FFF;  // Put the buttons_board1 data in the lower 12 bits
  
    // 'i' till 24 because MPR121 boards have 12 channels each and we have two
    for (int i=0; i<24; i++) {
        // if it *is* touched and *wasnt* touched before, alert!
        if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
            Serial.print(i); Serial.println(" touched");
            *button_position = i;
        }
        // if it *was* touched and now *isnt*, alert!
        if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
            Serial.print(i); Serial.println(" released");
        }
    }

    // reset our state
    lasttouched = currtouched;
    
}