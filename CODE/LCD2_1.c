#include <mega128.h>
#include <delay.h>
unsigned char data;
void write_cmd(char cmd) {
    PORTG = 0xfc;
    PORTD = cmd;
    PORTG = PORTG ^ 0x04;
    delay_ms(2);
}
void write_data(char data) {
    PORTG = 0xfd;
    PORTD = data;
    PORTG = PORTG ^ 0x04;
    delay_ms(2);
}
void init_LCD(void) {
    delay_ms(15);
    write_cmd(0x38);
    write_cmd(0x0c);
    write_cmd(0x06);
}
void LCD_String(char flash *str) {  
    char flash *pstr = 0;
    pstr = str;
    while(*pstr) { write_data(*pstr++);}
}
void write_num(void) {
    unsigned char st, nd, rd;
    write_cmd(0xc0);
    st = data % 10;
    nd = (data / 10) % 10;
    rd = (data / 100) % 10;
    LCD_String("      ");
    write_data(rd + '0');
    write_data(nd + '0');
    write_data(st + '0');
}
void main(void) {
    ADMUX = 0x20;
    SREG = 0x80;
    DDRF = 0x00;
    DDRA = 0xff;
    DDRG = 0x0f;
    DDRD = 0xff;
    PORTD = 0xff;
    PORTG = 0xff;
    init_LCD();
    write_cmd(0x80);
    LCD_String("-A/D CONVERTION-");
    do {
        write_num();
        ADCSRA = 0x8f;
        ADCSRA = 0xcf;
        delay_ms(5);
    }while(1);
}
interrupt [ADC_INT] void ADCinter(void) {
    data = ADCH;
    PORTA = data;    
}
