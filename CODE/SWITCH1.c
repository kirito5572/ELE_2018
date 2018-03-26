/* SWITCH1.c
 * DIP S/W의 상태를 PORTC로 입력 받고,
   PORTC의 상태를 그대로 PORTA의 LED로 전달하는 프로그램
 * Created  2018-03-26 오후 13:53:17           
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