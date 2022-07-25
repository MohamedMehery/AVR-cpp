
#include "led.hpp"

int main(int argc , char ** argv)
{
    LED_DIO led1;   //led init 
    led1(2);   //change pin number to pin 2 
    while (1)
    {
        led1.led_toggle();
    }
    return 0;
}