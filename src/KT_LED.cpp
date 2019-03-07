/*
 * TO DO
 *
 * FadeOn - transition from off to max brightness
 * FadeOff - transition from max brightness to off
 * Breathe - like blink, but use pwm to make the effect of breathing
 * LowActive - invert on and off
 * Blink - change to add off and on duration parameter
 * add support for RGB LED
 */

#include "KT_LED.h"

// Constructor
KT_LED::KT_LED(uint8_t pinValue){

    _pinValue = pinValue;   // init pin use for led
    _lastTime = millis();   // keep track of time
    _ledState = false;      // keep track of state

    // initialize led as output and state as off
    pinMode(_pinValue, OUTPUT);
    digitalWrite(_pinValue,_ledState);

}

// Turn on led
void KT_LED::ON(void){

    // change the state then turn on led
    _ledState = true;
    digitalWrite(_pinValue,_ledState);

}

// Turn off led
void KT_LED::OFF(void){

    //change the state then turn off led
    _ledState = false;
    digitalWrite(_pinValue,_ledState);
}

// Led blinking (without delay)
// This function need to be call frequently
void KT_LED::Blink(int delayTime){

    // get current time
    unsigned long currentTime = millis();

    // check if it is time to blink the led
    if(currentTime - _lastTime >= delayTime){

        // toggle the state of led
        digitalWrite(_pinValue, !_ledState);
    
        // keep track of time and state
        _lastTime = currentTime;
        _ledState = !_ledState;
        
        
    }

}
