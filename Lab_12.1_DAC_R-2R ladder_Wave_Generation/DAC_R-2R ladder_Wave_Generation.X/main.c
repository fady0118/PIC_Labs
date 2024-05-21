/* DAC_R-2R ladder_Wave_Generation
 * File:   main.c
 * Author: fady
 *
 * Created on May 21, 2024, 12:14 PM
 */

// This code generates a 8-bit digital sinewave & outputs it to port B
// It will then converted to analog using the R-2R ladder method
// The result is gonna be monitored using an oscilloscope


//---------Preprocessor---------
#include <xc.h>
#include <stdint.h>
#include "Config.h"
#include <math.h>
#define _XTAL_FREQ 4000000
#define DAC_OUT PORTB
#define PI 3.141592
//------------Main_Routine--------------
void main(void) {
    TRISB = 0x00; // For 8-Bit DAC Out
    DAC_OUT = 0x00;
    uint8_t sine[50];
    for(int i=0;i<50;i++){
        sine[i]=round((((sin((360/50)*i*(PI/180))+1)/2)*255));
    }
    while(1){
    for(int i=0;i<50;i++){
        DAC_OUT=sine[i];
        __delay_ms(200);
    }
    }
    return;
}
