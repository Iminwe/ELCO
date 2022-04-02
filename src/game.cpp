#include "game.h"

bool hasPlayed_MODE3 = false;
unsigned int timer_MODE3 = 0;

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

void game_MODE1() {
    Serial.println("Jugando Modo 1");

    audio_folder = FOLDER_MODE1;

    if (button_position < 19) {
        audio_position=button_position+1;
        // Turn on the led in the "button_position"
        leds_write(&button_position);
        // Play the audio in the "button_position" of SD card
        dfplayer_play(&audio_folder,&audio_position);
    }
    
}

void game_MODE2() {
    Serial.println("Jugando Modo 2");

    audio_folder = FOLDER_MODE2;

    if (button_position < 19) {
        audio_position=button_position+1;
        // Turn on the led in the "button_position"
        leds_write(&button_position);
        // Play the audio in the "button_position" of SD card
        dfplayer_play(&audio_folder,&audio_position);
    }
    
}

void game_MODE3() {
    Serial.println("Jugando Modo 3");

    audio_folder = FOLDER_MODE3;

    if (!hasPlayed_MODE3){
        audio_position =(rand() % 3) + 1;
        // Play the audio in the "button_position" of SD card
        dfplayer_play(&audio_folder,&audio_position);
        hasPlayed_MODE3 = true;
        timer_MODE3 = millis();
    } else {
        if ((millis() - timer_MODE3) < GAME_MODE3_TIMER) {
            if (button_position == (audio_position - 1)) {                
                dfplayer_play(&(audio_folder=FOLDER_SOUNDS),&(audio_position=RIGHT_SOUND));
                leds_write(&button_position);
                hasPlayed_MODE3 = false;
                delay (5000);
                leds_clear();

            } else {
                if (!(button_position==-1)&&(button_position<19)) {
                    dfplayer_play(&(audio_folder=FOLDER_SOUNDS),&(audio_position=WRONG_SOUND));
                    delay (1000);
                }
            }
        } else {
            hasPlayed_MODE3 = false;
        }
    }
}

void game_MODE4() {
    Serial.println("Jugando Modo 4");



}