/*
 * STEP_Motor3.c
 * 
 * Created: 2018-04-24 ¿ÀÈÄ 01:53:26
 * Author: KHJ
 */

 #include <mega128.h>
 #include <delay.h>
 #define SMOTOR PORTE
 void setting();
 void main(void) {                 
    unsigned short count;          
    DDRE = 0x0f;
    SMOTOR = 0x00;
    DDRD = 0xff;
    SMOTOR = 0x01;
    for(count = 0; count < 5; count++) {
        SMOTOR.2 = 1;
        delay_ms(75);
        SMOTOR.2 = 0;
        delay_ms(75);       
    }
    delay_ms(200);
    while(1) {
            SMOTOR = 0x00;
            PORTD = 0x70 | 1;
            for(count = 0; count < 180; count++) {
                SMOTOR.2 = 1;
                delay_ms(200);
                SMOTOR.2 = 0;
                delay_ms(200);       
            }
            SMOTOR = 0x02;
            delay_ms(2000);
            PORTD = 0x70 | 2;
            for(count = 0; count < 90; count++) {
                SMOTOR.2 = 1;
                delay_ms(200);
                SMOTOR.2 = 0;
                delay_ms(200);
            }
            SMOTOR = 0x00;
            delay_ms(2000);
            PORTD = 0x70 | 3;
            for(count = 0; count < 90; count++) {
                SMOTOR.2 = 1;
                delay_ms(200);
                SMOTOR.2 = 0;
                delay_ms(200);       
            }
            SMOTOR = 0x02;
            delay_ms(2000);
            PORTD = 0x70 | 4;
            for(count = 0; count < 180; count++) {
                SMOTOR.2 = 1;
                delay_ms(200);
                SMOTOR.2 = 0;
                delay_ms(200);
            }
            SMOTOR = 0x00;
            delay_ms(2000);
    }
 }
 