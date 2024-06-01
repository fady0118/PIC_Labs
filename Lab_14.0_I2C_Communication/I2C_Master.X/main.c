/* I2C_Master
 * File:   main.c
 * Author: fady
 *
 * Created on June 1, 2024, 2:17 PM
 */

//------------Preprocessor--------------
#include "Config.h"
#include <xc.h>
#define _XTAL_FREQ 4000000 // Fosc
#define I2C_BaudRate 100000 // I2C Baud Rate = 100 Kbps
// [Macros]
#define LED RC5
//----------prototype-------------
void I2C_Master_init(void);
void I2C_Wait(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Restart(void);
void I2C_ACK(void);
void I2C_NACK(void);
unsigned char I2C_Write(unsigned char Data);
//--------port_initialization----------
// initializes PortC and configures I/O pins
// RC5 is an output pin (LED)
void port_init(void){
TRISC&=~0x20;	// RC5 as Output pin
PORTC=0;		// initial state is low
}

//---------Main_Routine----------
void main(void) {
    port_init();
    I2C_Master_init();
    unsigned char i=1;
    while(1){
    I2C_Start();        // Initiate Start Condition
    I2C_Write(0x40);    // Send the address and R/W bit
    I2C_Write(i++);     // Send the data byte
    I2C_Stop();         // Initiate Stop Condition
    __delay_ms(500);    
    LED^=1;             // toggle led
    }
    
    return;
}

//--------I2C_Functions_Implementation----------
void I2C_Master_init(void){
    SSPCON=0x28;   // Select Master mode
                    // Enable the serial port and configures 
                    // the SDA and SCL pins as the serial port pins  
    TRISC|=0x18;    // RC3 & RC4 Input pins
    SSPCON2=0;
    SSPSTAT=0;
    SSPADD=(_XTAL_FREQ/(4*I2C_BaudRate)) - 1;
    
    
    
}

void I2C_Wait(void){
    while( (SSPSTAT & 0x04) || (SSPCON2 & 0x1F) );   // Wait for I2C to be idle
}

void I2C_Start(void){
    // Initiate Start Condition
    I2C_Wait();
    SEN=1;
}

void I2C_Stop(void){
    // Initiate Stop Condition
    I2C_Wait();
    PEN=1;
}

void I2C_Restart(void){
    // Initiate Restart Condition
    I2C_Wait();
    RSEN=1;
}

void I2C_ACK(void){
    // Send ACK for Master-Receiver mode
    I2C_Wait();
    ACKDT=0;    // 0 -> ACK, 1 -> NACK
    ACKEN=1;    // Initiate Acknowledge sequence
}

void I2C_NACK(void){
    // Send NACK for Master-Receiver mode
    I2C_Wait();
    ACKDT=1;    // 0 -> ACK, 1 -> NACK
    ACKEN=1;    // Initiate Acknowledge sequence
}

unsigned char I2C_Write(unsigned char Data){
  //---[ Send Byte, Return The ACK/NACK ]---
  I2C_Wait();
  SSPBUF = Data;
  I2C_Wait();
  return ACKSTAT;
}