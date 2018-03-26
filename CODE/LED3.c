/* LED3.c
 * ��Ʈ(bit) �̵� �����ڸ� �̿��� LED �̵� ������ LED 8�� ��
   ������Ʈ(PORTA.0) �ϳ����� On��Ű�� On�Ǿ��� LED��
   ������Ʈ �������� �̵��ϴ� �����̴�. �ݺ����� ��Ʈ(bit)
   �̵� �����ڸ� �̿��� �� ��Ʈ(bit) �� �����͸� �̵����� ����.
   
 * Created  2018-03-20 ���� 13:56:50           
 * Author: KHJ
 */
 
 #include <mega128.h>
 #include <delay.h>
 
 void main(){
    int turn; 
    DDRA = 0xff;
    PORTA = 0x01;
    while(1){ 
        for (turn = 0; turn < 7; turn++){
            delay_ms(200);
            PORTA = PORTA << 1;
            }
        for (; turn > 0; turn--){
            delay_ms(200);
            PORTA = PORTA >> 1;
            }
        }
 }          