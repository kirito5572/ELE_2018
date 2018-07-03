#include <mega128.h>
#include <delay.h>
unsigned int count = 0;
void main() {
    DDRD = 0xff;
    EIMSK = 0x80;
    EICRB = 0x00;
    SREG = 0x80;
    while(1) {
        unsigned char st,nd,rd,th;
        th = (count/1000)%10;
        rd = (count/100)%10;
        nd = (count/10)%10;
        st = count%10;
        PORTD = 0x70 | st;
        delay_ms(2);
        PORTD = 0xb0 | nd;
        delay_ms(2);
        PORTD = 0xd0 | rd;
        delay_ms(2);
        PORTD = 0xe0 | th;
        delay_ms(2);
    }
}
interrupt [EXT_INT7] void inter7(void) {
    count++;
}