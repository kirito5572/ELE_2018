/*
 * STEP_Motor4.c
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
    SMOTOR = 0x01;
    for(count = 0; count < 5; count++) {
        SMOTOR.2 = 1;
        delay_ms(150);
        SMOTOR.2 = 0;
        delay_ms(150);       
    }
    delay_ms(200);
    SMOTOR = 0x02;
    DDRD = 0xff;
    while(1) {
        PORTD = 0x71;
        for(count = 0; count < 90; count++) {
            SMOTOR.2 = 1;
            delay_ms(200);
            SMOTOR.2 = 0;
            delay_ms(200);       
        }
        SMOTOR = 0x00;
        delay_ms(1000);
        PORTD = 0x70;
        for(count = 0; count < 90; count++) {
            SMOTOR.2 = 1;
            delay_ms(200);
            SMOTOR.2 = 0;
            delay_ms(200);
        }
        SMOTOR = 0x02;
        delay_ms(1000);
        PORTD = 0x72;
        for(count = 0; count < 180; count++) {
            SMOTOR.2 = 1;
            delay_ms(200);
            SMOTOR.2 = 0;
            delay_ms(200);       
        }
        SMOTOR = 0x00;
        delay_ms(1000);
        PORTD = 0x70;
        for(count = 0; count < 1800; count++) {
            SMOTOR.2 = 1;
            delay_ms(200);
            SMOTOR.2 = 0;
            delay_ms(200);
        }
        SMOTOR = 0x02;
        delay_ms(1000);
    }
 }