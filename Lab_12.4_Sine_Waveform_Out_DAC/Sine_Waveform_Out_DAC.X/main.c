/* Sine_Waveform_Out_DAC
 * File:   main.c
 * Author: fady
 *
 * Created on May 21, 2024, 7:23 PM
 */

// This code is dedicated for Generating Sine Waveform With DAC  @ 10Hz
// Ns = 32 sample points
// Fout=1/(Number of samples * Ts)
// for F = 10Hz & 32 samples
// Ts = 3125 us

//---------Preprocessor---------
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
#define DAC_OUT PORTB
// Global
uint8_t i=0;
const uint8_t sineLookupTable[] = {
128, 152, 176, 198, 218, 234, 245, 253,
255, 253, 245, 234, 218, 198, 176, 152,
128, 103, 79, 57, 37, 21, 10, 2,
0, 2, 10, 21, 37, 57, 79, 103};
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
TMR1=62470;     // pre-loading value 390 us to overflow
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
// while the equations showed that pre-loading the timer with 62411 should give
// 10Hz frequency, in practice it took around 0.102 sec/cycle
// this is possibly caused by the time wasted on context switch from
// main thread to the ISR background thread
// so we'll make up for it by adjusting the pre-loading value
// the oscilloscope showed a 1.5~2.25 ms error 
// Changing the value form 62411 to 62470 showed the desired results
void __interrupt() ISR(void){
    if(TMR1IF){
        TMR1IF=0;   // clear flag
        DAC_OUT=sineLookupTable[i++];
        if(i==32){i=0;}
        TMR1=62470; 

    }
}
