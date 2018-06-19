#include <mega128.h>
#include <delay.h>
unsigned int count;
void FND();
void main() {
    DDRC = 0x00;
    DDRD = 0xff;
    while(1) {
        FND();
        if(PINC!= 0x00) {
            while(1) {
                FND();
                if(PINC == 0x00) {
                    count++;
                    break;
                }
            }
        }
    }
}
void FND() {
    unsigned char st,nd,rd,th;
    th = (count/1000) %10;
    rd = (count/100) %10;
    nd = (count/10) %10;
    st = count %10;
    PORTD = 0xe0 | th;
    delay_ms(2);
    PORTD = 0xd0 | rd;
    delay_ms(2);
    PORTD = 0xb0 | nd;
    delay_ms(2);
    PORTD = 0x70 | st;
    delay_ms(2);
}