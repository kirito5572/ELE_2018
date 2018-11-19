/*
 * LCD_4BIT1.c
 *
 * Created: 2018-08-30 ¿ÀÈÄ 8:27:49
 * Author: Administrator
 */
#include <mega128.h>
// Alphanumeric LCD functions
#include <lcd.h>
#asm
.equ __lcd_port = 0x12 ; // PORTD
#endasm
// Declare your global variables here

//or

//#include <alcd.h>
void main(void) {
    DDRD = 0xff;
    lcd_init(16);
    
    lcd_clear();
    lcd_gotoxy(3,0);
    lcd_putsf("ATMEGA 128");
    lcd_gotoxy(3,1);
    lcd_putsf("KIM HYEOKJIN");
       
        
}