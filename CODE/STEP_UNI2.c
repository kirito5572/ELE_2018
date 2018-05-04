/*
 * STEP_UNI2.c
 *
 * Created: 2018-05-01 ¿ÀÈÄ 2:34:02
 * Author: KHJ
 */

#include <mega128.h>
#include <delay.h>
#define Dtime 500
void main(void)
{
    DDRB = 0x0f;
    while (1) {
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