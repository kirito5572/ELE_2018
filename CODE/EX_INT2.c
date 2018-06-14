/*
 * EX_INT2.c
 *
 * Created: 2018-05-29 ¿ÀÈÄ 2:16:27
 * Author: KHJ
 */

#include <mega128.h>
void main(void) {
    DDRB = 0xff;
    EICRA = 0x00;
    EICRB = 0x2a;
    EIMSK = 0x70;
    EIFR = 0x00;
    SREG = 0x80;
    while (1) {
    
    }
}
interrupt [EXT_INT4] void MOTERCW (void)
{
     PORTB = 0x20;
}
interrupt [EXT_INT5] void MOTORSTOP (void)
{
     PORTB = 0x00;
}
interrupt [EXT_INT6] void MOTORCCW (void)
{
     PORTB = 0x10;
}