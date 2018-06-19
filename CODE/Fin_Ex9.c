#include <mega128.h>
#include <delay.h>
void main() {
    DDRD = 0xff;
    while(1) {
        PORTD = 0xe0 | 1;
        delay_ms(2);
        PORTD = 0xd0 | 2;
        delay_ms(2);
        PORTD = 0xb0 | 3;
        delay_ms(2);
        PORTD = 0x70 | 4;
        delay_ms(2);
    }
}