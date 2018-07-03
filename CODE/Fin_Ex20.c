#include <mega128.h>
#include <delay.h>
void main() {
    DDRB = 0xff;
    EIMSK = 0x70;
    EICRB = 0x2a;
    SREG = 0x80;
    while(1);
}
interrupt [EXT_INT4] void inter4(void) {
    PORTB = 0x20;
}
interrupt [EXT_INT5] void inter5(void) {
    PORTB = 0x00;
}
interrupt [EXT_INT6] void inter6(void) {
    PORTB = 0x10;
}