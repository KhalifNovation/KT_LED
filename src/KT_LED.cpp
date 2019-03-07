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

// Constructor for single led
KT_LED::KT_LED(uint8_t pinValue){

    _pinValue = pinValue;   // init pin use for led
    _ledState = false;      // keep track of state

}

// set single led as an output, set the initial state as HIGH or LOW
void KT_LED::begin(bool state) {
	_ledState = state;
	pinMode(_pinValue, OUTPUT);
	digitalWrite(_pinValue, _ledState);
	_lastTime = millis();   // keep track of time
}

// Turn on led
void KT_LED::on(void){

    // change the state then turn on led
    _ledState = true;
    digitalWrite(_pinValue,_ledState);

}

// Turn off led
void KT_LED::off(void){

    //change the state then turn off led
    _ledState = false;
    digitalWrite(_pinValue,_ledState);
}

// Led blinking (without delay)
// This function need to be call frequently
void KT_LED::blink(int delayTime){

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
