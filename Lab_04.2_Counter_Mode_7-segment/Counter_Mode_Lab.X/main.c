/* Lab_4.1_Counter_Mode
 * File:   main.c
 * Author: Fady Abd Elshahid
 *
 * Created on April 25, 2024, 7:40 PM
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
    /*
     * TRISC|=0x02;      // PC1 as input (button)
    PORTC&=~0x02;     // clear PC2
     */
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
    unsigned char segments_code[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; // 0-9 digit Hex code array
    while(1){
        
        PORTB=segments_code[TMR1];
        if(TMR1==10){TMR1=0;}
    }
    return;
}
