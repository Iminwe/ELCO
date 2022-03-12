#include <Arduino.h> // necessary to use our board

#include <systemLib.h> // global library with pin definition

#include "capacitive_buttons.h"
#include "leds_ws2812.h"

int button_position = -1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  buttons_setup();    // Buttons initialization
  leds_setup ();      // Leds initialization

}

void loop() {
  // put your main code here, to run repeatedly:

  // We read the buttons to see if any of them have been touched
  // and save the position of the button touched
  buttons_read(&button_position);

  // We have to turn on the led in the "button_position"
  leds_write (&button_position);

  delay (1000); // delay of debug, TO DELETE WHEN CODE IS RUNNING!!

  button_position = -1;
  
}