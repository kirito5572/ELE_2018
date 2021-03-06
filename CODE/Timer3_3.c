/*
 * Timer3_3.c
 *
 * Created: 2018-06-05 ���� 12:41:35
 * Author: KHJ
 */

#include <mega128.h>
#include <delay.h>
unsigned char count1 = 0,count2 = 0,FNDcount1 = 0,FNDcount2 = 99;
void FND();
void main(void) {
    DDRA = 0xff;
    DDRD = 0xff;
    TIMSK = 0x41;
    TCCR0 = 0x07;
    TCNT0 = 0x00;
    TCCR2 = 0x05;
    TCNT2 = 0x00;
    SREG = 0x80;
    while (1) {
        FND();
    }
}
interrupt [TIM2_OVF] void overflow2(void)
{
    count2++;
    if(count2 == 37) {
        FNDcount2--;
        if(FNDcount2 == 0) {
            FNDcount2 = 99;
        }
        count2 = 0;
    }
}
interrupt [TIM0_OVF] void overflow(void) {
    count1++;
    if(count1 == 18) {
        FNDcount1++;
        if(FNDcount1 == 100) {
            FNDcount1 = 0;
        }
        count1 = 0;
    }
}
void FND(){
    unsigned char st1,nd1,st2,nd2;
    nd2 = (FNDcount2/10)%10;
    st2 = FNDcount2%10;
    nd1 = (FNDcount1/10)%10;
    st1 = FNDcount1%10;
    PORTD = 0x70 | st1;
    delay_ms(2);
    PORTD = 0xb0 | nd1;
    delay_ms(2);
    PORTD = 0xd0 | st2;
    delay_ms(2);
    PORTD = 0xe0 | nd2;
    delay_ms(2);
}
