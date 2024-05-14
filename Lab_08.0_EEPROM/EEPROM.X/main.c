/* EEPROM
 * File:   main.c
 * Author: fady
 *
 * Created on May 2, 2024, 11:08 PM
 */

//---------Preprocessor---------
#include "Config.h"
#include <xc.h>
#define _XTAL_FREQ 4000000
//----------prototype-------------
void write_EEPROM(uint8_t address,uint8_t data);
uint8_t Read_EEPROM(uint8_t address);
//----------Port_Init--------------
// initializes portA and configures I/O pins
// RB0-3 as input for buttons
// RC0-3 as output LEDs
void Port_Init(void){
  TRISB |= 0x0F; // Push Buttons (Inputs)
  PORTB = 0;    // Initially OFF
  TRISC &= ~0x0F; // Output LEDs
  PORTC = 0x00; // Initially OFF
}
//-----------Main_loop-----------
void main(void) {
    Port_Init();
    uint8_t Address=0;
    while(1){
    if(RB0) // Write 0x03
    {
      write_EEPROM(Address++, 3);
      __delay_ms(500);
    }
    if(RB1) // Write 0x05
    {
      write_EEPROM(Address++, 5);
      __delay_ms(500);
    }
    if(RB2) // Write 0x07
    {
      write_EEPROM(Address++, 7);
      __delay_ms(500);
    }
    if(Address==3){Address=0;}
    
    if(RB3) // read data
    {
    // Read EEPROM data to PORTC
        for(int i=0;i<3;i++){
        PORTC=Read_EEPROM(i);
         __delay_ms(1000);
        } 
    }
       
    }
    return;
}
//-----------Writing to Data EEPROM Memory------------
void write_EEPROM(uint8_t address,uint8_t data){
char GIE_status=GIE;
while(WR);          // Waits Until Last Attempt To Write Is Finished
EEADR=address;      // Write the address to EEADR.
EEDATA=data;        // Write the 8-bit data value in EEDATA
EEPGD=0;            // Clear the EEPGD bit to point to EEPROM data memory
WREN=1;             // Enable program operations
GIE=0;              // Disable interrupts
// the special five instruction sequence
EECON2=0x55;        
EECON2=0xAA;
WR=1;               
GIE=1;     // Restore interrupts to its original state
WREN=0;             // Disable program operations
WR=0;               // Ready For Next Writing Operation
}

//-----------Reading Data EEPROM Memory------------
uint8_t Read_EEPROM(uint8_t address){
uint8_t Data;
EEADR=address;
EEPGD=0;
RD=1;
Data=EEDATA;
return Data;
}