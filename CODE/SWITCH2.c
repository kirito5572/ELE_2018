/* SWITCH2.c
 * 왕복으로 On되어진 LED를 이동하지만,
    DIP S/W를 이용해 이동되는 속도를 결정하도록 하는 프로그램
 * Created  2018-03-26 오후 14:24:17           
 * Author: KHJ
 */
 #include <mega128.h>
 #include <delay.h>
 
 void main() {
    unsigned char turn = 0;
    unsigned short delay_time = 1;
    DDRA = 0xff;
    DDRC = 0x00;
    PORTA = 0x01;
    while(1) {
        for(;turn < 7;turn++) {
            PORTA = PORTA << 1;
            if(PINC != 0) {
                delay_time = PINC*10;
                }
            delay_ms(delay_time); 
            }
        for(;turn > 0; turn--) {
            PORTA = PORTA >> 1;
            if(PINC != 0) {
                delay_time = PINC*10;
                }
            delay_ms(delay_time);
            }
        }
 }