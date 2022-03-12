#include "capacitive_buttons.h"

// This is done to compare with a 1 by AND the bit 
// in the position you need and to know if it is on or off 
#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 buttons_board1 = Adafruit_MPR121();
Adafruit_MPR121 buttons_board2 = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint32_t lasttouched = 0;
uint32_t currtouched = 0;


void buttons_setup()
{
    // Default address is 0x5A, if tied to 3.3V its 0x5B
    // If tied to SDA its 0x5C and if SCL then 0x5D

    // MPR121_board1 is tied to GND (default address)
    if (!buttons_board1.begin(0x5A))
    {
        Serial.println("MPR121_board1 not found, check wiring?");
        while (1);
    }
    Serial.println("MPR121_board1 found!");

    // MPR121_board2 is tied to SDA
    if (!buttons_board2.begin(0x5C))
    {
        Serial.println("MPR121_board2 not found, check wiring?");
        while (1);
    }
    Serial.println("MPR121_board2 found!");
}

void buttons_read() {
    // Get the currently touched pads
    currtouched = buttons_board2.touched() & 0x0FFF;
    currtouched <<= 12;  // Move buttons_board2 data left by 12 bits
    currtouched |= buttons_board1.touched() & 0x0FFF;  // put the buttons_board1 data in the lower 12 bits
  
   for (uint8_t i=0; i<24; i++) {
        
        // it if *is* touched and *wasnt* touched before, alert!
        if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
            Serial.print(i); Serial.println(" released ");
        }
        // if it *was* touched and now *isnt*, alert!
        if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
            Serial.print(i); Serial.println(" touched");
        }

   }

  // reset our state
  lasttouched = currtouched;

}