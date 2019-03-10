/*
   KhalifNovation
   KT_LED Library(examples)

   Created : 07/03/2019
   Author :  syed93uthman

   This example shows how to use the library blink function
*/

// the setup function runs once when you press reset or power the board

#include "KT_LED.h"

// create led object in Active High Mode
KT_LED led1(13,ACTIVE_HIGH_MODE);

// setup function
void setup() {
  led1.begin(false);  // initialize the state of the led
}

// the loop function runs over and over again until power down or reset
void loop() {
  led1.blink(1000); //led blinking for 1sec
}

