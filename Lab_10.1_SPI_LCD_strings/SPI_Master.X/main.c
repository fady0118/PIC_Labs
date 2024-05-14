/* SPI_Master
 * File:   main.c
 * Author: fady
 *
 * Created on May 14, 2024, 7:49 PM
 */

//------------Preprocessor--------------
#include <stdint.h>
#include <stdio.h>
#include "Config.h"
#include <xc.h>
#define _XTAL_FREQ 4000000
// Macros [pin configuration]
#define HELLO RB0
#define FRIEND RB1
#define SEND RB2
// Global
char string[20];
//----------prototype-------------
void SPI_Master_init(void);
void Write_data(uint8_t);
void SPI_Write_String(char *);
//----------Port_Init--------------
// initializes portA and configures I/O pins
// RB0, RB1 & RB2 Are Input Pins (Push Buttons)
void Port_Init(void){
   TRISB|=0x07;     // pin RB0-2 as input (buttons)
   PORTB&=~0x07;    // initial state low 
}


//---------Main_Routine----------
void main(void) {
SPI_Master_init();
Port_Init();
while(1){
if(HELLO){
sprintf(string,"HELLO");
  __delay_ms(350);
}
if(FRIEND){
sprintf(string,"FRIEND");
  __delay_ms(350);
}
if(SEND){
SPI_Write_String(string); // SPI transmission initiation
  __delay_ms(350);
}

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
//----------String_Transmission--------------
void SPI_Write_String(char *text)
{
  uint16_t i;
  for(i=0;text[i]!='\0';i++)
    Write_data(text[i]);
}