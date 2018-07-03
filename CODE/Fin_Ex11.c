#include <mega128.h>
#include <delay.h>
void main() {
    DDRB = 0xff;
    while(1) {
        PORTB.4 = 1;
        PORTB.5 = 0;
        delay_ms(3000);
    }
}