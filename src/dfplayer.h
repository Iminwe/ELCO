#ifndef _DFPLAYER_H_
#define _DFPLAYER_H_

//------------------------------------------------------------------------
// CLARIFICATIONS
//------------------------------------------------------------------------
// Code expects the SD card to contain the mp3 files in the path below:
// sd:/mp3/00XX.mp3
//
// Examples:
// sd:/mp3/0001.mp3
// sd:/mp3/0002.mp3

// Volume can have values from 0 to 30

//------------------------------------------------------------------------
// LIBRARIES
//------------------------------------------------------------------------
#include <Arduino.h>
#include <systemLib.h>

#include <SoftwareSerial.h>
#include <DFMiniMp3.h>

//------------------------------------------------------------------------
// INITIALIZATION FUNCTIONS 
//------------------------------------------------------------------------
void dfplayer_setup();

//------------------------------------------------------------------------
// ACTION FUNCTIONS 
//------------------------------------------------------------------------
void dfplayer_play(int *button_position);

#endif /* _DFPLAYER_H_ */