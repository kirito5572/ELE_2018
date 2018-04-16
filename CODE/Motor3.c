/*
 * MOTOR1.c
 * 모터를 정방향으로 회전시키기
 * Created: 2018-04-16 오후 12:23:59
 * Author: KHJ
 */

#include <mega128.h>
#include <delay.h>
#define MOTOR PORTB
unsigned int speed;
void main(void) {
    DDRA = 0xff;
    DDRB = 0xff;
    DDRC = 0x00;
    TCCR1A = 0b11000001;
    TCCR1B = 0b00000101;
    TCNT1 = 0x0000;
    SREG = 0x80;
    
    while(1) {
        speed = PINC;
        OCR1AL = speed;
        PORTA = OCR1AL;
    }
}
