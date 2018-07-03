#include <mega128.h>
#include <delay.h>
void main() {
    unsigned char i;
    DDRB = 0xff;
    for(i=0; i<50; i++) {
        PORTB = 0x01;
        delay_ms(20);
        PORTB = 0x04;
        delay_ms(20);
        PORTB = 0x02;
        delay_ms(20);
        PORTB = 0x08;
        delay_ms(20);
    }
}