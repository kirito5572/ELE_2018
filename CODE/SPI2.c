#include <mega128.h>
#include <spi.h>
#include <delay.h>
#include <alcd.h>
unsigned int temp1, temp2;
unsigned int temp;
void main(void) {
    // SPI initialization
    // SPI Type: Master
    // SPI Clock Rate: 125.000 kHz
    // SPI Clock Phase: Cycle Start
    // SPI Clock Polarity: Low
    // SPI Data Order: MSB First
    SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (0<<CPHA) | (1<<SPR1) | (1<<SPR0);
    SPSR=(0<<SPI2X);
    DDRB = 0x0f;
    DDRD = 0xff;
    lcd_init(16);
    lcd_clear();
    lcd_gotoxy(6,0);
    lcd_putsf("SPI"); 
    while (1) {
        temp1 = 0;
        temp2 = 0;
        PORTB.0 = 0;
        SPDR = 0xff;
        while(!(SPSR & 0x80));
        temp1 = SPDR;
        temp2 = SPDR;
        delay_ms(1);
        PORTB.0 = 1;  
        temp = 0;
        temp = ((temp1 << 8) & 0xff00) | (temp2 & 0x00ff);
        temp = (((temp >> 3) * 0.0625));
        lcd_gotoxy(6,1);
        lcd_putchar((temp/100)%10 + '0');
        lcd_putchar((temp/10)%10 + '0');
        lcd_putchar(temp%10 + '0');
        delay_ms(1);      
    }
}
