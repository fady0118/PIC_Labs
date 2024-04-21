/* 7-segment display
 * File:   main.c
 * Author: fady
 *
 * Created on April 21, 2024, 9:24 PM
 */

#include <xc.h>
#include "Config.h"
#define _XTAL_FREQ 4000000

//-----------Port_Init--------------
// initializes portB and configures I/O pins
// PB0-6 as output
void Port_Init(void){
    TRISB&=~0xFF; //pins PB0-6 output
    PORTB=0x00;     // initial state is LOW
}

void main(void) {
    Port_Init();
    unsigned char segments_code[10]={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6}; // 0-9 digit Hex code array
    unsigned long i=0; // counter
    while(1){
    PORTB=segments_code[i]; // output digits
    __delay_ms(500);
    i=(i+1)%10; // 0,1,2,3,...,9,0,1,2,....
    }    
    return;
}
