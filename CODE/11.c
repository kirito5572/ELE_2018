#include <mega128.h>
#include <delay.h>
#define LED PORTA
 unsigned int count=0;
 unsigned char FNDC[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
 void FND();                       
 void main(void) {
    unsigned char i = 0;
    DDRA = 0xff;
    DDRC = 0x80;
    DDRF = 0xff;
    DDRG = 0x0f;
    PORTC = 0x80;
    while(1) {
        for(i=0;i<20;i++) {
            FND();
        }
        delay_ms(2);
        count++;
        if(count == 10000) {
            count = 0;
        }
        if(PINC.0 == 0) {
            while(1) {
                PORTA = 0xff;
                for(i=0;i<20;i++) {
                    FND();
                }
                if(PINC.0 == 1) {
                    break;
                }
            }
        }
    }                    
 }
 void FND() {  
    unsigned char st,nd,rd,th;
    th = (count/1000)%10;
    rd = (count/100)%10;
    nd = (count/10)%10;
    st = count%10;
    PORTG = 0b00001;
    PORTF = FNDC[th];
    delay_ms(2);
    PORTG = 0b00000;
    PORTG = 0b00010;
    PORTF = FNDC[rd];
    delay_ms(2);
    PORTG = 0b00000;
    PORTG = 0b00100;
    PORTF = FNDC[nd];
    delay_ms(2);
    PORTG = 0b00000;
    PORTG = 0b01000;
    PORTF = FNDC[st];
    delay_ms(2);
    PORTG = 0b00000;
 }
 
 