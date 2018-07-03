#include <mega128.h>
#include <delay.h>
void main() {
    DDRB = 0xff;
    while(1) {
        PORTB.4 = 1;
        PORTB.5 = 0;
        delay_ms(3000);
        PORTB.4 = 0;
        delay_ms(500);
        PORTB.5 = 1;
        delay_ms(3000);
        PORTB.5 = 0;
        delay_ms(500);
    }
}