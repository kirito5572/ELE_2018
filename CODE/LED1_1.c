/* LED1_1.c
 * ���� LED 4���� ���� LED 4���� On�� Off�� ������
 ���鼭 �ݺ��ϴ� ���α׷��̴�.
 * Created  2018-03-19 ���� 15:16:05           
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