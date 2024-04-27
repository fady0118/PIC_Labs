/* CCP_compare_mode
 * This code toggles PB0 every 0.5sec by using  
 * CCP in compare mode
 * File:   main.c
 * Author: fady
 *
 * Created on April 26, 2024, 6:48 PM
 */

//---------Preprocessor---------
#include <xc.h>
#include "Config.h"
#define _XTAL_FREQ 4000000

//--------Global_Variable-----
unsigned char x=0;

//----------Port_Init--------------
// initializes portA and configures I/O pins
// PB0 as output (LEDs)
void Port_Init(void){
    TRISB&=~0x01;     // pins PB0 as output (LED)
    PORTB&=~0x01;     // clear PB0

}

//---------Timer1_init----------
void Timer1_Init(void){
T1CON&=~0x02; // Internal clock (FOSC/4)
T1CON|=0x08;  // Oscillator is enabled
T1CON&=~0x30; // 1:1 prescale value
T1CON|=0x01;  // Enable Timer1
}

//--------CCP_compare_mode_config---------
void CCP_compare(void){
CCP1CON|=0x0B;   // Compare mode, trigger special event
CCP1IE=1;        // CCP1 Interrupt Enabled
PEIE=1;          // Peripheral Interrupt Enabled
GIE=1;           // Global Interrupt Enabled
CCPR1=50000;     // Pre-loading value, will be compared with TMR1
}

void main(void) {
    Port_Init();
    Timer1_Init();
    CCP_compare();
    while(1){
    // everything is handled in the ISR
    }
    return;
}
//------------ISR---------------
void __interrupt() ISR(void){
    if(CCP1IF==1){
        x++;
        if(x==10){
        PORTB^=0x01;     // toggle PB0
        x=0;             // reset counter
        }
        CCP1IF=0;        // acknowledge flag
    }
}