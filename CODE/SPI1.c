#include <mega128.h>
#include <spi.h>
#include <delay.h>
unsigned char master_data = 0x0f, slave_data, tmp;
void main(void) {
	// SPI initialization
	// SPI Type: Master
	// SPI Clock Rate: 125.000 kHz
	// SPI Clock Phase: Cycle Start
	// SPI Clock Polarity: Low
	// SPI Data Order: MSB First
    SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (0<<CPHA) | (1<<SPR1) | (1<<SPR0);
    SPSR=(0<<SPI2X);
    TCCR0 = 0x47;
    TCNT0 = 0x00;
    TIMSK = 0x01;
    SREG = 0x80;
    DDRA = 0xff;
    DDRB = 0x0f;
    while (1) {  
        SPDR = master_data;
        while(!(SPSR & 0x80));
        delay_ms(1);
        slave_data = SPDR;
        PORTA = slave_data;
    }
}
interrupt [TIM0_OVF] void change(void) {
    tmp++;
    if(tmp == 10) {
        master_data = master_data ^ 0xff;
        tmp = 0;
    }
}
