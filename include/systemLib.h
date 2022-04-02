#ifndef _SYSTEMLIB_H_ // if this is not defined
#define _SYSTEMLIB_H_ // it will be defined

//------------------------------------------------------------------------
// CLARIFICATIONS
//------------------------------------------------------------------------
// But if it is already defined, it does not re-execute that part of the block.

//------------------------------------------------------------------------
// MPR121 BOARDS
//------------------------------------------------------------------------
// MPR121_board1 is tied to GND (default address)
#define MPR121_ADDRESS1          0x5A
// MPR121_board2 is tied to SDA
#define MPR121_ADDRESS2          0x5C

//------------------------------------------------------------------------
// LEDS
//------------------------------------------------------------------------
// Which pin on the Arduino is connected to the NeoPixels?
#define GPIO_LEDS               15

// How many NeoPixels are attached to the Arduino?
#define LEDS_NUMPIXELS          19

// Time (in milliseconds) to pause between pixels
#define LEDS_DELAY              500

// RGB brightness values: from 0,0,0 up to 255,255,255
#define R_BRIGHTNESS            0
#define G_BRIGHTNESS            150
#define B_BRIGHTNESS            0

//------------------------------------------------------------------------
// DFplayer
//------------------------------------------------------------------------
// Which pin on the Arduino is connected to the DFplayer?
#define GPIO_DFPLAYER_RX        5       // Pin receiving info from DFplayer
#define GPIO_DFPLAYER_TX        4       // Pin transmiting info to DFplayer

#define VOLUME                  10

enum sd_folder {
    NO_FOLDER,
	FOLDER_MODE1,
	FOLDER_MODE2,
	FOLDER_MODE3,
	FOLDER_MODE4,
    FOLDER_SOUNDS};

enum control_sounds{
    NO_SOUND,
    RIGHT_SOUND,
    WRONG_SOUND};

//------------------------------------------------------------------------
// FINITE STATE MACHINE
//------------------------------------------------------------------------
// Both states and transitions are identified by an 8-bit integer (0 to 255)
#define STATES_NUMBER           4
#define TRANSITION_NUMBER       4

enum fsm_state {
	MODE1,
	MODE2,
	MODE3,
	MODE4};

//------------------------------------------------------------------------
// GAME
//------------------------------------------------------------------------
#define GAME_MODE3_TIMER        10000

//------------------------------------------------------------------------
// GLOBAL VARIABLE DECLARATIONS
//------------------------------------------------------------------------
// Declare global var
extern int button_position;
extern int audio_folder;
extern int audio_position;
extern int button_mode;
extern int currentState;



#endif /* SYSTEMLIB_H_ */