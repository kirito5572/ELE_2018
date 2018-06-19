#include <mega128.h>
#include <delay.h>
void main(void) {
    DDRA = 0xff;
    PORTA = 0x01;
    while(1) {
        delay_ms(200);
        PORTA <<=1;
        if(PORTA == 0x00) {
            PORTA = 0x80;
            while(1) {
                delay_ms(200);
                PORTA >>=1;
                if(PORTA == 0x00) {
                    PORTA = 0x01;
                    break;
                }
            }
        }
    }
}