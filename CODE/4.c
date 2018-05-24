#include <mega128.h>
#include <delay.h>
#define LED PORTA
 void main(void) {
    DDRA = 0xff;
    LED = 0xf0;
    while(1) {
        LED = ~LED;
        delay_ms(500);
    }
 }     