/* Triangular_Waveform_Out_DAC_using_Timer
 * File:   main.c
 * Author: fady
 *
 * Created on May 21, 2024, 4:39 PM
 */

// This code is dedicated for Generating Triangular Waveform With DAC  @ 10Hz
// Ns = 256 (ramp-up) + 255 (ramp-down) = 511 sample points
// Fout=1/(Number of samples * Ts)
// for F = 10Hz & 511 samples
// Ts = 196 us
//---------Preprocessor---------
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
#define DAC_OUT PORTB
// Global
bool State=0;       // governs incrementing or decrementing the data var
uint8_t data=0;     // data variable 
uint8_t counter=0;
//-----------Timer1_Init-------------
void Timer1_Init(void){
TMR1ON=0;
TMR1CS=0;       // Internal clock (FOSC/4)
T1OSCEN=1;      // Oscillator is enabled
T1CON&=~0x30;   // 1:1 prescale value
TMR1ON=1;       // Start Timer1
TMR1IE=1;       // Enable Interrupts
TMR1IF = 0;     // Clear The Interrupt Flag Bit
PEIE = 1;       // Peripherals Interrupts Enable Bit
GIE = 1;        // Global Interrupts Enable Bit
TMR1=65388;     // pre-loading value 390 us to overflow
}

void main(void) {
    TRISB = 0x00;       // For 8-Bit DAC Out
    DAC_OUT = 0x00;     // initial state low
    Timer1_Init();
    while(1){
        // Everything is handled in the ISR
    }
    return;
}

//------------ISR-------------
// Calibration
// while the equations showed that pre-loading the timer with 65340 should give
// 10Hz frequency, in practice it took around 0.125 sec/cycle
// this is possibly caused by the time wasted on context switch from
// main thread to the ISR background thread
// so we'll make up for it by adjusting the pre-loading value
// the oscilloscope showed a 23.5~25 ms error 
// Changing the value form 65340 to 65388 showed the desired results
void __interrupt() ISR(void){
    if(TMR1IF){
        TMR1IF=0;   // clear flag

        if(State==0){
            DAC_OUT=data++; // New sample
        }
        else {
            DAC_OUT=data--; // New sample   
        }
        if(data==255 || data==0){State^=1;}
        TMR1=65388; 

    }
}
