/* LED2.c
 * 비트(bit) 이동 연산자를 이용한 LED 이동 실험은 LED 8개 중
   하위비트(PORTA.0) 하나만을 On시키고 On되어진 LED가
   상위비트 방향으로 이동하는 내용이다. 반복문과 비트(bit)
   이동 연산자를 이용해 한 비트(bit) 씩 데이터를 이동시켜 보자.
 * Created  2018-03-20 오후 12:03:30           
 * Author: KHJ
 */                                  
 
 #include <mega128.h>
 #include <delay.h>
 
 void main(){
    DDRA = 0xff;
    PORTA = 0x01;
    
    while(1){
        delay_ms(200);  
        PORTA = (PORTA << 1);
        if(PORTA == 0x00) {
            PORTA = 0x01;
            }
        }
 }       
        