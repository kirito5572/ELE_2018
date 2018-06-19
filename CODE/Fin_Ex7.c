#include <mega128.h>
#include <delay.h>
void main() {
    unsigned char delay;
    DDRA = 0xff;
    DDRC = 0x00;
    PORTA = 0x01;
    while(1) {
    delay = (~PINC)*5;
    delay_ms(delay);
    PORTA <<= 1;
    if(PORTA == 0x00) {
        PORTA = 0x80;
        while(1) {
            delay = (~PINC)*5;
            delay_ms(delay);
            PORTA >>= 1;
            if(PORTA == 0x00) {
                PORTA = 0x01;
                break;
            }
        }
    }
}