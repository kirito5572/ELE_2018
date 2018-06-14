/*
 * Timer3_4.c
 *
 * Created: 2018-06-05 ¿ÀÈÄ 01:55:08
 * Author: KHJ
 */

#include <mega128.h>
#include <delay.h>
unsigned char FNDcount,flag = 1;
unsigned int count;
void FND();
void main(void) {
    DDRA = 0xff;
    DDRD = 0xff;
    TIMSK = 0x40;
    TCCR2 = 0x03;
    TCNT2 = 0x00;
    EICRB = 0x80;
    EIMSK = 0x80;
    EIFR = 0x00;
    SREG = 0x80;
    while (1) {
        FND();
    }
}
interrupt [TIM2_OVF] void overflow2(void)
{   
    if(flag == 1) {
        count++;
        if(count == 977) {
            FNDcount++;
            if(FNDcount == 10) {
                FNDcount = 0;
            }
            count = 0;
        }
    }
}
interrupt [EXT_INT7] void flag_inter(void)
{
     flag ^= 1;
}
void FND(){
    unsigned char st;
    st = FNDcount%10;
    PORTD = 0x70 | st;
    delay_ms(2);
}