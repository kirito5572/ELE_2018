/*******************************************************
This program was created by the CodeWizardAVR V3.32a 
Automatic Program Generator
� Copyright 1998-2017 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 2018-11-30
Author  : 
Company : 
Comments: 


Chip type               : ATmega128
Program type            : Application
AVR Core Clock frequency: 16.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 1024
*******************************************************/

#include <mega128.h>

// SPI functions
#include <spi.h>

// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here

unsigned char SPI_Receive(void);
void led_a();
void led_b();
void led_c();
void led_d();
unsigned char data, b, c;

void main(void) {
    unsigned char x = 0, y = 0;
    
    // Port B initialization
    // Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=Out Bit2=In Bit1=In Bit0=In 
    DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (1<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
    // State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=0 Bit2=T Bit1=T Bit0=T 
    PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0); 
    
    DDRD = 0x0f;
    
    // SPI initialization
    // SPI Type: Slave
    // SPI Clock Rate: 4000.000 kHz
    // SPI Clock Phase: Cycle Start
    // SPI Clock Polarity: Low
    // SPI Data Order: MSB First
    SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
    SPSR=(0<<SPI2X);

    // Alphanumeric LCD initialization
    // Connections are specified in the
    // Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
    // RS - PORTA Bit 0
    // RD - PORTA Bit 1
    // EN - PORTA Bit 2
    // D4 - PORTA Bit 4
    // D5 - PORTA Bit 5
    // D6 - PORTA Bit 6
    // D7 - PORTA Bit 7
    // Characters/line: 16
    lcd_init(16);
    while (1) {
        data = SPI_Receive();
        if(x == 16) {
            x = 0;
            y++;
            if(y == 2) {
                y = 0;
            }            
        }
        lcd_gotoxy(x,y);
        lcd_putchar(data);
        if(data == 'a') {
            led_a();
        }
        else if(data == 'b') {
            led_b();
        }
        else if(data == 'c') {
            led_c();
        }
        else if(data == 'd') {
            led_d();
        }
        x++;
    }
}
unsigned char SPI_Receive(void) {
    while( !(SPSR & (1<<SPIF)));

    return SPDR;
}
void led_a() {
    PORTD = 0x0f;
}
void led_b() {
    if(b % 2)
        PORTD = 0x03;
    else
        PORTD = 0x0c;
    b++;
}
void led_c() {
    switch (c)
           {
           case 0 : PORTD = 0x01;

           break;

           case 1 : PORTD = 0x02;

           break;
           
           case 2 : PORTD = 0x04;

           break;

           case 3 : PORTD = 0x08;

           break;
           }
    c++;
    if(c >= 4) 
    c = 0;
}
void led_d() {
    PORTD = 0x00;
}