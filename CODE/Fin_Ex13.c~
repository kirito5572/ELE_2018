#include <mega128.h>
#include <delay.h>
void main() {
    unsigned char speed = 15;
    DDRB = 0xff;
    DDRC = 0x00;
    DDRA = 0xff;
    TCCR1A = 0b10000001;
    TCCR1B = 0b00000101;
    TCNT1 = 0x0000;
    SREG = 0x80;
    while(1) {
        switch(PINC) {
            case 0x01: speed = 30;
            break;
            case 0x02: speed = 60;
            break;
            case 0x04: speed = 90;
            break;
            case 0x08: speed = 120;
            break;
            case 0x10: speed = 150;
            break;
            case 0x20: speed = 180;
            break;
            case 0x40: speed = 210;
            break;
            case 0x80: speed = 240;
            break;
            default: speed = 0;
            break;
        }
        PORTA = speed;
        OCR1A = speed;
        PORTB.4 = 0;
    }
}