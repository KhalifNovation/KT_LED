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
KT_LED::KT_LED(uint8_t pinValue, MODE_LED mode){
	_mode = mode;
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

	//set pin HIGH, if Active High Mode
	if (_mode == ACTIVE_HIGH_MODE)
		digitalWrite(_pinValue, HIGH);
	else
		digitalWrite(_pinValue, LOW);

}

// Turn off led
void KT_LED::off(void){

    //set pin LOW, if Active High Mode
	if (_mode == ACTIVE_HIGH_MODE)
		digitalWrite(_pinValue, LOW);
	else
		digitalWrite(_pinValue, HIGH);

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
