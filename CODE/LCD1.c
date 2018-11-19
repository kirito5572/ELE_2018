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
void main(void) {
    DDRG = 0x0f;
    DDRD = 0xff;
    PORTD = 0xff;
    PORTG = 0xff;
    init_LCD();
    write_cmd(0x80);
    write_data('-');
    write_data('A');
    write_data('T');
    write_data('M');
    write_data('E');
    write_data('G');
    write_data('A');
    write_data('1');
    write_data('2');
    write_data('8');
    write_data(' ');
    write_data('T');
    write_data('E');
    write_data('S');
    write_data('T');
    write_data('-');
    write_cmd(0xc0);
    write_data('-');
    write_data(' ');
    write_data('K');
    write_data('i');
    write_data('m');
    write_data(' ');
    write_data('H');
    write_data('y');
    write_data('e');
    write_data('o');
    write_data('k');
    write_data('j');
    write_data('i');
    write_data('n');
    write_data(' ');
    write_data('-');
    while(1);
}
