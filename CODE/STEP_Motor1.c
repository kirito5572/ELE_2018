/*
 * STEP_Motor1.c
 * 
 * Created: 2018-04-24 ¿ÀÈÄ 01:53:26
 * Author: KHJ
 */

 #include <mega128.h>
 #include <delay.h>
 #define SMOTOR PORTE
 void main(void) {                 //CCW 185 count 10 2.5 count 20 7.5
    unsigned short count;          //CW 183 count 10 3.5 count 20 8.5
    DDRE = 0x0f;
    SMOTOR = 0x03;
        for(count = 0; count < 183; count++) {
            SMOTOR.2 = 1;
            delay_ms(150);
            SMOTOR.2 = 0;
            delay_ms(150);
        }
 }
            