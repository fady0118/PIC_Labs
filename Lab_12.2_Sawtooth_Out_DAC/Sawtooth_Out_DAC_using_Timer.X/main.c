/* Sawtooth_Out_DAC_using_Timer
 * File:   main.c
 * Author: fady
 *
 * Created on May 21, 2024, 2:31 PM
 */

// [This is a modification to the Sawtooth_Out_DAC Lab
//  but we'll be using Timer delays instead for better accuracy]


// This code is dedicated for Generating Sawtooth Waveform With DAC  @ 10Hz
// Fout=1/(Number of samples * Ts)
// for F = 10Hz & 256 samples
// Ts = 390 us
//---------Preprocessor---------
#include <xc.h>
#include <stdint.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
#define DAC_OUT PORTB

//-----------Timer1_Init-------------
void Timer1_Init(void){


}

void main(void) {
    TRISB = 0x00;       // For 8-Bit DAC Out
    DAC_OUT = 0x00;     // initial state low
    uint8_t data=0;     // data variable 
    while(1){

    }
    return;
}
