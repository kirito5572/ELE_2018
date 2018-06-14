/*
 * Timer3_1.c
 *
 * Created: 2018-06-05 ¿ÀÈÄ 12:25:43
 * Author: KHJ
 */

#include <mega128.h>
unsigned char LED = 0x01, count = 0;
void main(void) {
    DDRA = 0xff;
    TIMSK = 0x01;
    TCCR0 = 0x07;
    TCNT0 = 0x00;
    SREG = 0x80;
    while (1) {
        PORTA = LED;
    }
}
interrupt [TIM0_OVF] void overflow(void) {
    count++;
    if(count == 31) {
        LED <<= 1;
        count = 0;
        if(LED == 0x00) {
            LED = 0x01;
        }
    }
}
