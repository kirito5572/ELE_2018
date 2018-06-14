/*
 * AD6.c
 *
 * Created: 2018-06-12 ¿ÀÈÄ 02:06:41
 * Author: KHJ
 */
long count;
#include <mega128.h>
#include <delay.h>
void main(void) {
    DDRA = 0xff;
    DDRD = 0xff;
    DDRF = 0x00;
    ADMUX = 0x10;
    ADCSRA = 0x8f;
    SREG = 0x80;
    do {
        ADCSRA = 0xcf; 
        delay_ms(5);
    }
    while (1);
}
interrupt [ADC_INT] void ADCinter(void) {
    unsigned char st,nd,rd;
    count = ADCW;
    if(ADCH.1 == 1) {
        count = ((long)(ADCW*-1)+1)%256;
        rd = (count/100)%10;
        nd = (count/10)%10;
        st = count%10;
        PORTD = 0xe0;
        delay_ms(2);
    }
    else{
        count = ADCW%256;
        rd = (count/100)%10;
        nd = (count/10)%10;
        st = count%10;
        PORTD = 0xef;
        delay_ms(2);
    }    
    PORTD = 0xd0 | rd;
    delay_ms(2);
    PORTD = 0xb0 | nd;
    delay_ms(2);
    PORTD = 0x70 | st;
    delay_ms(2);
}
