/* Bluetooth Module HC-05 Interfacing
 * File:   main.c
 * Author: fady
 *
 * Created on May 9, 2024, 6:58 PM
 */

//------------Preprocessor--------------
#include <xc.h>
#include <stdint.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
#define Baud 9600
//--[ Control Data ]--
#define Blue_LED_ON    49
#define Blue_LED_OFF   50
#define Yellow_Toggle  51
//--------------------------------
// Functions Declarations
void UART_RX_Init(void);
// Globals
uint8_t UART_Buffer = 0;

//----------Port_Init--------------
// initializes portB and configures I/O pins
// RB0-1 as output LED
void Port_Init(void){
  TRISB &= ~0x03; // Inputs(LED)
  PORTB = 0;      // Initially OFF
}
//-----------Main_loop-----------
void main(void) {
    Port_Init();    // initializes portB and configures I/O pins
    UART_RX_Init(); // Initialize The UART in Master Mode @ 9600bps
    
    while(1){
 
    }
    return;
}
//--------------------------------
// Functions Definitions
 
void UART_RX_Init(){
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
  //------------------
  CREN = 1; // Enable Data Continous Reception
}
 
void __interrupt() ISR (void){
  if (RCIF == 1)
  {
    UART_Buffer = RCREG; // Read The Received Data Buffer
 
    // This could have been done within the main loop. Since it's not
    // Excessive processing, so it's OK to do it here below
    if(UART_Buffer == Blue_LED_ON)
      RB0 = 1; // Blue LED ON
    if(UART_Buffer == Blue_LED_OFF)
      RB0 = 0; // Blue LED OFF
    if(UART_Buffer == Yellow_Toggle)
      RB1 = ~RB1; // Toggle Yellow LED
 
    RCIF = 0; // Clear The Interrupt Flag
  }
}