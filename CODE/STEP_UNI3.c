/*
 * STEP_UNI3.c
 *
 * Created: 2018-05-01 ¿ÀÈÄ 2:36:43
 * Author: KHJ
 */

#include <mega128.h>
#include <delay.h>
#define Dtime 500
void main(void)
{
    unsigned char S1_2[8]={0x01,0x05,0x04,0x06,0x02,0x0a,0x08,0x09},i;
    DDRB = 0x0f;
    while (1) {
        for(i = 0; i <8; i++) {
            PORTB = S1_2[i];
            delay_ms(Dtime);
        }    
    }
}