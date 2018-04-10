/*
 * FND2_4.c
 *
 * Created: 2018-04-03 ¿ÀÈÄ 2:10:59
 * Author: KHJ
 */

 #include <mega128.h>
 #include <delay.h>
 void main(void) {
    DDRA = 0xff;
    DDRD = 0xf0;
        while(1) {
            PORTD = 0xe0;
            PORTA = 0b11110110;
            delay_ms(10);
            PORTD = 0xd0;
            PORTA = 0b11111001;
            delay_ms(10);
            PORTD = 0xb0;
            PORTA = 0b10111000;
            delay_ms(10);
            PORTD = 0x70;
            PORTA = 0b11110011;
            delay_ms(10);
        }
 }
            