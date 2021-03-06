
#include <mega128.h>

// SPI functions
#include <spi.h>

// Declare your global variables here

// Standard Input/Output functions
#include <stdio.h>

unsigned char USART_Receive( void );        /* 반환형이 unsigned char인 함수 */
void SPI_MasterTransmit(unsigned char cData);  /* 반환형이 void이나 함수 호출시에 입력값이 있는 함수 */

void main(void)
{
    DDRB = 0x0f;     //SPI통신 출력 설정
    
    //위저드 사용으로 초기화
    // USART0 initialization
    // Communication Parameters: 8 Data, 1 Stop, No Parity
    // USART0 Receiver: On
    // USART0 Transmitter: Off
    // USART0 Mode: Asynchronous
    // USART0 Baud Rate: 9600
    UCSR0A=(0<<RXC0) | (0<<TXC0) | (0<<UDRE0) | (0<<FE0) | (0<<DOR0) | (0<<UPE0) | (0<<U2X0) | (0<<MPCM0);
    UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (1<<RXEN0) | (0<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);
    UCSR0C=(0<<UMSEL0) | (0<<UPM01) | (0<<UPM00) | (0<<USBS0) | (1<<UCSZ01) | (1<<UCSZ00) | (0<<UCPOL0);
    UBRR0H=0x00;
    UBRR0L=0x67;


    // SPI initialization
    // SPI Type: Master
    // SPI Clock Rate: 125.000 kHz
    // SPI Clock Phase: Cycle Start
    // SPI Clock Polarity: Low
    // SPI Data Order: MSB First
    SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (0<<CPHA) | (1<<SPR1) | (1<<SPR0);
    SPSR=(0<<SPI2X);


    while (1) {
        SPI_MasterTransmit(USART_Receive());    
    }
}
unsigned char USART_Receive( void ) {   //데이터 시트에 있는 함수
    /* 데이터 수신시까지 대기 하는 코드 */
    while ( !(UCSR0A & (1<<RXC0)) )         /*데이터 수신이 완료될경우, RXC0가 1이 된다.*/
    ;
    /* 수신이 완료된 데이터를 이 함수를 호출한 곳으로 반환한다. */
    return UDR0;
}
void SPI_MasterTransmit(unsigned char cData) {     //데이터 시트에 있는 함수
    /* 전송 시작 코드 */
    SPDR = cData;
    /* 전송이 완료될때까지 대기 */
    while(!(SPSR & (1<<SPIF)))
    ;
}
