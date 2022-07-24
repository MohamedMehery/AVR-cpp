#include "led.hpp"

LED_DIO::LED_DIO(void)
{
    pinnumber = 1;
    DDRA |= pinnumber;    //make porta->pin0 as input
    PORTA = pinnumber;   //init porta->pin0 as digital low
}
void LED_DIO::led_toggle()
{
    PORTA ^= pinnumber;
    _delay_ms(1000);
}
/* this call operator will change the pin number to be toggled */
void LED_DIO::operator()(uint8_t pinnum)
{
    if(pinnum <= 8)
    {
        PORTA &= ~(1<<(pinnumber-1)); //reset old pin
        DDRA |= pinnum;
        LED_DIO::pinnumber = pinnum;
    }
}
