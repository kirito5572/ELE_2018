/*
 * serial3_8.c
 *
 * Created: 2018-09-13 ¿ÀÀü 10:21:24
 * Author: Administrator
 */
unsigned char rx, PORTAnum[8], PORTAnumchar;
#include <mega128.h>
#include <delay.h>

#define CMD_WRITE 0xfe;
#define DATA_WRITE 0xff;
#define LCD_EN 0x40;
void LCD_cmd_write(char cmd) {
    PORTG = CMD_WRITE;
    PORTD = cmd;
    PORTG = PORTG^LCD_EN;
    delay_ms(2);
}
void LCD_data_write(char data) {
    PORTG = DATA_WRITE;
    PORTD = data;
    PORTG = PORTG^LCD_EN;
    delay_ms(2);
}
void init_lcd() {
    delay_ms(15);
    LCD_cmd_write(0x38);
    delay_ms(5);
    LCD_cmd_write(0x38);
    delay_us(100);
    LCD_cmd_write(0x38);
    LCD_cmd_write(0x08);
    LCD_cmd_write(0x01);
    LCD_cmd_write(0x06);
    LCD_cmd_write(0x0c);
}
void Putch(char data) {
    while(!(UCSR0A & 0x20));
    UDR0 = data;
}
char Getch(void) {
    while(!(UCSR0A & 0x80));
    rx = UDR0;
    return UDR0;
}
void PORTAnumadder(void) {
    unsigned char i = 0;
    PORTAnumchar = 0;
    for(i = 0; i < 8; i++) {
        if(PORTAnum[i] == 1) {
            switch(i) {
                case 0: PORTAnumchar = 1; break;
                case 1: PORTAnumchar += 2; break;
                case 2: PORTAnumchar += 4; break;
                case 3: PORTAnumchar += 8; break;
                case 4: PORTAnumchar += 16; break;
                case 5: PORTAnumchar += 32; break;
                case 6: PORTAnumchar += 64; break;
                case 7: PORTAnumchar += 128; break;
            }
        }            
    }
}
void main(void) {
    unsigned char i;
    DDRA = 0xff;
    DDRB = 0xff;
    DDRD = 0xff;
    init_lcd();     
    UCSR0A = 0x00;
    UCSR0B = 0x18;
    UCSR0C = 0x06;
    UBRR0H = 0;
    UBRR0L = 51;
    SREG = 0x80;
    while (1) {
        Getch();
        switch(rx) {
            case 65: PORTAnum[0] = 1; break;
            case 66: PORTAnum[1] = 1; break;
            case 67: PORTAnum[2] = 1; break;
            case 68: PORTAnum[3] = 1; break;
            case 69: PORTAnum[4] = 1; break;
            case 70: PORTAnum[5] = 1; break;
            case 71: PORTAnum[6] = 1; break;
            case 72: PORTAnum[7] = 1; break;
        }
        switch(rx) {
            case 97: PORTAnum[0] = 0; break;
            case 98: PORTAnum[1] = 0; break;
            case 99: PORTAnum[2] = 0; break;
            case 100: PORTAnum[3] = 0; break;
            case 101: PORTAnum[4] = 0; break;
            case 102: PORTAnum[5] = 0; break;
            case 103: PORTAnum[6] = 0; break;
            case 104: PORTAnum[7] = 0; break;
        }
        PORTAnumadder();
        LCD_cmd_write(0x01);
        LCD_cmd_write(0x82);
        lcd_putsf("Lamp Control");
        lcd_gotoxy(0,1);
        for(i = 0; i < 8; i++) {
            if(PORTAnum[i] != 0) {
                lcd_putchar(i + '0');
                lcd_putchar(',');
            } 
            PORTA = PORTAnumchar;
        }    
    }
}