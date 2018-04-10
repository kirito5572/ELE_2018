/*
 * FND2_2.c
 * 0->1...->99->98...->0 �ݺ�
 * Created: 2018-04-03 ���� 2:21:03
 * Author: KHJ
 */

 #include <mega128.h>
 #include <delay.h>
 void main(void) {
    unsigned char count = 0,st,nd;
    DDRC = 0x00;
    DDRD = 0xff;
    while(1) {
        for(;count<99;count++) {
            nd = (count/10) % 10;
            st = count % 10;
            PORTD = 0xb0 | nd;
            delay_ms(20);
            PORTD = 0x70 | st;
            delay_ms(20);
        }
        for(;count>0;count--) {
            nd = (count/10) % 10;
            st = count % 10;
            PORTD = 0xb0 | nd;
            delay_ms(20);
            PORTD = 0x70 | st;
            delay_ms(20);
        }
    }
 }       
    