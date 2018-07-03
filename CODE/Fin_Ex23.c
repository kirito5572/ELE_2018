#include <mega128.h>
#include <delay.h>

unsigned int ADC(unsigned char);
void main() {
    DDRB = 0xff;
    DDRF = 0x00;
    PORTB = 0x00;
    ADCW = 0x0000;
    TCCR0 = 0x67;
    TIMSK = 0x01;
    while(1) {
        OCR0 = (ADC(0x8f)/10);
        delay_ms(20);    
    }
}
unsigned int ADC(unsigned char ADCS) {
    ADMUX = 0x00;
    ADCSRA = ADCS;
    ADCSRA |= 0x40; //(1<<ADSC)
    delay_us(10);
    while(ADIF == 0);
    return ADCW;
}
    
