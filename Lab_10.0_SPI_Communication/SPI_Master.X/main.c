/* SPI_Master
 * File:   main.c
 * Author: fady
 *
 * Created on May 14, 2024, 2:06 PM
 */


//------------Preprocessor--------------
#include <stdint.h>
#include "Config.h"
#include <xc.h>
#define _XTAL_FREQ 4000000
// Macros [pin configuration]
#define UP RB0
#define DOWN RB1
#define SEND RB2
// Global_Var
uint8_t data=0;
//----------prototype-------------
void SPI_Master_init(void);
void Write_data(uint8_t);

//--------port_initialization----------
// initializes portB&D and configures I/O pins
// RB0, RB1 & RB2 Are Input Pins (Push Buttons)
// RD0-3 are output pins (LEDs)
void port_init(void){
TRISB|=0x07;	// RB0, RB1 & RB2 as Input
PORTB=0;		// initial state is low
TRISD&=~0x0F;	// RD0-4 as output
PORTD=0;		// initial state is low
}

//---------Main_Routine----------
void main(void) {
SPI_Master_init();
port_init();
while(1){
if(UP){
data++;
  __delay_ms(350);
}
if(DOWN){
data--;
  __delay_ms(350);
}
if(SEND){
Write_data(data); // SPI transmission initiation
  __delay_ms(350);
}
PORTD=data;	// display data to be transmitted
}
    return;
}


//----------SPI_Master_mode_initialization----------
void SPI_Master_init(void){
// SPI Master mode, clock rate = Fosc/4
SSPM3=0;
SSPM2=0;
SSPM1=0;
SSPM0=0;

// Enable SPI synchronous serial port 
SSPEN=1;

// Configure the serial clock polarity and phase
CKP=0;	// Idle state for clock is a low level
CKE=0;	// Transmit occurs on transition from Idle to active clock state

// Data sampling
SMP=0;	// Input data sampled at middle of data output time

// IO pins configuration
TRISC3=0;	// SCK/RC3 output
TRISC4=1;	// SDI/RC4 input
TRISC5=0;	// SDO/RC5 output

}

//----------Transmit_serial_data_SPI-------------
void Write_data(uint8_t data){
SSPBUF=data;	// write data to the buffer
}