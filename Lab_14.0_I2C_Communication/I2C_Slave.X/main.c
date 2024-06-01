/* I2C_Slave
 * File:   main.c
 * Author: fady
 *
 * Created on June 1, 2024, 3:42 PM
 */

//------------Preprocessor--------------
#include "Config.h"
#include <xc.h>
#define _XTAL_FREQ 4000000 // Fosc
#define I2C_BaudRate 100000 // I2C Baud Rate = 100 Kbps
unsigned char RX_Data = 0x00;
//----------prototype-------------
void I2C_Slave_init(unsigned char);
//--------port_initialization----------
// initializes PortD and configures I/O pins
// PortD is Output pins (LEDs)
void port_init(void){
TRISD&=~0xFF;	// RD0-7 as Output pins
PORTD=0;		// initial state is low
}

//---------Main_Routine----------
void main(void) {
    port_init();
    I2C_Slave_init(0x40); // Initiate I2C Slave With Address = 0x40
    while(1){
    
    }
    return;
}
//--------I2C_Functions_Implementation----------
void I2C_Slave_init(unsigned char Address){
TRISC|=0x18;    // RC3 & RC4 Input pins
SSPCON|=0x36;   // Select I2C Slave mode, 7-bit address
                // Enables the serial port, Release clock
SSPADD=Address; // Assign address to the slave device
SMP=1;          // Slew rate control disabled for standard speed mode
SEN=1;          // Clock stretching is enabled
// Enable Interrupts
SSPIE=1;
PEIE=1;
GIE=1;
SSPIF=0;
}
//-----------ISR-----------
void __interrupt() ISR(void){
    if(SSPIF){
        if(!R_nW){
        char Dummy = SSPBUF; // Dummy Read
        CKP = 1; // Release The SCL Clock Line
        while(!BF); // Wait Until Completion
        RX_Data=SSPBUF;   // Read The Buffer Data
        PORTD = RX_Data;  // Output The Received Byte
        }
    CKP = 1;   // Release The SCL Clock Line
    SSPIF=0;
    }
}
