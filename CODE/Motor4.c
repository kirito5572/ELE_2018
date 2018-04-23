/*
 * MOTOR4.c
 * 
 * Created: 2018-04-23 ¿ÀÈÄ 01:24:52s
 * Author: KHJ
 */
 
 #include <mega128.h>
 #include <delay.h>
 #define MOTOR PORTB
 unsigned int speed;
 void main(void) {
    DDRB = 0xf0;
    DDRC = 0x00;
    TCCR1A = 0b10000001;
    TCCR1B = 0b00000101;
    TCNT1 = 0x0000;
    while(1) {
        speed = PINC;          
        OCR1AL = speed;    
    }
 }
    