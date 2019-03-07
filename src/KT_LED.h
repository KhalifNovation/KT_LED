/*
 *
 * Test.h - Test library
 *
 */

// ensure this library description is only included once
#ifndef KT_LED_h
#define KT_LED_h

#include <Arduino.h>

enum MODE_LED
{
	ACTIVE_HIGH_MODE,
	ACTIVE_LOW_MODE
};

class KT_LED{

    // user-accessible "public" interface
    public:
        KT_LED(uint8_t pin, MODE_LED mode);
		void begin(bool state);
        void on(void);
        void off(void);
        void blink(int);

    // library-accessible "private" interface
    private:
		MODE_LED _mode;
        int _pinValue;
        unsigned long _lastTime;
        bool _ledState;

};

#endif
