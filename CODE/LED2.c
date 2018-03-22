/* LED2.c
 * ��Ʈ(bit) �̵� �����ڸ� �̿��� LED �̵� ������ LED 8�� ��
   ������Ʈ(PORTA.0) �ϳ����� On��Ű�� On�Ǿ��� LED��
   ������Ʈ �������� �̵��ϴ� �����̴�. �ݺ����� ��Ʈ(bit)
   �̵� �����ڸ� �̿��� �� ��Ʈ(bit) �� �����͸� �̵����� ����.
 * Created  2018-03-20 ���� 12:03:30           
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
        