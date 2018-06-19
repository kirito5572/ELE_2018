/*
 * AD6.c
 *
 * Created: 2018-06-12 ¿ÀÈÄ 02:06:41
 * Author: KHJ
*/
int count,ADC0L,ADC1L;
#include <mega128.h>
#include <delay.h>
void main(void) {
    DDRA = 0xff;
    DDRD = 0xff;
    DDRF = 0x00;
    ADCSRA = 0x8f;
    SREG = 0x80;
    do {
        ADMUX = 0x30;
        ADCSRA = 0xcf; 
        delay_ms(2);
        ADCSRA = 0x8f;
        ADMUX = 0x20;
        ADCSRA = 0xcf;
        delay_ms(2);
        ADCSRA = 0x8f;
        ADMUX = 0x21;
        ADCSRA = 0xcf;
        delay_ms(2);
    }
    while (1);
}
interrupt [ADC_INT] void ADCinter(void) {
    unsigned char st,nd,rd;
    if(ADMUX == 0x20) {
        ADC0L = ADCH;    
    }
    else if(ADMUX == 0x21) {                                               
        ADC1L = ADCH;                                                      
    }
    else if(ADMUX == 0x30) {   
        if(ADC0L < ADC1L) {
            count = ((~ADCH)+1);
            PORTD = 0xe0;
            delay_ms(2);
        }
        else{
            count = ADCH;
            PORTD = 0xef;
            delay_ms(2);
        }    
    }
    else {

    }
    rd = (count/100)%10;
    nd = (count/10)%10;
    st = count%10;
    PORTD = 0xd0 | rd;
    delay_ms(2);
    PORTD = 0xb0 | nd;
    delay_ms(2);
    PORTD = 0x70 | st;
    delay_ms(2);
}
