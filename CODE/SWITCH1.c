/* SWITCH1.c
 * DIP S/W�� ���¸� PORTC�� �Է� �ް�,
   PORTC�� ���¸� �״�� PORTA�� LED�� �����ϴ� ���α׷�
 * Created  2018-03-26 ���� 13:53:17           
 * Author: KHJ
 */
 #include <mega128.h>
 #include <delay.h>
 
 void main(){
    DDRA=0xff;
    DDRC=0x00;
    while(1) {
        PORTA = PINC;
        delay_ms(200);
        }
 }