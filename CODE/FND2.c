/*
 * FND2.c
 *
 * Created: 2018-04-03 ¿ÀÈÄ 2:10:59
 * Author: KHJ
 */

 #include <mega128.h>
 #include <delay.h>
 void main(void) {
    DDRD = 0xff;
    while(1) {
        PORTD = 0xe1;
        delay_ms(5);
        PORTD = 0xd2;
        delay_ms(5);
        PORTD = 0xb3;
        delay_ms(5);
        PORTD = 0x74;
        delay_ms(5);
    }
 }