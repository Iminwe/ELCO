#include <Arduino.h> // necessary to use our board

#include <systemLib.h> // global library with pin definition

#include "capacitive_buttons.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  buttons_setup();

}

void loop() {
  // put your main code here, to run repeatedly:

  buttons_read();

}