/* Lab_9.0_UART_TX
 * UART Transmitter (Master)
 * File:   main.c
 * Author: fady
 *
 * Created on May 7, 2024, 8:19 PM
 */
/*
[ Transmitter Firmware ]
    3 inputs from the user using 3 push buttons:
     * 1. increment the data value
     * 2. decrement the data value
     * 3. send the current data frame via UART @ 9600bps
 */

//------------Preprocessor--------------
#include <stdint.h>
#include "Config.h"
#include <xc.h>
#define _XTAL_FREQ 4000000

//----------prototype-------------
void UART_TX_Init(void);
void UART_Write(uint8_t);

//----------Port_Init--------------
// initializes portA and configures I/O pins
// RB0, RB1 & RB2 Are Input Pins (Push Buttons)
// RD0-3 are output pins (LEDs)
void Port_Init(void){
   TRISB|=0x07;     // pin RB0-2 as input (buttons)
   PORTB&=~0x07;    // initial state low 
   TRISD&=~0x0F;    // Output Port (4-Pins)
   PORTD = 0x00;    // initial state low 
}
//------------Main_Loop-------------
void main(void) {
    Port_Init();    // initial buttons Pins
    UART_TX_Init(); // Initialize The UART in Master Mode at 9600bps
    uint8_t Data = 0; // The Data
    while(1){
        if(RB0){   // Increment button pushed
        Data++;
        __delay_ms(250);
        }
        if(RB1){   // Decrement button pushed
        Data--;
        __delay_ms(250);    
        }
        if(RB2){   // Send the current data frame
        UART_Write(Data);
        __delay_ms(250);    
        }
        PORTD = Data; // Display The Current Data Value at PORTD
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