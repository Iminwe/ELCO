#include "game.h"

//------------------------------------------------------------------------
// GLOBAL VARIABLES
//------------------------------------------------------------------------
// Neopixel default color
int r_color = R_BRIGHTNESS;
int g_color = G_BRIGHTNESS;
int b_color = B_BRIGHTNESS;

// DFplayer
int audio_folder = 0;
int audio_position = -1;

//------------------------------------------------------------------------
// LOCAL VARIABLES
//------------------------------------------------------------------------
// Mode 3: Control
bool hasPlayed_MODE3 = false;
unsigned int timer_MODE3 = 0;

// Mode 4: Control
bool hasPlayed_MODE4 = false;
unsigned int timer_MODE4 = 0;

// Mode 4
int random_Color;
int random_Position;
int leds_array [COLOURS_NUMBER];

//------------------------------------------------------------------------
// ACTION FUNCTIONS 
//------------------------------------------------------------------------
// Function to check that the button is not being used for another colour
bool check_random (int led_array [], int random){
    bool result = false;
    for (size_t i = 0; i < COLOURS_NUMBER; i++) {
        if (led_array [i] == random){
            result = true;
        }
    }
    return result;
}

void game_play(int *currentState) {
    switch (*currentState) {
        case MODE1:
            game_MODE1();
            break;
        case MODE2:
            game_MODE2();
            break;
        case MODE3:
            game_MODE3();
            break;
        case MODE4:
            game_MODE4();
            break;
        default:
            game_MODE1();
            break;
    }
}

// Function to play Mode1
void game_MODE1() {
    Serial.println("Jugando Modo 1"); // Only to DEBUG

    audio_folder = FOLDER_MODE1; // Folder with the audios for this mode

    if (button_position < LEDS_NUMPIXELS) {
        audio_position=button_position+1;
        // Play the audio in the "button_position" of SD card
        dfplayer_play(&audio_folder,&audio_position);
        leds_clear();
        // Turn on the led in the "button_position"
        leds_write(&button_position, &r_color, &g_color, &b_color);
        // Delay to let audio finish playing
        delay (GAME_MODE1_DELAY_FINISHAUDIO);
    }
    
}

// Function to play Mode2
void game_MODE2() {
    Serial.println("Jugando Modo 2"); // Only to DEBUG

    audio_folder = FOLDER_MODE2; // Folder with the audios for this mode

    if (button_position < LEDS_NUMPIXELS) {
        audio_position=button_position+1;
        // Play the audio in the "button_position" of SD card
        dfplayer_play(&audio_folder,&audio_position);
        leds_clear();
        // Turn on the led in the "button_position"
        leds_write(&button_position, &r_color, &g_color, &b_color);
        // Delay to let audio finish playing
        delay (GAME_MODE2_DELAY_FINISHAUDIO);
    }
    
}

// Function to play Mode3
void game_MODE3() {
    Serial.println("Jugando Modo 3"); // Only to DEBUG
    
    audio_folder = FOLDER_MODE3; // Folder with the audios for this mode

    if (!hasPlayed_MODE3){
        delay(GAME_DELAY_STARTGAME); // Delay to start the game

        // Generate random audio
        // The blanket has 19 buttons but the audios goes from 1 to 19, not from 0 to 18
        audio_position = rand() % LEDS_NUMPIXELS + 1;
        // Play the audio in the "audio_position" of SD card
        dfplayer_play(&audio_folder,&audio_position);
        hasPlayed_MODE3 = true; // Control variable

        // Store the current time
        timer_MODE3 = millis();

    } else {
        // If it is within the time
        if ((millis() - timer_MODE3) < GAME_MODE3_TIMER) {
            // If the correct button is pressed
            if (button_position == (audio_position - 1)) {
                // "Correct answer" audio is played 
                dfplayer_play(&(audio_folder=FOLDER_CONTROL),&(audio_position=RIGHT_SOUND));
                // LEDs turn off
                leds_clear();
                // The correct button lights up
                leds_write(&button_position, &r_color, &g_color, &b_color);
                // Delay to let audio finish playing
                delay (GAME_DELAY_CORRECTANSWER);
                // Reset the control variable
                hasPlayed_MODE3 = false;
                // LEDs turn off
                leds_clear();

            // If another button is pressed
            } else {

                if (!(button_position==-1)&&(button_position<19)) {
                    // "Wrong answer" audio is played 
                    dfplayer_play(&(audio_folder=FOLDER_CONTROL),&(audio_position=WRONG_SOUND));
                    // Delay to let audio finish playing
                    delay (GAME_DELAY_WRONGANSWER);
                }
            }
        // If the time is over
        } else {
            // Reset the control variable
            hasPlayed_MODE3 = false;
            // LEDs turn off
            leds_clear();
        }
    }
}

// Function to play Mode4
void game_MODE4() {
    Serial.println("Jugando Modo 4"); // Only to DEBUG
    
    audio_folder = FOLDER_MODE4; // Folder with the audios for this mode

    if (!hasPlayed_MODE4){
        delay(GAME_DELAY_STARTGAME); // Delay to start the game

        // A random colour is generated from COLOURS_NUMBER colours
        random_Color= rand() % COLOURS_NUMBER;
        audio_position = random_Color;
       
        int random_Position;
        for (size_t i = 0; i < COLOURS_NUMBER; i++) {
            // A random button is generated from LEDS_NUMPIXELS buttons
            random_Position=rand() % LEDS_NUMPIXELS;
            // If the button is being used for another colour, a new button is generated
            while (check_random (leds_array, random_Position)){
                random_Position=rand() % LEDS_NUMPIXELS;
            }
            // It is introduced to the array
            leds_array [i] = random_Position;
        }
        //                                    Red     Green    Blue    Yellow
        int leds_red    [COLOURS_NUMBER] = {  150,        0,      0,      150};
        int leds_green  [COLOURS_NUMBER] = {    0,      150,      0,      150};
        int leds_blue   [COLOURS_NUMBER] = {    0,        0,    150,        0};

        // LEDs turn off
        leds_clear();
        // The buttons light up in the colours you have defined
        for (size_t i = 0; i < COLOURS_NUMBER; i++) {
            leds_write(&leds_array[i], &leds_red[i], &leds_green[i], &leds_blue[i]);
        }

        // Play the audio in the "audio_position" of SD card
        dfplayer_play(&audio_folder,&audio_position);
        // Set the control variable
        hasPlayed_MODE4 = true;
        // Store the current time
        timer_MODE4 = millis();

    } else {
        // If it is within the time
        if ((millis() - timer_MODE4) < GAME_MODE4_TIMER) {
            // If the correct button is pressed
            if (button_position == leds_array[random_Color]) {
                // "Correct answer" audio is played              
                dfplayer_play(&(audio_folder=FOLDER_CONTROL),&(audio_position=RIGHT_SOUND));
                // Delay to let audio finish playing
                delay (GAME_DELAY_CORRECTANSWER);
                // Reset the control variable
                hasPlayed_MODE4 = false;
                // LEDs turn off
                leds_clear();
                //leds_array [COLOURS_NUMBER]= {};
            // If another button is pressed
            } else {
                if (!(button_position==-1)&&(button_position<LEDS_NUMPIXELS)) {
                    // "Wrong answer" audio is played
                    dfplayer_play(&(audio_folder=FOLDER_CONTROL),&(audio_position=WRONG_SOUND));
                    // Delay to let audio finish playing
                    delay (GAME_DELAY_WRONGANSWER);
                }
            }
        // If the time is over
        } else {
            // Reset the control variable
            hasPlayed_MODE4 = false;
            // LEDs turn off
            leds_clear();
            //leds_array [COLOURS_NUMBER]= {};
        }
    }
}