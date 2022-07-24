
#include "led.hpp"

int main(void)
{
    LED_DIO led1;   //led init 
    led1(2);   //change pin number to pin 2 
    while (1)
    {
        led1.led_toggle();
    }
    return 0;
}