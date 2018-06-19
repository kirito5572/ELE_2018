#include <mega128.h>
#include <delay.h>
void main() {
    DDRA = 0xff;
    DDRC = 0x00;
    while(1) {
        PORTA = PINC;
        delay_ms(20);
    }
}