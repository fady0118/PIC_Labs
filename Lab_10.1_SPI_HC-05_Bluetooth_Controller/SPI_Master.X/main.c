/* SPI_Master
 * Bluetooth Module HC-05 Interfacing
 * File:   main.c
 * Author: fady
 *
 * Created on May 15, 2024, 3:04 PM
 */

//------------Preprocessor--------------
#include <stdint.h>
#include "Config.h"
#include <xc.h>
#define _XTAL_FREQ 4000000
//--[ Control Data ]--
#define UP    49  // ASCII of 1
#define DOWN  50  // ASCII of 2
#define SEND  51  // ASCII of 3
// Global_Var
uint8_t data=0;
uint8_t UART_Buffer = 0;
//----------prototype-------------
void SPI_Master_init(void);
void SPI_Write_data(uint8_t);
void UART_RX_Init(void);

//--------port_initialization----------
// initializes portB&D and configures I/O pins
// RD0-3 are output pins (LEDs)
void port_init(void){
TRISD&=~0x0F;	// RD0-4 as output
PORTD=0;		// initial state is low
}

//---------Main_Routine----------
void main(void) {
SPI_Master_init();
UART_RX_Init();
port_init();
while(1){
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
void SPI_Write_data(uint8_t data){
SSPBUF=data;	// write data to the buffer
}

//---------UART_initialization-----------
// Needed for communication with the HC-05 bluetooth module
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

//------------ISR-----------------
// Reads received data from HC-05 using UART protocol
void __interrupt() ISR (void){
  if (RCIF == 1)
  {
    UART_Buffer = RCREG; // Read The Received Data Buffer
 
    // This could have been done within the main loop. Since it's not
    // Excessive processing, so it's OK to do it here below
    if(UART_Buffer == UP)
      data++; // Increment data
    if(UART_Buffer == DOWN)
      data--; // Decrement data
    if(UART_Buffer == SEND)
      SPI_Write_data(data); // SPI transmission initiation

    RCIF = 0; // Clear The Interrupt Flag
  }
}