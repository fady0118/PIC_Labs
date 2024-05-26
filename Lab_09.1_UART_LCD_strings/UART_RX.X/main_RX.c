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
#define LCD_CLEAR RC0
char string[20];
uint8_t LCD_FLAG=0;
uint8_t i=0;
//----------prototype-------------
void UART_RX_Init(void);
uint8_t UART_Read(void);
void UART_Read_String(uint8_t *Output, uint16_t length);

void main(void) {
    UART_RX_Init(); // Initialize The UART in Slave Mode @ 9600bps
    LCD_Init();
    LCD_Clear();
    LCD_Set_Cursor(1,1);
    while(1){
       if(LCD_CLEAR){
       LCD_Clear();
       LCD_Set_Cursor(1,1);
       }
       if(LCD_FLAG==1){
       LCD_Set_Cursor(1,1);
       LCD_Write_String(string);
       LCD_FLAG=0;
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

void __interrupt() ISR (void){
  if (RCIF == 1){
    string[i]=RCREG;
    i++;
    if(string[i-1]=='\0'){
        LCD_FLAG=1;
        i=0;
    }
    RCIF = 0;   // Clear The Flag
  }
}