#ifndef _LED_HPP_
#define _LED_HPP_

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

class LED_DIO
{
    public:
        LED_DIO();
        void led_toggle(void);
        void operator()(uint8_t pin_num );

    private:
        uint8_t pinnumber;
};

#endif