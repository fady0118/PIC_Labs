/* SPI_Master
 * File:   main.c
 * Author: fady
 *
 * Created on May 25, 2024, 5:50 PM
 */


//------------Preprocessor--------------
#include <xc.h>
#include <stdint.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
//----------prototype-------------
void Port_Init(void);
void SPI_Master_Init(void);
void Write_data(uint8_t);
void SPI_Write_String(char *);
// Macros [pin configuration]
#define STRING_DEFINE RB0
#define SEND1 RB1
#define SEND2 RB2
//------------Main_Routine--------------
void main(void) {
    Port_Init();
    SPI_Master_Init();
    char *buffer; // Pointer Variable
    // Dynamically allocate memory using malloc()
    buffer = (char*)malloc(10 * sizeof(char));
    
    while(1){
    if(STRING_DEFINE){
    buffer="123456789";
    __delay_ms(350);
    }

    if(SEND1){
    PORTD=0x02;     // select slave1 (SS1 LOW)
    SPI_Write_String(buffer); // SPI transmission initiation
      __delay_ms(350);
    }
    if(SEND2){
    PORTD=0x01;     // select slave2 (SS2 LOW) 
    SPI_Write_String(buffer); // SPI transmission initiation
      __delay_ms(350);
    }
    }
    return;
}
//-----------Functions_Implementations------------
//----------Port_Init--------------
// initializes portA and configures I/O pins
// RB0, RB1 & RB2 Are Input Pins (Push Buttons)
// RD0-1 -> ss lines (Output)
void Port_Init(void){
   TRISB|=0x07;     // pin RB0-2 as input (buttons)
   PORTB&=~0x07;    // initial state low 
   TRISD&=~0x03;    // pin RB0-2 as output (ss lines)
   PORTD|=0x03;     // idle state high
}
//----------SPI_Master_Init----------
void SPI_Master_Init(void){
// SPI Master mode, clock = FOSC/4
SSPM3=0;
SSPM2=0;
SSPM1=0;
SSPM0=0;     

SSPEN=1;            // Enables serial port and configures SCK, SDO, SDI, and SS as serial port pins
CKP=0;              // Idle state for clock is a low level
CKE=0;              // Transmit occurs on Leading edge
SMP=0;              // Input data sampled at middle of data output time
// I/O configuration
TRISC5=0;           // RC5/SDO output
TRISC4=1;           // RC4/SDI input
TRISC3=0;           // RC3/SCK output
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