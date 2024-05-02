/*
 * File:   main.c
 * Author: Fady Abd Elshahid
 *
 * Created on April 23, 2024, 8:13 PM
 */
//---------Preprocessor---------
#include <xc.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
//----------Port_Init--------------
// initializes portA and configures I/O pins
// PB0-3 as output
void Port_Init(void){
    TRISB&=~0x0F;    //pins PB0-3 output
    PORTB&=~0x0F;    // clear PB0-3
}

//-----------main-------------
void main(void) {
Port_Init();
while(1){
unsigned char i=0; // shifting variable
unsigned char j=0; // step variable    
    // rotate motor CW  1,2,3,4,1,.....
        while(j<48){ // total steps is 48
            PORTB=(1<<i); //activates pins 0,1,2,3 to make the CC rotation
            i=(i+1)%4; // i= 0,1,2,3,0,1,.....
            j++;
            __delay_ms(50); //50ms delay
        }  
    PORTB&=~0x0F;     // initial state is LOW
    //wait 1 second
        __delay_ms(1000);
      
        
// rotate motor CCW 4,3,2,1,4,..... 
    i=0; // shifting variable
    j=0; // step variable
        while(j<48){
            PORTB=(8>>i); //activates pins 3,2,1,0,3,... to make the CCW rotation
            i=(i+1)%4; // i= 0,1,2,3,0,1,.....
            j++;
            __delay_ms(50); //50ms delay
        }
    PORTB&=~0x0F;     // initial state is LOW
    //wait 1 second
        __delay_ms(1000);
       
    }
}