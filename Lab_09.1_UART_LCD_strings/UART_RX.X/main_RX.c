/* Lab_9.1_UART_LCD_strings
 * UART_RX
 * File:   main_RX.c
 * Author: fady
 *
 * Created on May 8, 2024, 1:57 PM
 */

//------------Preprocessor--------------
#include <xc.h>
#include <stdint.h>
#include "Config.h"
#include "LCD.h"
#define Baud 9600
//----------prototype-------------
void UART_RX_Init(void);
uint8_t UART_Read(void);
void UART_Read_String(uint8_t *Output, uint16_t length);

void main(void) {
    UART_RX_Init(); // Initialize The UART in Slave Mode @ 9600bps
    LCD_Init();
    LCD_Clear();
    
    while(1){
       if(RC0){
       LCD_Clear();
       } 
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
 
uint8_t UART_Read(){
  while(!RCIF); // Wait Untill a Data Frame is Received
  return RCREG;
}
 
void UART_Read_String(uint8_t *Output, uint16_t length){
  uint16_t i;
  for(int i=0;i<length;i++)
    Output[i] = UART_Read();
}
 
// You Can Also Use The ISR If You Want To !
void __interrupt() ISR (void){
    char x[25];
  if (RCIF == 1)
  {
    UART_Read_String(x,7);     // Read The RCREG Buffer Register...
    LCD_Set_Cursor(1,1);
    LCD_Write_String(x);
    RCIF = 0;               // Clear The Flag
  }
}