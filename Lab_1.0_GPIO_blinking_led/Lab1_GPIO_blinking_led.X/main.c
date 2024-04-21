/*
 * File:   main.c
 * Author: fady
 *
 * Created on April 21, 2024, 12:40 PM
 */
// preprocessor 
#include <xc.h>
#include "Config.h"
#include <pic16f877a.h>
#define _XTAL_FREQ 4000000
//-----------Port_Init--------------
// initializes portB and configures I/O pins
// PB0 as input
// PB1 as output
void Port_Init(void){
// direction
 TRISB|=0x01; // Configure PB0 as input (switch)
 TRISB&=~0x02; // Configure PB1 as output (LED)
// data
 PORTB&=~0x02; // LED (PB1) initial state LOW
}
//------------Main_loop--------------
int main(void) {
   Port_Init(); // port initialization
   
   while(1){
       if(PORTB&0x01){//if switch in pressed
        PORTB^=0x02; //toggle LED
        __delay_ms(250); //delay 250ms
       }
       else{
           PORTB&=~0x02;
       }
   
   }
   
    return 0;
}
