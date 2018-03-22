/* LED1_1.c
 * 상위 LED 4개와 하위 LED 4개를 On과 Off를 번갈아
 가면서 반복하는 프로그램이다.
 * Created  2018-03-19 오후 15:16:05           
 * Author: KHJ
 */          

#include <mega128.h>
#include <delay.h>

void main()
{
    DDRA = 0xff;
    
    while(1){
        PORTA = 0x0f;
        delay_ms(200);
        PORTA = 0xf0;
        delay_ms(200);
        }
}