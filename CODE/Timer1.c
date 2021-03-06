/*
 * Timer1.c
 *
 * Created: 2018-06-04 ���� 2:08:32
 * Author: KHJ
 */

#include <mega128.h>
unsigned char LED = 0x01;
void main(void) {
    DDRA = 0xf;
    TIMSK = 0x01;
    TCCR0 = 0x07;
    TCNT0 = 0x00;
    SREG = 0x80;
    while (1) {
        PORTA = LED;
    }
}
interrupt [TIM0_OVF] void overflow(void) {
    LED <<= 1;
    if(LED == 0x00) {
        LED = 0x01;
    }
}
