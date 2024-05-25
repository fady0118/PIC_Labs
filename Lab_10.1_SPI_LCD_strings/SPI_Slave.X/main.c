/* SPI_Slave
 * File:   main.c
 * Author: fady
 *
 * Created on May 14, 2024, 8:11 PM
 */


//------------Preprocessor--------------
#include <stdint.h>
#include <stdbool.h>
#include "Config.h"
#include <xc.h>
#include "LCD.h"
#define LEN 9
// Global
char string[20];
bool LCD_Flag=0;
volatile uint8_t i=0;
//----------prototype-------------
void SPI_Slave_init(void);
void SPI_Read_String(uint8_t *Output, uint16_t length);
uint8_t SPI_Read(void);
//--------port_initialization----------
// initializes portB and configures I/O pins
// RB0-3 are output pins (LEDs)
void port_init(void){
TRISC&=~0x01;	// RC0 as input
PORTC=0;		// initial state is low
}

//---------Main_Routine----------
void main(void) {
    SPI_Slave_init();
    port_init();
    LCD_Init();
    LCD_Clear();
 
    while(1){
    if(RC0==1){
    LCD_Clear();
    LCD_Set_Cursor(1,1);
    }
    if(LCD_Flag == 1){
    LCD_Set_Cursor(1,1);
    LCD_Write_String(string);
    LCD_Flag=0;
    }
    }
    return;
}
//----------SPI_Slave_mode_initialization----------
void SPI_Slave_init(void){
// SPI Slave mode, clock = SCK pin, SS line enabled 
SSPM0=0;
SSPM1=0;
SSPM2=1;
SSPM3=0;

// Enable SPI synchronous serial port 
SSPEN=1;

// Configure the serial clock polarity and phase [same as Master]
CKP=0;	// Idle state for clock is a low level
CKE=0;	// Transmit occurs on transition from Idle to active clock state

// Clear SMP bit
SMP=0;  // SMP must be cleared in slave mode

// IO pins configuration
// set SS line (RA5/AN4) as Digital I/O [ADCON1 REGISTER]
PCFG0=0;
PCFG1=0;
PCFG2=1;
PCFG3=0;
TRISA5=1;   // SS/RA5  input

TRISC3=1;	// SCK/RC3 input
TRISC4=1;	// SDI/RC4 input
TRISC5=0;	// SDO/RC5 output

// Enable SPI reception interrupts 
SSPIE=1;	// enable SPI interrupts
PEIE=1;		// enable peripheral interrupts
GIE=1;		// enable general interrupts

}
//----------ISR------------
void __interrupt() ISR(void){
    if(SSPIF){
    SSPIF=0;    // clear interrupt flag
    if (BF){
        string[i]=SSPBUF;
        i++;
        if(i>=LEN){
            LCD_Flag=1;
            i=0;
        }

    }
    }
}