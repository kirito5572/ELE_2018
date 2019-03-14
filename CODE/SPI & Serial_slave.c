#include <mega128.h>

// SPI functions
#include <spi.h>

// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here
char SPI_SlaveReceive(void);         //char���� ��ȯ�ϴ� �Լ�

unsigned char x, y;        //lcd�� x,y�� �����ϴ� �Լ�

void main(void)
{

    //������ ����

    // SPI �ʱ�ȭ
    // SPI Ÿ��: Slave
    // SPI Ŭ�� �ӵ�: 125.000 kHz
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
    
    //LCD�� ��ƮA�� ���� 
    //asm�� ���������� 0x12�� �ƴ� 0x1b�� ������ PORTD�� �ƴ� PORTA�� ������. �ڼ��� ������ mega128.h����
    lcd_init(16);               //LCD �ʱ�ȭ

    while (1) {
        unsigned char data;      //���۹��� �����͸� ���� ���� ����
        data = SPI_SlaveReceive();          //������ ����
        if(x == 16) {                       //X�� Y�� ����
            x = 0;                          //X���� 16�̻� �����Ƿ� 16�� �ɰ�� y�� 0->1 Ȥ�� 1->0���θ� ����
            y++;                            //�ϸ� �ǹǷ�, x�� 16�϶� y�� 1�����ϸ� y�� 2�� ���� �����Ƿ� 2��
            if(y == 2) {                    //�Ǹ� y�� 0�� �Ǹ� LCD�� �ʱ�ȭ �ȴ�.
                y = 0;
                lcd_clear();
            }
        }
        if(data == 0x08) { //backspace
            x--;                            //BACKSPACEŰ�� ������� LCDȭ�鿡���� BACKSPACE����� �����ϵ���
            if(x > 250 ) x = 0;             //§ �ڵ��̳�, ���࿡�� �̷��� �ȳ����� ���� ���Ҳ��� �Ѿ����
            lcd_gotoxy(x,y);
            lcd_putchar(data);
            x--;
        }
        else {                              //BACKSPACE�̿��� �ڵ尡 ���� ���(���ڰ� �ԷµǾ� �ϴ� ���)
            lcd_gotoxy(x,y);                //X,Y ��ġ ����
            lcd_putchar(data);              //������ ���
        }
        
        x++;                                //���ڰ� �Է�����, X���� �������Ѽ� ����ĭ�� ���ڰ� �Էµǰ� �ؾ���.
        
        if(data == 0x0d) { //enter
            y++;                            //ENTERŰ�� ������� X���� ������� �����ٷ� �Ѿ���� �ϴ� �ڵ�
            x = 0;                          //�� �ڵ� ���� ���࿡�� ������ ����.
            if(y == 2) {
                y = 0;
                lcd_clear();
            }
        }
        else if(data == 0x1b) { //esc
            x = 0;                          //ESCŰ�� ������� �����ġ����, LCD�� ���µǰ� �ϴ� �ڵ�
            y = 0;                          //�� �ڵ� ���� ���࿡�� ������ ����.
            lcd_clear();
        }
    }
}
char SPI_SlaveReceive(void) {               //������ ��Ʈ �ڵ� ����
    /* Wait for reception complete */
    while(!(SPSR & (1<<SPIF)))
    ;
    
    /* Return data register */
    return SPDR;
}
