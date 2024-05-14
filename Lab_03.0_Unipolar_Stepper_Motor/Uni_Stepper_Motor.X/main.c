/* Lab_3.0_Unipolar_Stepper_Motor
 * File:   main.c
 * Author: Fady Abd Elshahid
 *
 * Created on April 22, 2024, 5:31 PM
 */

#include <xc.h>
#include "Config.h"
#define _XTAL_FREQ 4000000

//-----------Port_Init--------------
// initializes portC and configures I/O pins
// PC0-3 as output
void Port_Init(void){
    TRISC&=~0x0F; //pins PC0-3 output
    PORTC&=0xF0;     // initial state is LOW
}
//-----------main-------------
void main(void) {
    Port_Init();
    while(1){
    unsigned char i=0; // shifting variable
    unsigned char j=0; // step variable
    // rotate motor CW  1,2,3,4,1,.....
        while(j<48){ // total steps is 48
            PORTC=(1<<i); //activates pins 0,1,2,3 to make the CC rotation
            i=(i+1)%4; // i= 0,1,2,3,0,1,.....
            j++;
            __delay_ms(50); //50ms delay
        }
    //wait 1 second
        __delay_ms(1000);
        PORTC&=~0xF0;     // initial state is LOW
    // rotate motor CCW 4,3,2,1,4,..... 
    i=0; // shifting variable
    j=0; // step variable
        while(j<48){
            PORTC=(8>>i); //activates pins 3,2,1,0,3,... to make the CCW rotation
            i=(i+1)%4; // i= 0,1,2,3,0,1,.....
            j++;
            __delay_ms(50); //50ms delay
        }
    //wait 1 second
        __delay_ms(1000);
        PORTC&=~0xF0;     // initial state is LOW
    }
}
