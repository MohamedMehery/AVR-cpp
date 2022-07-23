#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

class LED_DIO
{
    public:
        LED_DIO();
        void led_toggle(void);
};
LED_DIO::LED_DIO(void)
{
    DDRA = 0x01;    //make porta->pin0 as input
    PORTA = 0x01;   //init porta->pin0 as digital low
}
void LED_DIO::led_toggle()
{
    PORTA ^= 0x01;
    _delay_ms(1000);
}

int main(void)
{
    LED_DIO led1;   //led init 
    while (1)
    {
        led1.led_toggle();
    }
    
    return 0;
}