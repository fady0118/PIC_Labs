/* SPI_Slave
 * File:   main.c
 * Author: fady
 *
 * Created on May 15, 2024, 3:20 PM
 */

//------------Preprocessor--------------
#include <stdint.h>
#include "Config.h"
#include <xc.h>
#define _XTAL_FREQ 4000000
//---------=Global_vars------------
uint8_t Data_Buffer = 0;
//----------prototype-------------
void SPI_Slave_init(void);
//--------port_initialization----------
// initializes portB and configures I/O pins
// RB0-3 are output pins (LEDs)
void port_init(void){
TRISB&=~0x0F;	// RD0-4 as output
PORTB=0;		// initial state is low
}

//---------Main_Routine----------
void main(void) {
    SPI_Slave_init();
    port_init();
    while(1){
    PORTB=Data_Buffer; // Dumping Received Data To PORTB 
    }
    return;
}
//----------SPI_Slave_mode_initialization----------
void SPI_Slave_init(void){
// SPI Slave mode, clock = SCK pin, SS line enabled 
SSPM0=0;
SSPM1=0;
SSPM2=1;
SSPM3=0;

// Enable SPI synchronous serial port 
SSPEN=1;

// Configure the serial clock polarity and phase [same as Master]
CKP=0;	// Idle state for clock is a low level
CKE=0;	// Transmit occurs on transition from Idle to active clock state

// Clear SMP bit
SMP=0;  // SMP must be cleared in slave mode

// IO pins configuration
// set SS line (RA5/AN4) as Digital I/O [ADCON1 REGISTER]
PCFG0=0;
PCFG1=0;
PCFG2=1;
PCFG3=0;
TRISA5=1;   // SS/RA5  input

TRISC3=1;	// SCK/RC3 input
TRISC4=1;	// SDI/RC4 input
TRISC5=0;	// SDO/RC5 output

// Enable SPI reception interrupts 
SSPIE=1;	// enable SPI interrupts
PEIE=1;		// enable peripheral interrupts
GIE=1;		// enable general interrupts

}
//---------ISR----------
// Reads recieved data from Master using SPI protocol
void __interrupt() ISR(void){
    if(SSPIF){
    Data_Buffer=SSPBUF;     // Read Buffer
    SSPIF=0;    // clear interrupt flag
    }
}