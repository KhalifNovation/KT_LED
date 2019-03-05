#include "KT_LED.h"


KT_LED::KT_LED(uint8_t pinValue){

    _pinValue = pinValue;
    pinMode(_pinValue, OUTPUT);
    digitalWrite(_pinValue,LOW);

}

void KT_LED::ON(void){

    digitalWrite(_pinValue,HIGH);

}

void KT_LED::OFF(void){

    digitalWrite(_pinValue,LOW);
}
