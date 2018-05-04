/*
 * STEP_Motor2.c
 * 
 * Created: 2018-04-24 ¿ÀÈÄ 02:32:01
 * Author: KHJ
 */

 #include <mega128.h>
 #include <delay.h>
 #define SMOTOR PORTE
 void setting();
 void main(void) {                 
    unsigned short count,counts;          
    DDRE = 0x0f;
    SMOTOR = 0x03;
    SMOTOR = 0x01;
    for(count = 0; count < 5; count++) {
        SMOTOR.2 = 1;
        delay_ms(75);
        SMOTOR.2 = 0;
        delay_ms(75);       
    }
    delay_ms(200);
    SMOTOR = 0x03;
    for(counts = 0; counts <3; counts++) {
        for(count = 0; count < 360; count++) {
            SMOTOR.2 = 1;
            delay_ms(100);
            SMOTOR.2 = 0;
            delay_ms(100);       
        }
        SMOTOR = 0x01;
        delay_ms(100);
        for(count = 0; count < 360; count++) {
            SMOTOR.2 = 1;
            delay_ms(100);
            SMOTOR.2 = 0;
            delay_ms(100);
        }
    }
 }