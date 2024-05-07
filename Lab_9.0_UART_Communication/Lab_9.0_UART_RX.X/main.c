/* Lab_9.0_UART_RX
 * File:   main.c
 * Author: fady
 *
 * Created on May 7, 2024, 8:23 PM
 */

/*
 * [ Receiver Firmware ]
 * set up the UART module to operate in slave mode @ 9600bps and 
   enable the UART data reception interrupt. 
   Within the ISR handler, we should read the received byte of data and 
   latch it out to PORTB with some LEDs for data inspection.
*/

//------------Preprocessor--------------
#include <stdint.h>
#include "Config.h"
#include <xc.h>
#define _XTAL_FREQ 4000000

//----------prototype-------------
void UART_RX_Init(void);
uint8_t UART_Read(void);
//---------=Global_vars------------
uint8_t UART_Buffer = 0;
//----------Port_Init--------------
// initializes portA and configures I/O pins
// RB0-3 Are Output Pins (LEDs)
void Port_Init(void){
   TRISB = 0x00;    // Output Port (4-Pins) 
   PORTB = 0x00;    // initial state low 
}
//------------Main_Loop-------------
void main(void) {
    Port_Init();
    UART_RX_Init();
    
    while(1){
    // Stay Idle, Everything is handled in the ISR !
    }
    return;
}

void UART_RX_Init(void){
  BRGH = 1; // Set For High-Speed Baud Rate
  SPBRG = 25; // Set The Baud Rate To Be 9600 bps
  
  // Enable The Ascynchronous Serial Port
  SYNC = 0;
  SPEN = 1;
  
  // Set The RX-TX Pins to be in UART mode (not io)
  TRISC6 = 1; // As stated in the datasheet
  TRISC7 = 1; // As stated in the datasheet
  
  //--[ Enable UART Receiving Interrupts ]--
  RCIE = 1; // UART Receving Interrupt Enable Bit
  PEIE = 1; // Peripherals Interrupt Enable Bit
  GIE = 1; // Global Interrupt Enable Bit

  CREN = 1; // Enable Data Continous Reception
}

void __interrupt() ISR(void){
 if (RCIF == 1){
    UART_Buffer = RCREG; // Read The Received Data Buffer
    PORTB = UART_Buffer; // Display The Received Data On LEDs
    RCIF = 0; // Clear The Flag
  }
}