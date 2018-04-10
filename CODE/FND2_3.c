/*
 * FND2_3.c
 *
 * Created: 2018-04-03 ¿ÀÈÄ 2:41:05
 * Author: KHJ
 */

 #include <mega128.h>
 #include <delay.h>
 void main(void) {
    unsigned char st,nd,rd,th;
    unsigned short count = 0;
    DDRC = 0x00;
    DDRD = 0xff;
    while(1) {
        if(PINC != 0) {
            count = count +2;
        }
        th = (count / 1000) % 10;
        rd = (count / 100) % 10;
        nd = (count / 10) % 10;
        st = count % 10;
        PORTD = 0xe0 | th;
        delay_ms(10);
        PORTD = 0xd0 | rd;
        delay_ms(10);
        PORTD = 0xb0 | nd;
        delay_ms(10);
        PORTD = 0x70 | st;
        delay_ms(10);
        if(count >= 9999) {
            count = 0;
        }
    }
 }
        
         