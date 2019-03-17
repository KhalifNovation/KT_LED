// ensure this library description is only included once
#ifndef KT_LED_h
#define KT_LED_h

	#if defined(ARDUINO) && ARDUINO >= 100
		#include "Arduino.h"
	#else
		#include "WProgram.h"
	#endif

enum MODE_LED
{
	ACTIVE_HIGH_MODE,
	ACTIVE_LOW_MODE
};

class KT_LED{

    // user-accessible "public" interface
    public:
        KT_LED(uint8_t pin, MODE_LED mode);
		void begin(bool ledState);
		void state(bool ledState);
        void brightness(int value);
        void on(void);
        void off(void);
        void blink(int);
        void blink(int, int);
        void breathe(float);

    // library-accessible "private" interface
    private:
		MODE_LED _mode;
        int _pinValue;
        unsigned long _lastTime;
        bool _ledState;

};

#endif
