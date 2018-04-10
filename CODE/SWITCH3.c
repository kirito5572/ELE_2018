/* SWITCH3.c
 * �պ����� On�Ǿ��� LED�� �̵�������,
    PORTC.0�� �������� ������� ����
    PORTC.1�� �������� ������º��� �ٽ� �̵�
 * Created  2018-03-26 ���� 14:53:50           
 * Author: KHJ
 */
 #include <mega128.h>
 #include <delay.h>
 
 void main() {
    unsigned char turn = 0;
    DDRA = 0xff;
    DDRC = 0x00;
    PORTA = 0x01;
    while(1) {
        for(;turn < 7;turn++) {
            PORTA = PORTA << 1;
            if(PINC.0 == 1) {
                for(;;) {
                    if(PINC.1 == 1) {
                        break;
                    }
                }
            }
            delay_ms(150); 
        }
        for(;turn > 0; turn--) {
            PORTA = PORTA >> 1;
            if(PINC.0 == 1) {
                for(;;) {
                    if(PINC.1 == 1) {
                        break;
                    }
                }
            }
            delay_ms(150);
        }
    }
 }