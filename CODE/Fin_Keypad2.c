#include <mega128.h>
#include <delay.h>
unsigned int count;
unsigned char key_scan[4] = {0x10, 0x20, 0x40, 0x80}, scan, data, sum, lcount, sdata, sta;
void FND();
void scanning();
void calculator();
void cls();
void main() {
    DDRA = 0xf0;
    DDRD = 0xff;
    while(1) {
        if(sta == 0) {
            scanning();
        }
        if(sdata == 20 | sdata == 30) {
            lcount = count;
            count = 0;
            while(1) { 
                calculator();
                FND();
                if(sum != 0) {
                    cls(); 
                    break;
                }
            }
        }
        FND();
        if(sta == 1) {
            PORTA = key_scan[3];
            if(PINA.0 == 0) {
                sta = 0;
            }
        }
    }
}
void calculator() {
    scan = ++scan % 4;
    switch(scan) {
        case 0: PORTA = key_scan[scan]; data = 1; break;
        case 1: PORTA = key_scan[scan]; data = 4; break;
        case 2: PORTA = key_scan[scan]; data = 7; break;
        case 3: PORTA = key_scan[scan]; data = 10; break;
    }
    delay_ms(5);
    if(PINA.0 == 1) {
        if(sdata == 20 && data != 10) {
            count = data;
            sum = lcount + count;
        } else if (sdata == 30 && data != 10) {
            sum = lcount - count;
        } else if (data == 10){
        
        } else {
            count = data;
        }
    } else if(PINA.1 == 1) {        
        if(sdata == 20 && data != 10) {
            count = data + 1;
            sum = lcount + count;
        } else if (sdata == 30 && data != 10) {
            sum = lcount - count;
        } else if (data == 10){
        
        } else {
            count = 1 + data;
        }   
    } else if(PINA.2 == 1) {
        if(sdata == 20 && data != 10) {
            count = data + 2;
            sum = lcount + count;
        } else if (sdata == 30 && data != 10) {
            sum = lcount - count;
        } else if (data == 10){
        
        } else {
            count = 2 + data;
        }
    }
}
void scanning() {
    scan = ++scan % 4;
    switch(scan) {
        case 0: PORTA = key_scan[scan]; data = 1; break;
        case 1: PORTA = key_scan[scan]; data = 4; break;
        case 2: PORTA = key_scan[scan]; data = 7; break;
        case 3: PORTA = key_scan[scan]; data = 10; break;
    }
    delay_ms(5);   
    if(PINA.0 == 1) {
        if(data == 10) {
            sdata = 20;
        }
        else {
            count = data;
        }
    } else if(PINA.1 == 1) {
        count = 1 + data;
        if(data == 10) {
            count = 0;
        }
    } else if(PINA.2 == 1) {
        if(data == 10) {
            sdata = 30;
        } else {
            count = 2 + data;
        }
    } else {
        sdata = 40;
    }
}
void FND() {
    unsigned char st,nd,rd,th;
    st = count % 10;
    nd = lcount % 10;
    rd = sum % 10;
    th = (sum / 10) % 10;
    PORTD = 0x70 | st;
    delay_ms(5);
    PORTD = 0xb0 | nd;
    delay_ms(5);
    PORTD = 0xd0 | rd;
    delay_ms(5);
    PORTD = 0xe0 | th;
    delay_ms(5);   
}
void cls() {
    while(sta == 0) {
        scan = ++scan % 4;
        switch(scan) {
            case 0: PORTA = key_scan[scan]; data = 1; break;
            case 1: PORTA = key_scan[scan]; data = 4; break;
            case 2: PORTA = key_scan[scan]; data = 7; break;
            case 3: PORTA = key_scan[scan]; data = 10; break;
        }
        delay_ms(5);   
        if(PINA.0 == 1) {
            if(data == 10) {
                sta = 1;
            }
        } else if(PINA.2 == 1) {
            if(data == 10) {
                sta = 1;
            }
        } FND();
    }
    scan = 0;
    data = 0;
    sum = 0;
    lcount = 0;
    sdata = 0;
    count = 0;    
}