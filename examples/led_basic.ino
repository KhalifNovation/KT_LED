/*
   KhalifNovation
   KT_LED Library(examples)

   Created : 07/03/2019
   Author :  syed93uthman

   This is an example how to use KT_LED class
    - begin(bool state)
    - on()
    - off()
    - blinky(delayTime)

*/

// the setup function runs once when you press reset or power the board

#include "KT_LED.h"

KT_LED led1(13,ACTIVE_HIGH_MODE);
KT_LED led2(12, ACTIVE_HIGH_MODE);

void setup() {
  led1.begin(false);  //
  led2.begin(false);  //
}

// the loop function runs over and over again until power down or reset
void loop() {
  led1.on();
  //led1.off();
  led1.blink(1000); //led blinking for 1sec
}

