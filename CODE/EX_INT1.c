/*
 * EX_INT1.c
 *
 * Created: 2018-05-29 ¿ÀÈÄ 2:41:01
 * Author: KHJ
 */

#include <mega128.h>
void main(void) {
    DDRA = 0xff;
    DDRE = 0x00;
    EICRA = 0x00;
    EICRB = 0x02;
    EIMSK = 0x10;
    EIFR = 0x00;
    SREG = 0x80;
    PORTA = 0xff;
    while (1) {
    
    }
}
interrupt [EXT_INT4] void LEDS (void)
{
     PORTA ^= 0xff;
}
