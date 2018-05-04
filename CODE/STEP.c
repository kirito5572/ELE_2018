 #include <mega128.h>
 #include <delay.h>
 #define SMOTOR PORTE
void setting() {
    unsigned char count;
        SMOTOR = 0x01;
    for(count = 0; count < 5; count++) {
        SMOTOR.2 = 1;
        delay_ms(75);
        SMOTOR.2 = 0;
        delay_ms(75);       
    }
    delay_ms(200);
}