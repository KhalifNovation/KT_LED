
/*
   KhalifNovation
   KT_LED Library(examples)

   Created : 10/03/2019
   Author :  hazimgharib21

   This example shows how to use the library breathe function
*/


// include KT_LED library
#include "KT_LED.h"

// create led object in Active High Mode
// for breathe to work, need to select pwm pin
KT_LED led1(11,ACTIVE_HIGH_MODE);

// the setup function runs once when you press reset or power the board
void setup() {
    led1.begin(false);  // initialize the state of the led
}

// the loop function runs over and over again until power down or reset
void loop() {
    led1.breathe(500);  // create led breathing effect with speed of 500
}

