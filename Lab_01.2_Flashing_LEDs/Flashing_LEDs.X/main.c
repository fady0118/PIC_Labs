/* Flashing_LEDs
 * File:   main.c
 * Author: Fady Abd Elshahid
 *
 * Created on April 21, 2024, 5:53 PM
 */
// preprocessor 
#include <xc.h>
#include "Config.h"
#include <pic16f877a.h>
#define _XTAL_FREQ 4000000
typedef unsigned long ul;

//-----------Port_Init--------------
// initializes portB and configures I/O pins
// PB0-2 as input Buttons
// PB3-5 as output
void Port_Init(void){
// direction
 TRISB|=0x07; // Configure PB0-2 as input (Buttons)
 TRISB&=~0x38; // Configure PB3-5 as output (LED)
// data
 PORTB&=~0x3F; // PB0-5 initial state LOW
}
void main(void) {
    Port_Init(); //initialize portB
    if((PORTB&0x01)){ // PB0 pressed 
    // flash LEDs 1->2->3
      PORTB|=0x08;      // LED1 ON (PB3)
      __delay_ms(250);  // 250ms delay
      
      PORTB&=~0x08;     // LED1 OFF (PB3)
      PORTB|=0x10;      // LED2 ON  (PB4)
      __delay_ms(250); // 250ms delay
      
      PORTB&=~0x10;     // LED2 OFF (PB4)
      PORTB|=0x20;      // LED3 ON  (PB5)
      __delay_ms(250);  // 250ms delay
      
      PORTB&=~0x20;     // LED3 OFF (PB5)
    }
    
    if((PORTB&0x02)){ // PB1 pressed
    //flash All LEDs 3 times
        for(int i=0;i<3;i++){
    PORTB^=0x38;      // Toggle LED1,2,3 (PB3-5)
    __delay_ms(250);  // 250ms delay
    PORTB^=0x38;      // Toggle LED1,2,3 (PB3-5)
    __delay_ms(250);  // 250ms delay
        }
    }
    
    if((PORTB&0x04)){ // PB2 pressed
    // flash LEDs 3->2->1
    PORTB|=0x20;      // LED3 ON (PB5)
    __delay_ms(250);  // 250ms delay
    
    PORTB&=~0x20;     // LED3 OFF(PB5)
    PORTB|=0x10;      // LED2 ON (PB4)
    __delay_ms(250); // 250ms delay
    
    PORTB&=~0x10;     // LED2 OFF(PB4)
    PORTB|=0x08;      // LED1 ON (PB3)
    __delay_ms(250); // 250ms delay
    
    PORTB&=~0x08;     // LED1 OFF(PB3)  
    }
}
