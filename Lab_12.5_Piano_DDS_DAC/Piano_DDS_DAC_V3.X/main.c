/* Piano_DDS_DAC_V3
 * File:   main.c
 * Author: fady
 *
 * Created on May 22, 2024, 11:48 AM
 */

// This is a simple adjustment to the og code in this version the signal
// is only generated as long as you hold the buttons

// This project is a simple 4 note piano-like device that simply generates 
// a sine-wave with a specific frequency that corresponds to a real note
// The frequency control is done using the [DDS algorithm]
// Piano notes included
    // C4 = 261.6 Hz 
    // D5= 587.33 Hz 
    // E3= 164.81 Hz 
    // F6= 1396.91Hz 
// This project relies on a DAC to convert this digital signal to analog
// As well as an R-C Low Pass filter to smooth the signal which gave good 
// results for low-medium frequencies but I might update with 
// a different method later

//------------Preprocessor--------------
#include <xc.h>
#include <stdint.h>
#include "Config.h"
//#define _XTAL_FREQ 20000000
// Notes Macros 
#define C4 1
#define D5 2
#define E3 4
#define F6 8

uint8_t sineLUT[64] = {0x80,0x8c,0x98,0xa5,0xb0,0xbc,0xc6,0xd0,0xda,0xe2,0xea,
0xf0,0xf5,0xfa,0xfd,0xfe,0xff,0xfe,0xfd,0xfa,0xf5,0xf0,0xea,0xe2,0xda,0xd0,
0xc6,0xbc,0xb0,0xa5,0x98,0x8c,0x80,0x73,0x67,0x5a,0x4f,0x43,0x39,0x2f,0x25,
0x1d,0x15,0xf,0xa,0x5,0x2,0x1,0x0,0x1,0x2,0x5,0xa,0xf,0x15,0x1d,0x25,0x2f,
0x39,0x43,0x4f,0x5a,0x67,0x73};

//--------port_initialization----------
// initializes portB&D and configures I/O pins
// PORTA Input Pins (Push Buttons)
// PORTB output (DAC)
void port_init(void){
TRISB=0x00;     // PORTB output
PORTB=0;		// initial state is low
ADCON1|=0x06;   // RA0-RA7 digital
TRISA=0xFF;     // PORTA as Input
PORTA=0;		// initial state is low
TRISC0=0;       // RC0 output
}

// notes
// oscilloscope's results showed that Fs=46666.667 Hz
// Fout=Fs*Inc/2^16
// equation at Inc=367 gives Fout=261.6 Hz
// at Inc=367.37 using 367 oscilloscope showed Fout~=261.64 Hz (accurate)
// We're also using R-C low pass filter to smooth the signal 
// Piano notes
    // C4 = 261.6 Hz -> Inc=367 -> oscilloscope's results ~= 261.64 Hz
    // D5= 587.33 Hz -> Inc=825 -> oscilloscope's results ~= 588.23 Hz
    // E3= 164.81 Hz -> Inc=231 -> oscilloscope's results ~= 164.69 Hz
    // F6= 1396.91Hz -> Inc=1962 -> oscilloscope's results ~= 1398.6 Hz
void main(void) {
    port_init();
    uint16_t PhaseAcc=0;
    uint16_t PhaseInc=0;  // Fout = Fs * PhaseInc / 2^16
    while(1)
    {   
        switch(PORTA){
            case C4:
                PhaseInc=367;
                break;
            
            case D5:
                PhaseInc=825;
                break;
            
            case E3:
                PhaseInc=231;
                break;
            
            case F6:
                PhaseInc=1962;
                break;
//            default:
//                PhaseInc=0;
//                break;
        }
        
        // The LUT Length is 6-Bits, So We Must Parse Out The 6 MSBs
        PhaseAcc += PhaseInc;
        PORTB = sineLUT[PhaseAcc>>10];
        RC0 = ~RC0;
    }
    return;
}
