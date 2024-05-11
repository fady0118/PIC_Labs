/* CCP_PWM
 * CCP_PWM_DC_Motor
 * 
 *  This code is dedicated to controlling the direction & speed of a DC motor
 * 
 *  The PIC16F877A has only RB0 as IRQ INT (edge-triggered)
 *  and RB4-7 as IOC (interrupt-on-change)
 *  I originally wanted to generate 6 interrupts 1 for direction 
 *  and 5 for speeds (0 25 50 75 100)
 *  Unfortunately as stated the PIC16F877A can generate a total of 5 interrupts
 *  we could reduce the speed control levels to 4
 *  or use polling
 *  since it's better to use interrupts we'll resort to reducing the 
 *  speed levels controls to 4 (0 33 67 100)
 * 
 * File:   main.c
 * Author: Fady Abd Elshahid
 *
 * Created on April 27, 2024, 8:49 PM
 */


//---------Preprocessor---------
#include <xc.h>
#include <stdint.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
#define REV     RB0
#define LVL0    RB1
#define LVL1    RB2
#define LVL2    RB3
#define LVL3    RB4
#define LVL4    RB5
//----------prototype-------------
void PWM_duty_cycle(unsigned short int);
//----------Port_Init--------------
// initializes portA and configures I/O pins
// RD0-1 as output for motor direction
// RC2 CCP/PWM output pin
// RB0 IRQ input (switch) for motor direction control
// RB4-7 as IOC (interrupt-on-change) input (switches) for motor speed control
void Port_Init(void){
   TRISB|=0x01;     // pin RB0 as input (IRQ)
   TRISB|=0xF0;     // RB4-7 as input (IOC)

   TRISD&=~0x03;    // RD0-1 as output for direction
   PORTD=0x01;      // Set RD0 & Clear RD1
   
}

//---------Timer2_init----------
// Work horse of the PWM module
void Timer2_Init(void){
T2CON&=~0x03;  // 1 prescale value    
}
//--------CCP_PWM_mode_config---------
void CCP_PWM(void){
PR2=199;         // PR2 controlling the PWM freq 5khz
TRISC&=~0x04;    // RC2/CCP1 PWM output pin
CCP1CON|=0x0C;   // PWM mode   
T2CON|=0x04;     // Enable Timer2
PWM_duty_cycle(0);

}
//---------Enable_Interrupts---------
// Enable Interrupts 
// Configure RB0 as IRQ
// Configure RB4-7 as IOC
void Enable_Interrupts(void){
INTE=1;         // Enables the RB0/INT external interrupt  
INTEDG=1;       // Interrupt on (rising edge) of RB0/INT pin
GIE=1;          // Enables all unmasked interrupts
RBIE=1;         // Enables the RB port change interrupt
}

void main(void) {
Port_Init();
Timer2_Init();
CCP_PWM();
Enable_Interrupts();
while(1){
    // everything is handled in the ISR
}
    return;
}

void __interrupt() ISR(void){

    if(INTF){
    // Reverse direction
    PORTD^=0x03;  // toggle RD0-1 to reverse the motor direction
    INTF=0;       // Acknowledge flag
    }
    if(RBIF && RB4){ // 0%
            PWM_duty_cycle(0);   // set duty cycle
            PORTC&=~0x04;            // clear RC2/CCP1
            RBIF=0;                  // Acknowledge flag
    }
    if(RBIF && RB5){ // 33%
            PWM_duty_cycle(267);   // set duty cycle
            RBIF=0;                  // Acknowledge flag
    }
    if(RBIF && RB6){ // 67%
            PWM_duty_cycle(534);   // set duty cycle
            RBIF=0;                  // Acknowledge flag
    }

    if(RBIF && RB7){  // 100%
            PWM_duty_cycle(800);    // set duty cycle  
            RBIF=0;                   // Acknowledge flag
    }
   
}

//---------PWM_duty_cycle------------
void PWM_duty_cycle(unsigned short int duty_cycle){
CCP1Y  = duty_cycle & 1;  // duty cycle LSB
CCP1X  = duty_cycle & 2;  // duty cycle 2nd LSB
CCPR1L = duty_cycle >> 2; // duty cycle remaining bits
}