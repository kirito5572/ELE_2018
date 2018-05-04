/*
 * STEP_UNI4_1.c
 *
 * Created: 2018-05-01 ¿ÀÈÄ 2:53:19
 * Author: KHJ
 */

#include <mega128.h>
#include <delay.h>
#define Dtime 200
#define Angle 360
void main(void)
{
    unsigned char i,angle;
    DDRB = 0x0f;
    angle = Angle/1.8/4;
    for (i=0;i<angle;i++) {
        PORTB = 0x09;
        delay_ms(Dtime);
        PORTB = 0x05;
        delay_ms(Dtime);
        PORTB = 0x06;
        delay_ms(Dtime);
        PORTB = 0x0a;
        delay_ms(Dtime);    
    }
}