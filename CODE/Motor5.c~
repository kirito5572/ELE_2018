/*
 * MOTOR5.c
 * 
 * Created: 2018-04-23 ¿ÀÈÄ 01:52:43
 * Author: KHJ
 */

 #include <mega128.h>
 #include <delay.h>
 #define MOTOR PORTB
 unsigned int speed = 0;
 void main(void) {
    unsigned char SWnow, SWpass = 0;
    DDRA = 0xff;
    DDRB = 0xf0;
    DDRC = 0x00;
    TCCR1A = 0b10000001;
    TCCR1B = 0b00001100;
    TCNT1 = 0x0000;
    SWnow = PINC;
    while(1) {
        SWnow = PINC;
        if(PINC == 0b00000001 && speed < 250 && SWpass == 0x00 && SWnow == 0x01)
            speed = speed + 10;
        else if(PINC == 0b00000010 && speed != 0 && SWpass == 0x00 && SWnow == 0x02)
            speed = speed - 10;
        OCR1AL = speed;
        PORTA = speed;
        SWpass = SWnow;
    }
 }  