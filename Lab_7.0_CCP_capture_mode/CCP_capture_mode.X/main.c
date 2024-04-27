/* CCP_capture_mode
 * File:   main.c
 * Author: fady
 *
 * Created on April 26, 2024, 4:00 PM
 */

//---------Preprocessor---------
#include <xc.h>
#include "Config.h"
#define _XTAL_FREQ 4000000

//----------Port_Init--------------
// initializes portA and configures I/O pins
// PB0-3 as output (LEDs)
// PD0-3 as output (LEDs)
// 0-3 are for TMR1
// 0-3 are for CPPR1

void Port_Init(void){
    TRISB&=~0x0F;     // pins PB0-3 as output (LEDs)
    PORTB&=~0x0F;     // clear PB0-3
    TRISD&=~0x0F;     // pins PD0-3 as output (LEDs)
    PORTD&=~0x0F;     // clear PD0-3
}

//---------Timer1_init----------
void Timer1_init(void){
TMR1=0x00;
TMR1CS=1;  // External clock (Counter mode)
T1OSCEN=1; // Oscillator is enabled 
//the timer increments on every rising edge of clock input on pin RC1/T1OSI/CCP2
// RC1 input Counter button
TRISC|=0x02;   // RC1 Counter
T1CKPS0=0; // 1:1 prescale value
T1CKPS1=0;
T1SYNC=0;  // Synchronized external clock
TMR1ON=1;  // Enables Timer1
}
//--------CCP_capture_mode_config---------
void CCP_capture(void){
CCP1CON|=0x05; // Capture_mode (rising edge)
TRISC|=0x04;   // RC2 Capture
PEIE=1;        // Peripheral Interrupt Enabled
GIE=1;         // Global Interrupt Enabled
CCP1IE=1;      // CCP1 Interrupt Enabled
}

void main(void) {
    Port_Init();
    Timer1_init();
    CCP_capture();
    while(1){
        PORTB=TMR1;
    }
    return;
}
void __interrupt() ISR(void){
    if(CCP1IF){
    PORTD=CCPR1;
    CCP1IF=0;
    }

}