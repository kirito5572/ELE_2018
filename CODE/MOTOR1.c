/*
 * MOTOR1.c
 * 모터를 정방향으로 회전시키기
 * Created: 2018-04-16 오후 12:23:59
 * Author: KHJ
 */

#include <mega128.h>
#include <delay.h>
void main(void) {
    DDRB = 0xf0;
    while (1) {
        PORTB = 0b00100000;
        delay_ms(1000);
        PORTB = 0b00000000;
    }
}
