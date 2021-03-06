/* SWITCH3.c
 * 왕복으로 On되어진 LED를 이동하지만,
    PORTC.0을 눌렀을때 현재상태 멈춤
    PORTC.1을 눌렀을때 현재상태부터 다시 이동
 * Created  2018-03-26 오후 14:53:50           
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