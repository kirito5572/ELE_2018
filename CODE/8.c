#include <mega128.h>
#include <delay.h>
#define LED PORTA
  void main(void) {
    unsigned char Bits = 0x00;
    DDRA = 0xff;
    DDRC = 0x00;
    DDRF = 0xff;
    PORTF = 0xff;
    while(1) {
        if(PINC == 0x02) {
            Bits = 0xfe;
            for(;;) {
                LED = Bits;
                delay_ms(500);
                Bits <<= 2;
                Bits |= 0x03;
                if(Bits == 0xff) {
                    Bits = 0xfe;
                }
                if(PINC == 0x01) {
                    break;
                }
            }
        }
        if(PINC == 0x01) {
            Bits = 0xfd;
            for(;;) {
                LED = Bits;
                delay_ms(500);
                Bits <<= 2;
                Bits |= 0x03;
                if(Bits == 0xff) {
                    Bits = 0xfd;
                }
                if(PINC == 0x02) {
                    break;
                }
            }
        }
    }
 }