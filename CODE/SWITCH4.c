/* SWITCH4.c
 * 
 * Created  2018-03-27 ¿ÀÈÄ 12:15:01           
 * Author: KHJ
 */
 #include <mega128.h>
 #include <delay.h>
 
 void main() {
    char On_Off;
    DDRA = 0xff;
    DDRC = 0x00;
    while(1) {
        switch(PINC) {
        case 0: PORTA = 0x0f;
                delay_ms(200);
                PORTA = 0xf0;
                delay_ms(200);
                break;
        case 1: PORTA = 0x01;
                while(PINC == 1) {
                    delay_ms(150);
                    PORTA = PORTA << 1;
                    if(PINC == 2) {
                        for(;;) {
                            if(PINC != 2) {
                                break;
                            }
                        }
                    }
                    if(PORTA == 0x00) {
                        PORTA = 0x01;
                    }
                }
                break;
                
        case 2: break;
        
        case 3: for(On_Off = 0; On_Off < 5; On_Off++) {
                    PORTA = 0x00;
                    delay_ms(200);
                    PORTA = 0xff;
                    delay_ms(200);
                }
                break;
               
        }
        if(On_Off < 5) {
            while(1); {
                if(PINC != 3) {
                    break;
                }
            }
        }
    }
 }