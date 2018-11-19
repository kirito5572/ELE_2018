#include <mega128.h>
// Alphanumeric LCD functions
#include <lcd.h>
#asm
.equ __lcd_port = 0x12 ; // PORTD
#endasm
#include <delay.h>
typedef unsigned char byte;
byte num_1st,num_2nd,num_3rd,num_4th;  
void init();
void main() {
    init();
    lcd_init(16);
    lcd_clear();
    lcd_gotoxy(0,0);
    lcd_putsf("-A/D CONVERSION-");
    lcd_gotoxy(0,1);
    lcd_putsf("10BIT DEC->");
    while(1) {
        ADCSRA = 0xcf;
        delay_ms(5);
        ADCSRA = 0x8f;
        lcd_gotoxy(11,1);
        lcd_putchar(num_4th + '0');
        lcd_putchar(num_3rd + '0');
        lcd_putchar(num_2nd + '0');
        lcd_putchar(num_1st + '0');
    }
}
void init() {
    DDRD = 0xff;
    DDRF = 0x00;
    ADMUX = 0x00;
    ADCSRA = 0x8f;
    SREG = 0x80;
}
interrupt [ADC_INT] void ADCinter(void) {
    int count = 0;
    count = ADCW & 0x3ff;
    num_1st = count % 10;
    num_2nd = (count / 10) % 10;
    num_3rd = (count / 100) % 10;
    num_4th = (count / 1000) % 10;
}