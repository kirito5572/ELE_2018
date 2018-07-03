#include <mega128.h>
#include <delay.h>
void main() {
    DDRB = 0xff;
    while(1) {
        PORTB = 0x09;
        delay_ms(20);
        PORTB = 0x05;
        delay_ms(20);
        PORTB = 0x06;
        delay_ms(20);
        PORTB = 0x0a;
        delay_ms(20);
    }
}