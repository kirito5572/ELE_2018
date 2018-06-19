#include <mega128.h>
#include <delay.h>
void main() {
    DDRA = 0xff;
    while(1) {
        PORTA.0 = 1;
        delay_ms(200);
        PORTA.0 = 0;
        delay_ms(200);
    }
}