int count;
#include <mega128.h>
#include <delay.h>
void main(void) {
    DDRA = 0xff;
    DDRD = 0xff;
    DDRF = 0x00;
    ADCSRA = 0x8f;
    SREG = 0x80;
    do {
        ADMUX = 0x50;
        ADCSRA = 0xcf; 
        delay_ms(2);
        ADCSRA = 0x8f;
    }
    while (1);
}
interrupt [ADC_INT] void ADCinter(void) {
    unsigned char st,nd,rd;              
    PORTA = ADCH;
    if(ADCW > 512) {
        count = ((~ADCW)+1) * (-1);
        PORTD = 0xe0;
        delay_ms(2);
    } else{
        count = ADCW;
        PORTD = 0xef;
        delay_ms(2);
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