/* SWITCH2.c
 * �պ����� On�Ǿ��� LED�� �̵�������,
    DIP S/W�� �̿��� �̵��Ǵ� �ӵ��� �����ϵ��� �ϴ� ���α׷�
 * Created  2018-03-26 ���� 14:24:17           
 * Author: KHJ
 */
 #include <mega128.h>
 #include <delay.h>
 
 void main() {
    unsigned char turn = 0;
    unsigned short delay_time = 1;
    DDRA = 0xff;
    DDRC = 0x00;
    PORTA = 0x01;
    while(1) {
        for(;turn < 7;turn++) {
            PORTA = PORTA << 1;
            if(PINC != 0) {
                delay_time = PINC*10;
                }
            delay_ms(delay_time); 
            }
        for(;turn > 0; turn--) {
            PORTA = PORTA >> 1;
            if(PINC != 0) {
                delay_time = PINC*10;
                }
            delay_ms(delay_time);
            }
        }
 }