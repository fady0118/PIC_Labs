/* Lab_6.0_IRQ_Lab
 * File:   main.c
 * Author: fady
 *
 * Created on April 26, 2024, 1:48 PM
 */

//---------Preprocessor---------
#include <xc.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
//----------Port_Init--------------
// initializes portB and configures I/O pins
// PB3 as output (LED)
void Port_Init(void){
    TRISB&=~0x04;     // pin PB3 as output (7-segment)
    PORTB&=~0x04;     // clear PB0-6
}
//------------IRQ_Init-------------
void IRQ_Init(void){
    TRISB|=0x01;    // pin PB0 as input (IRQ)
    INTE=1;         // Enables the RB0/INT external interrupt
    GIE=1;          // Enables all unmasked interrupts
    INTEDG=1;       // Interrupt on rising edge of RB0/INT pin
}
void main(void) {
    Port_Init();    // Port Configuration/Initialization
    IRQ_Init();     // IRQ RB0 configuration
    while(1){
    }
    return;
}
//------------ISR------------
void __interrupt() ISR(void){
    if(INTF==1){
    PORTB^=0x04; // toggle LED
    INTF=0;      // acknowledge flag
    }
}
