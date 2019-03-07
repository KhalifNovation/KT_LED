/*
 *
 * Test.h - Test library
 *
 */

// ensure this library description is only included once
#ifndef KT_LED_h
#define KT_LED_h

#include <Arduino.h>

class KT_LED{

    // user-accessible "public" interface
    public:
        KT_LED(uint8_t pin);
		void begin(bool state);
        void ON(void);
        void OFF(void);
        void Blink(int);

    // library-accessible "private" interface
    private:
        int _pinValue;
        unsigned long _lastTime;
        bool _ledState;

};

#endif
