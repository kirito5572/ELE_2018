/*
 * Timer3.c
 *
 * Created: 2018-06-05 ¿ÀÈÄ 12:18:42
 * Author: KHJ
 */

#include <mega128.h>
#include <delay.h>
unsigned char count = 0;
unsigned int second;
void FND();
void main(void) {
    DDRD = 0xff;
    TIMSK = 0x01;
    TCCR0 = 0x07;
    TCNT0 = 0x00;
    SREG = 0x80;
    while (1) {
        FND();
    }
}
interrupt [TIM0_OVF] void overflow(void) {
    count++;
    if(count == 61) {
        second++;
        count = 0;
    }
}
void FND(){
    unsigned char st,nd,rd,th;
    th = (second/1000)%10;
    rd = (second/100)%10;
    nd = (second/10)%10;
    st = second%10;
    PORTD = 0x70 | st;
    delay_ms(2);
    PORTD = 0xb0 | nd;
    delay_ms(2);
    PORTD = 0xd0 | rd;
    delay_ms(2);
    PORTD = 0xe0 | th;
    delay_ms(2);
}
