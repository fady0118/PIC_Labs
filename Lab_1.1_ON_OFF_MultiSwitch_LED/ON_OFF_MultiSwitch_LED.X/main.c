/*
 * File:   main.c
 * Author: Fady Abd Elshahid
 *
 * Created on April 21, 2024, 4:41 PM
 */

// preprocessor 
#include <xc.h>
#include "Config.h"

#define _XTAL_FREQ 4000000
typedef unsigned long ul;

//-----------Port_Init--------------
// initializes portB and configures I/O pins
// PB0-2 as input
// PB3 as output
void Port_Init(void){
// direction
 TRISB|=0x07; // Configure PB0-2 as input (switch)
 TRISB&=~0x08; // Configure PB3 as output (LED)
// data
 PORTB&=~0x0F; // PB0-3 initial state LOW
}
//global variables
ul SW1_previous_state=0x00; // SW1 state
ul SW2_previous_state=0x00; // SW2 state
ul SW3_previous_state=0x00; // SW3 state
void main(void) {
    Port_Init();//initialize portB
    while(1){
        if((PORTB&0x01)!=SW1_previous_state){//SW1 pressed
            PORTB^=0x08; // Toggle LED (PB3)
            SW1_previous_state=(PORTB&0x01);
        }
        if((PORTB&0x02)!=SW2_previous_state){//SW2 pressed
            PORTB^=0x08; // Toggle LED (PB3)
            SW2_previous_state=(PORTB&0x02);
        }
        if((PORTB&0x04)!=SW3_previous_state){//SW3 pressed
            PORTB^=0x08; // Toggle LED (PB3)
            SW3_previous_state=(PORTB&0x04);
        }
    }

}
