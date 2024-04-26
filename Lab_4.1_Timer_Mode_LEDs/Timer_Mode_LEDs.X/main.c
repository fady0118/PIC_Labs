/*
 * File:   main.c
 * Author: fady
 *
 * Created on April 25, 2024, 11:36 PM
 */

//---------Preprocessor---------
#include <xc.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
//----------Port_Init--------------
// initializes portA and configures I/O pins
// PB0-6 as output (7-segment)
// PC2 as input (button)
void Port_Init(void){
    TRISB&=~0xFF;     // pins PB0-6 as output (7-segment)
    PORTB&=~0xFF;     // clear PB0-6
}
void Timer1_init(void){
TMR1=0x00;
TMR1CS=1;  // External clock (Counter mode)
T1OSCEN=1; // Oscillator is enabled

T1CKPS0=0;    // 1:1 prescale value
T1CKPS1=0;
T1SYNC=0;  // Synchronized external clock
TMR1ON=1;  // Enables Timer1
}


void main(void) {
    Port_Init();
    Timer1_init();
    while(1){
        PORTB=TMR1;
    }
    return;
}
