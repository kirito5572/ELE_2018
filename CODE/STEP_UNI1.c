/*
 * STEP_UNI1.c
 *
 * Created: 2018-05-01 ¿ÀÈÄ 2:25:08
 * Author: KHJ
 */

#include <mega128.h>
#include <delay.h>
#define Dtime 500
void main(void)
{
    DDRB = 0x0f;
    while (1) {
        PORTB = 0x01;
        delay_ms(Dtime);
        PORTB = 0x04;
        delay_ms(Dtime);
        PORTB = 0x02;
        delay_ms(Dtime);
        PORTB = 0x08;
        delay_ms(Dtime);    
    }
}
