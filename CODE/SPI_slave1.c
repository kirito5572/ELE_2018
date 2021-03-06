#include <mega128.h>
#include <spi.h>
#include <delay.h>
unsigned char master_data, slave_data = 0xff, tmp;
void main(void) {    
    // SPI initialization
    // SPI Type: Slave
    // SPI Clock Rate: 4000.000 kHz
    // SPI Clock Phase: Cycle Start
    // SPI Clock Polarity: Low
    // SPI Data Order: MSB First
    SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
    SPSR=(0<<SPI2X);
    TCCR0 = 0x47;
    TCNT0 = 0x00;
    TIMSK = 0x01;
    SREG = 0x80;
    DDRA = 0xff;
    DDRB = 0x0f;
    while (1) {
        master_data = SPDR;
        delay_ms(1);
        SPDR = slave_data;
        PORTA = master_data;
        while(!(SPSR & 0x80));
    }
}
interrupt [TIM0_OVF] void change(void) {
    tmp++;
    if(t == 10) {
        slave_data = slave_data ^ 0xff;
        tmp = 0;
    }
}
