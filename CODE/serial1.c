/*
 * serial1.c
 *
 * Created: 2018-09-13 ¿ÀÀü 10:21:24
 * Author: Administrator
 */

#include <mega128.h>
void Putch(char data) {
    while(!(UCSR0A & 0x20));
    UDR0 = data;
}

char Getch(void) {
    while(!(UCSR0A & 0x80));
    return UDR0;
}
void main(void) {     
    UCSR0A = 0x00;
    UCSR0B = 0x18;
    UCSR0C = 0x06;
    UBRR0H = 0;
    UBRR0L = 51;
    while (1) {
        Putch(Getch() + 1);
    }
}
