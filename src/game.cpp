#include "game.h"

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

    audio_folder = folder_MODE1;

    if (button_position < 19) {
        // Turn on the led in the "button_position"
        leds_write(&button_position);
        // Play the audio in the "button_position" of SD card
        dfplayer_play(&audio_folder,&button_position);
    }
    Serial.println("Jugando Modo 1");
}

void game_MODE2() {

    audio_folder = folder_MODE2;

    if (button_position < 19) {
        // Turn on the led in the "button_position"
        leds_write(&button_position);
        // Play the audio in the "button_position" of SD card
        dfplayer_play(&audio_folder,&button_position);
    }
    Serial.println("Jugando Modo 2");
}

void game_MODE3() {
    Serial.println("Jugando Modo 3");

}

void game_MODE4() {
    Serial.println("Jugando Modo 4");

}