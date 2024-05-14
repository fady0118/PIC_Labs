/* Lab_4.0_1-second_Delay_with_Timer1
 * File:   main.c
 * Author: Fady Abd Elshahid
 *
 * Created on April 23, 2024, 3:28 PM
 */

//---------Preprocessor---------
#include <xc.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
//--------global_variables--------
unsigned char Counter=0;

//----------Port_Init--------------
// initializes portA and configures I/O pins
// PB0 as output
void Port_Init(void){
    TRISB&=~0x01;    //pins PB0 output
    PORTB&=~0x01;    // clear PB0
}
//---------Timer1_Init-----------
void Timer1_Init(void){
T1CON|=0x01;  // Enable Timer1
T1CON&=~0x02; // Internal clock (FOSC/4)
T1CON|=0x08;  // Oscillator is enabled
T1CON&=~0x30; // 1:1 prescale value
TMR1=15536;   // preloading value
}
//-------Enable_Interrupts--------
void Enable_Interrupts(void){
TMR1IE = 1;  // Timer1 Interrupt Enable Bit
TMR1IF = 0;  // Clear The Interrupt Flag Bit
PEIE = 1;    // Peripherals Interrupts Enable Bit
GIE = 1;     // Global Interrupts Enable Bit
}
//-----------main-------------
void main(void) {
Port_Init();
Timer1_Init();
Enable_Interrupts();
while(1){


}
}
// Interrupt Service Routine - ISR
void __interrupt() ISR (void){
    if(TMR1IF==1){         // flag is raised every 0.065536 sec
        Counter++;
        if(Counter == 20){ // 15*0.065536 is 0.983 sec almost 1 sec
            PORTB^=0x01;   // toggle PB0
            Counter=0;     // clear/acknowledge Counter
        }
        TMR1IF=0;          // clear/acknowledge flag
        TMR1=15536;        // preloading value
    }
}