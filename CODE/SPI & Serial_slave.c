#include <mega128.h>

// SPI functions
#include <spi.h>

// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here
char SPI_SlaveReceive(void);         //char형을 반환하는 함수

unsigned char x, y;        //lcd의 x,y를 결정하는 함수

void main(void)
{

    //위저드 설정

    // SPI 초기화
    // SPI 타입: Slave
    // SPI 클럭 속도: 125.000 kHz
    // SPI Clock Phase: Cycle Start
    // SPI Clock Polarity: Low
    // SPI Data Order: MSB First
    SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
    SPSR=(0<<SPI2X);

    // Alphanumeric LCD initialization
    // Connections are specified in the
    // Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
    // RS - PORTA Bit 0
    // RD - PORTA Bit 1
    // EN - PORTA Bit 2
    // D4 - PORTA Bit 4
    // D5 - PORTA Bit 5
    // D6 - PORTA Bit 6
    // D7 - PORTA Bit 7
    // Characters/line: 16
    
    //LCD는 포트A에 연결 
    //asm을 사용했을경우 0x12가 아닌 0x1b를 넣으면 PORTD가 아닌 PORTA로 설정됨. 자세한 사항은 mega128.h참조
    lcd_init(16);               //LCD 초기화

    while (1) {
        unsigned char data;      //전송받은 데이터를 넣을 변수 선언
        data = SPI_SlaveReceive();          //데이터 수신
        if(x == 16) {                       //X열 Y열 설정
            x = 0;                          //X열이 16이상 없으므로 16이 될경우 y를 0->1 혹은 1->0으로만 변경
            y++;                            //하면 되므로, x가 16일때 y가 1증가하며 y가 2를 넘지 않으므로 2가
            if(y == 2) {                    //되면 y도 0이 되며 LCD가 초기화 된다.
                y = 0;
                lcd_clear();
            }
        }
        if(data == 0x08) { //backspace
            x--;                            //BACKSPACE키를 누를경우 LCD화면에서도 BACKSPACE기능이 동작하도록
            if(x > 250 ) x = 0;             //짠 코드이나, 수행에는 이런거 안나오니 공부 안할꺼면 넘어가도됨
            lcd_gotoxy(x,y);
            lcd_putchar(data);
            x--;
        }
        else {                              //BACKSPACE이외의 코드가 들어온 경우(문자가 입력되야 하는 경우)
            lcd_gotoxy(x,y);                //X,Y 위치 설정
            lcd_putchar(data);              //데이터 출력
        }
        
        x++;                                //문자가 입력됬으니, X값을 증가시켜서 다음칸에 문자가 입력되게 해야함.
        
        if(data == 0x0d) { //enter
            y++;                            //ENTER키를 누를경우 X값에 상관없이 다음줄로 넘어가도록 하는 코드
            x = 0;                          //이 코드 역시 수행에는 영향이 없다.
            if(y == 2) {
                y = 0;
                lcd_clear();
            }
        }
        else if(data == 0x1b) { //esc
            x = 0;                          //ESC키를 누를경우 어느위치던지, LCD가 리셋되게 하는 코드
            y = 0;                          //이 코드 역시 수행에는 영향이 없다.
            lcd_clear();
        }
    }
}
char SPI_SlaveReceive(void) {               //데이터 시트 코드 복사
    /* Wait for reception complete */
    while(!(SPSR & (1<<SPIF)))
    ;
    
    /* Return data register */
    return SPDR;
}
