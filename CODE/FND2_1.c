/*
 * FND2_1.c
 * 0->1->2....->9->8...1반복하기
 * Created: 2018-04-03 오후 2:10:59
 * Author: KHJ
 */

 #include <mega128.h>
 #include <delay.h>
 void main(void) {
    unsigned char count = 0;
    DDRC = 0x00;
    DDRD = 0xff;
    while (1) {
        for(;count<9;count++) {
            delay_ms(500);
            PORTD = 0x70 | count;
        }
        for(;count>0;count--) {
            delay_ms(500);
            PORTD = 0x70 | count;
        }
        
    }
 }
