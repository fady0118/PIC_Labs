/* Lab_11.0_ADC_LED_Dimmer
 * File:   main.c
 * Author: fady
 *
 * Created on May 19, 2024, 5:30 PM
 * 
 */
/*
 [This project is a variant of the ADC_LED_Dimmer.X project the only
 * difference is that we use interrupts instead of polling the GO/DONE bit]
 */

// This code is dedicated to A/D conversion from an analog signal that utilizes
// a potentiometer to adjust the input electric signal 
// the signal is then converted into digital value using the ADC module 
// the value is fed to the PWM module which controls the LED light intensity

//---------Preprocessor---------
#include <xc.h>
#include <stdint.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
//Global
uint16_t result;
//----------prototype-------------
void PWM_duty_cycle(unsigned short int);
void ADC_Read(uint8_t);
//--------CCP_PWM_mode_config---------
void CCP_PWM(void){
PR2=255;        // PR2 controlling the PWM freq ~1khz at 4Mhz Fosc 
TRISC&=~0x04;   // CCP1/RC2 output
CCP1CON|=0x0C;  // PWM mode   
T2CON|=0x01;      // 4 prescale value    
T2CON|=0x04;      // Enable Timer2
PWM_duty_cycle(0);
}
//----------ADC_Init-------------
void ADC_Init(void){
    ADCON0 = 0x41;  // Turn ADC ON, Select AN0 Channel, ADC Clock = Fosc/8
    ADCON1 = 0x80;  // All 8 Channels Are Analog, Result is "Right-Justified"
                    // ADC Clock = Fosc/8
    //interrupts
    ADIF=0;
    ADIE=1;
    PEIE=1;
    GIE=1;
}
//------------Main_Routine--------------
void main(void) {
CCP_PWM();
ADC_Init();
while(1){
ADC_Read(0);
PWM_duty_cycle(result);
__delay_ms(1);
}
    return;
}

//---------PWM_duty_cycle------------
void PWM_duty_cycle(uint16_t DC){
    if(DC<1024){  // Check The DC Value To Make Sure it's Within 10-Bit Range
    CCP1Y  = DC & 1;  // duty cycle LSB
    CCP1X  = DC & 2;  // duty cycle 2nd LSB
    CCPR1L = DC >> 2; // duty cycle remaining bits
    }
}
//-----------AD_conversion-------------
// Input: Analog channel number
// Output: The Right-Justified 10-Bit ADC Result
void ADC_Read(uint8_t AN){
if(AN>=0 && AN<=7){      // Check Channel Number Validity
ADCON0&=~0x38;           // clear the channel select
ADCON0|=AN<<3;           // Select The Required Channel (AN)
__delay_us(30);          // Wait The Acquisition Time
ADCON0|=0x04;            // Set GO/DONE
}
else {result=0;}
}
//------------ISR---------------
void __interrupt() ISR(void){
    if(ADIF){
        ADIF=0;     //clear flag
        result=(ADRESH<<8)+ADRESL;
    }
}