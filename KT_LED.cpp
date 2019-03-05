#include "KT_LED.h"


KT_LED::KT_LED(uint8_t pinValue){

    _pinValue = pinValue;
    _lastTime = millis();
    _ledState = false;

    pinMode(_pinValue, OUTPUT);
    digitalWrite(_pinValue,_ledState);

}

void KT_LED::ON(void){

    _ledState = true;
    digitalWrite(_pinValue,_ledState);

}

void KT_LED::OFF(void){

    _ledState = false;
    digitalWrite(_pinValue,_ledState);
}

void KT_LED::Blink(int delayTime){

    unsigned long currentTime = millis();

    if(currentTime - _lastTime >= delayTime){

        digitalWrite(_pinValue, !_ledState);
    
        _lastTime = currentTime;
        _ledState = !_ledState;
        
        
    }

}
