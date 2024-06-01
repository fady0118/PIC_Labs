/*
 * File:   main.c
 * Author: fady
 *
 * Created on June 1, 2024, 9:41 PM
 */

//------------Preprocessor--------------
#include "Config.h"
#include <xc.h>
#define _XTAL_FREQ 4000000      // Fosc
//----------prototype-------------
void I2C_Slave_Init(unsigned char);
//--------port_initialization----------
// initializes PortD and configures I/O pins
// PortD is Input pins (switches)
void port_init(void){
TRISD|=0xFF;	// RD0-7 as Input pins
PORTD=0;		// initial state is low
}
//---------Main_Routine----------
void main(void) {
    port_init();
    I2C_Slave_Init(0x40);
    while(1){
    
    }
    return;
}

//-----------ISR-----------
void __interrupt() ISR(void){
    if(SSPIF){
        CKP=0;          // hold the clock
        if(R_W && !D_A){
            char Dummy = SSPBUF;
            SSPBUF=PORTD;
            CKP=1;      // release the clock
            while(BF);  // wait for the buffer to be full
        }
        SSPIF=0;
    }
}

//-----------I2C_Functions_Implementation-------------
void I2C_Slave_Init(unsigned char Address){
    TRISC|=0x18;        // RC3/SCL & RC4/SDA as input
    SSPADD=Address;     // assign the address to the device
    SMP=1;              // Slew rate control disabled
    SSPCON|=0x36;       // I2C Slave mode, 7-bit address, Enables the serial port ,Release clock
    SEN=1;              // Clock stretching is enabled
    // Enable Interrupts
    SSPIE=1;
    PEIE=1;
    GIE=1;
    SSPIF=0;
}
