#include <mega128.h>
#include <delay.h>
unsigned char p[8] = {0x01,0x05,0x04,0x06,0x02,0x0a,0x08,0x09};
void main() {
    DDRB = 0xff;
    while(1) {
        unsigned char i;
        for(i=0;i<8;i++) {
            PORTB = p[i];
            delay_ms(20);
        }
    }
}