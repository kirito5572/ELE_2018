#include <mega128.h>
#include <delay.h>
#define LED PORTA
  void main(void) {
    unsigned char Bits = 0xfe;
    DDRA = 0xff;
    while(1) {
        while(1) {
            LED = Bits;
            Bits <<= 1;
            Bits |= 0x01;
            delay_ms(500);
            if(Bits == 0x7f) {
                break;
            }
        }
        while(1) {
            LED = Bits;
            Bits >>= 1;
            Bits |= 0x80;
            delay_ms(500);
            if(Bits == 0xfe) {
                break;
            }
        }
    }
 }