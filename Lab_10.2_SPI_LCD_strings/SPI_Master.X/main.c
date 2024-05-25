/* SPI_Master
 * File:   main.c
 * Author: fady
 *
 * Created on May 14, 2024, 7:49 PM
 */

//------------Preprocessor--------------
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "Config.h"
#include <xc.h>
#define _XTAL_FREQ 4000000
// Macros [pin configuration]
#define STRING RB0
#define SEND RB2

//----------prototype-------------
void SPI_Master_init(void);
void Write_data(uint8_t);
void SPI_Write_String(char *);
void Shift_String_Right_Add_Length(char *);
//----------Port_Init--------------
// initializes portA and configures I/O pins
// RB0 & RB2 Are Input Pins (Push Buttons)
void Port_Init(void){
   TRISB|=0x05;     // pin RB0&2 as input (buttons)
   PORTB&=~0x05;    // initial state low 
}


//---------Main_Routine----------
void main(void) {
SPI_Master_init();
Port_Init();

char buffer[20]; 

while(1){
if(STRING){
// define the string to transmit
    // first character is the length
    // the rest are the data
    strcpy(buffer,"1234578");
    // shift string right and add its length at the beginning
    Shift_String_Right_Add_Length(buffer);
  __delay_ms(350);
}

if(SEND){
SPI_Write_String(buffer); // SPI transmission initiation
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

//----------Write_data----------
void Write_data(uint8_t data){
SSPBUF=data;    // write data to the buffer
}
//----------SPI_Write_String----------
void SPI_Write_String(char *Text){
    uint8_t i;
    for(i=0;Text[i]!='\0';i++){
    Write_data(Text[i]);
     __delay_ms(100);
    }
}
//----------Shift_String_Left----------
void Shift_String_Right_Add_Length(char* str){
    int32_t i;
    char len = strlen(str); // Get the length of the string
    // Shift string to the right by one position
    for (int i = len; i >= 0; --i) {
        str[i + 1] = str[i];
    }
str[0]=len+0x30; // first element is the string length (converted to ASCII)
}