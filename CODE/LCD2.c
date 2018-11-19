#include <mega128.h>
#include <delay.h>
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
void main(void) {
    DDRG = 0x0f;
    DDRD = 0xff;
    PORTD = 0xff;
    PORTG = 0xff;
    init_LCD();
    write_cmd(0x80);
    LCD_String("-ATMEGA128 TEST-");
    write_cmd(0xc0);
    LCD_String("- KIM HYEOKJIN -");
    while(1);
}
