/* SPI_Master
 * File:   main.c
 * Author: fady
 *
 * Created on May 25, 2024, 5:50 PM
 */


//------------Preprocessor--------------
#include <xc.h>
#include <stdint.h>
#include <string.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
// Macros [pin configuration]
#define STRING_DEFINE1 RB0
#define STRING_DEFINE2 RB1
#define SEND1 RB2
#define SEND2 RB3
//----------prototype-------------
void Port_Init(void);
void SPI_Master_Init(void);
void Write_data(uint8_t);
void SPI_Write_String(char *);
void Shift_String_Right_Add_Length(char *);
//------------Main_Routine--------------
void main(void) {
    Port_Init();
    SPI_Master_Init();
    char buffer[20]; 
  
    while(1){
    if(STRING_DEFINE1){
    // define the string to transmit
    // first character is the length
    // the rest are the data
    strcpy(buffer,"BESTO");
    // shift string right and add its length at the beginning
    Shift_String_Right_Add_Length(buffer);
    __delay_ms(350);
    }
    if(STRING_DEFINE2){
    // define the string to transmit
    // first character is the length
    // the rest are the data
    strcpy(buffer,"FRIENDO");
    // shift string right and add its length at the beginning
    Shift_String_Right_Add_Length(buffer);
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
// RB0-3 Are Input Pins (Push Buttons)
// RD0-1 -> ss lines (Output)
void Port_Init(void){
   TRISB|=0x0F;     // pin RB0-3 as input (buttons)
   PORTB&=~0x0F;    // initial state low 
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