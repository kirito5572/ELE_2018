#include <mega128.h>
#include <delay.h>
void main(void) {
    DDRA = 0xff;
    PORTA = 0xf0;
    while(1) {
        PORTA = ~PORTA;
        delay_ms(200);
    }
}