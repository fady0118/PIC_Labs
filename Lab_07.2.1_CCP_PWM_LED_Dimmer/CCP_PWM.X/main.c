/* CCP_PWM
 * PWM - LED Dimmer
 * File:   main.c
 * Author: Fady Abd Elshahid
 *
 * Created on April 27, 2024, 5:35 PM
 */


//---------Preprocessor---------
#include <xc.h>
#include <stdint.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
//----------prototype-------------
void PWM_duty_cycle(unsigned short int);
//---------Timer2_init----------
void Timer2_Init(void){
T2CON&=~0x03;  // 1 prescale value    
T2CON|=0x04;      // Enable Timer2
}

//--------CCP_PWM_mode_config---------
void CCP_PWM(void){
CCP1CON|=0x0C;  // PWM mode   
TRISC&=~0x04;   // CCP1/RC2 output
PR2=199;        // PR2 controlling the PWM freq 5khz
PWM_duty_cycle(0);
}

void main(void) {
CCP_PWM();
Timer2_Init();
unsigned short int DC; // duty cycle variable 100% is 800
while(1){
    DC=0;
    while(DC<800){
    PWM_duty_cycle(DC);
    DC++;
    __delay_ms(2);      // 2ms delay
    }
    
    __delay_ms(100);    // 100ms delay
    
    while(DC>0){
    PWM_duty_cycle(DC);
    DC--;
    __delay_ms(2);      // 2ms d
    }
    
    __delay_ms(100);    // 100ms delay
}
    return;
}
//---------PWM_duty_cycle------------
void PWM_duty_cycle(unsigned short int DC){
CCP1Y  = DC & 1;  // duty cycle LSB
CCP1X  = DC & 2;  // duty cycle 2nd LSB
CCPR1L = DC >> 2; // duty cycle remaining bits
}
