#include <mega128.h>
#include <delay.h>
void main() {
    DDRA = 0xff;
    PORTA = 0xff;
    while(1) {
        PORTA = ~PORTA;
        delay_ms(200);
    }
}