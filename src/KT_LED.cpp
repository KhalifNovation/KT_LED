/*
 * TO DO
 *
 * FadeOn - transition from off to max brightness
 * FadeOff - transition from max brightness to off
 * LowActive - invert on and off *added in KT_LEDv0.1*
 * Blink - change to add off and on duration parameter
 * add support for RGB LED
 * state - state the led true or false (true = led on, false = led off) *added in KT_LEDv0.2*
 */

#include "KT_LED.h"

// Constructor for single led
KT_LED::KT_LED(uint8_t pinValue, MODE_LED mode){
	_mode = mode;
    _pinValue = pinValue;   // init pin use for led
    _ledState = false;      // keep track of state

}

// set single led as an output, set the initial state as HIGH or LOW
void KT_LED::begin(bool ledState) {
	state(ledState);
	pinMode(_pinValue, OUTPUT);
	digitalWrite(_pinValue, _ledState);
	_lastTime = millis();   // keep track of time
}

//Set the led. state = true (On)
void KT_LED::state(bool ledState) {
	digitalWrite(_pinValue, ledState);
}

// Set the brightness of led, using pwm pin
void KT_LED::brightness(int value){
    analogWrite(_pinValue, value);
}

// Turn on led
void KT_LED::on(void){

	//set pin HIGH, if Active High Mode
	if (_mode == ACTIVE_HIGH_MODE)
		state(HIGH);
	else
		state(LOW);

}

// Turn off led
void KT_LED::off(void){

    //set pin LOW, if Active High Mode
	if (_mode == ACTIVE_HIGH_MODE)
		state(LOW);
	else
		state(HIGH);

}

// single Led blinking (without delay), This function need to be call frequently
void KT_LED::blink(int delayTime){

    // get current time
    unsigned long currentTime = millis();

    // check if it is time to blink the led
    if(currentTime - _lastTime >= delayTime){

        // toggle the state of led
        state(!_ledState);
    
        // keep track of time and state
        _lastTime = currentTime;
        _ledState = !_ledState;
        
    }

}

void KT_LED::breathe(float speed){

    float val = (exp(sin(millis()/speed*PI)) - 0.36787944)*108.0;
    brightness(val);
}
