/*
 * File:   main_TX.c
 * Author: fady
 *
 * Created on May 8, 2024, 1:58 PM
 */

//------------Preprocessor--------------
#include <stdint.h>
#include <string.h>
#include "Config.h"
#include <xc.h>
#include "LCD.h"
#define Baud 9600
//Macros
#define DEFINE1 RB0
#define DEFINE2 RB1
#define SEND RB2
//----------prototype-------------
void UART_TX_Init(void);
void UART_Write(uint8_t);
void UART_Write_String(char *);
//----------Port_Init--------------
// initializes portA and configures I/O pins
// RB0, RB1 & RB2 Are Input Pins (Push Buttons)
void Port_Init(void){
   TRISB|=0x07;     // pin RB0-2 as input (buttons)
   PORTB&=~0x07;    // initial state low 
}

void main(void) {
    Port_Init();    // initial buttons Pins
    UART_TX_Init(); // Initialize The UART in Master Mode at 9600bps
    char string[25];
    while(1){
    
    if (DEFINE1) // Increment The Data Value
    {
    strcpy(string,"HELLO");
    __delay_ms(250);
    }
    if (DEFINE2) // Increment The Data Value
    {
    strcpy(string,"FRIEND");
    __delay_ms(250);
    }
    if (SEND) // Send The Current Data Value Via UART
    {
      UART_Write_String(string);
      __delay_ms(250);
    }
   
    }
    return;
}

void UART_TX_Init(void){
    // baud rate
    BRGH = 1;   // Set For High-Speed Baud Rate
    SPBRG = 25; // Set The Baud Rate To Be 9600 bps
    
    // ASync serial
    SYNC = 0;   // Asynchronous mode
    SPEN = 1;   // Serial port enabled
    
    // Set The RX-TX Pins to be in UART mode
    TRISC6 = 1;  // As stated in the datasheet
    TRISC7 = 1;  // As stated in the datasheet
    TXEN = 1; // Enable UART Transmission
}

void UART_Write(uint8_t data)
{
  while(!TRMT);  // wait for TSR to be empty
  TXREG = data;  // Load the data
}
void UART_Write_String(char *text){
  uint16_t i;
  for(i=0;text[i]!='\0';i++){
    UART_Write(text[i]);
  }
  UART_Write('\0');
}