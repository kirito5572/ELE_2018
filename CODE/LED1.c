/* LED1.c
 * LED On/Off ���� 1�� LED8���� ���ÿ� �Ѱ�(On), 
 ����(Off) ���� �ݺ��ϵ��� ���α׷��� �ۼ��ϰ�
 ���۽�Ű�� �����̴�.
 * Created  2018-03-19 ���� 15:05:35           
 * Author: KHJ
 */
    
 #include <mega128.h>
 #include <delay.h>
 
 void main(){
 
    DDRA = 0xff;
    
    while(1){
        PORTA = 0xff;       //LED 8�� On
        delay_ms(200);
        PORTA = 0x00;       //LED 8�� Off
        delay_ms(200);
        }
 }        