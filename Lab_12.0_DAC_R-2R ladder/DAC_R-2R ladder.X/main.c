/* Analog_Out_DAC
 * File:   main.c
 * Author: fady
 *
 * Created on May 20, 2024, 11:02 PM
 */

//---------Preprocessor---------
#include <xc.h>
#include <stdint.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
#define DAC_OUT PORTB
//----------prototype-------------
void ADC_Read(uint8_t);
void ADC_Init(void);
//Global_variable
uint16_t result=0;
//------------Main_Routine--------------
void main(void) {
    ADC_Init();
    TRISB = 0x00; // For 8-Bit DAC Out
    DAC_OUT = 0x00;
    uint16_t AN_RES;
    while(1){
    // Read The ADC
    ADC_Read(3);    // initiate conversion and update result variable
    AN_RES = result>>2; // DAC_OUT = (10bit ADC Result) / 4 = [ 0->255 ]
    DAC_OUT = AN_RES; // Transfer Data To DAC
    __delay_ms(1); // Reduce CPU Loading For Better Simulation
    }
    return;
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
//-----------AD_conversion-------------
// Input: Analog channel number
void ADC_Read(uint8_t AN){
    if(AN>=0 && AN<=7){ // Check Channel Number Validity
    ADCON0&=~0x38;      // clear channel selection
    ADCON0|=AN<<3;      // channel selection
    __delay_us(30);     // Wait The Acquisition Time
    ADCON0|=0x04;       // Set GO/DONE    
    }
    else {result=0;}
}
//------------ISR----------------
void __interrupt() ISR(void){
    if(ADIF){
    ADIF=0;             // clear interrupt flag
    result=(ADRESH<<8)+ADRESL;
    }
}
