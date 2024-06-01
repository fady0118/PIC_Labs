/* I2C_Master
 * File:   main.c
 * Author: fady
 *
 * Created on June 1, 2024, 7:58 PM
 */
// The Master firmware for I2C Communication network

//------------Preprocessor--------------
#include "Config.h"
#include <xc.h>
#define _XTAL_FREQ 4000000      // Fosc
#define I2C_BaudRate 100000     // Baud Rate = 100 Kbps
#define SLAVE_1 RB0
#define SLAVE_2 RB1
unsigned char Address=0x41;
//----------prototype-------------
void I2C_Master_Init(void);
void I2C_Wait(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Restart(void);
void I2C_ACK(void);
void I2C_NACK(void);
unsigned char I2C_Write(unsigned char Data);
unsigned char I2C_Read(void);

//--------port_initialization----------
// initializes I/O ports and configures I/O pins
void port_init(void){
    TRISB|=0x03;    // RB0 & RB1 inputs
    PORTB=0;        // initial state low
    TRISD&=~0xFF;   // RD0-7 outputs
    PORTD=0;        // initial state low
}

//---------Main_Routine----------
void main(void) {
    port_init();
    I2C_Master_Init();
    while(1){
        if(SLAVE_1){ Address=0x41;}
        if(SLAVE_2){ Address=0x61;}
    I2C_Start();        // I2C Start Sequence
    I2C_Write(Address);    // Send Address + Read request bit 
    PORTD = I2C_Read(); // Read data
    I2C_Stop();         // I2C Stop Sequence
    __delay_ms(100);
    }
    return;
}
//-----------I2C_Functions_Implementation-------------
void I2C_Master_Init(void){
    TRISC|=0x18;    // RC3/SCL & RC4/SDA as input
    SSPADD=(_XTAL_FREQ/(4*I2C_BaudRate))-1;
    SSPCON|=0x08;   // Select I2C Master mode
    SSPEN=1;        // Enables the serial port
}
void I2C_Wait(void){
    while((SSPSTAT&0x04) || (SSPCON2&0x1F));
}
void I2C_Start(void){
    // Initiate I2C Start Condition Sequence
    I2C_Wait();
    SEN=1;
}
void I2C_Stop(void){
    // Initiate I2C Stop Condition Sequence
    I2C_Wait();
    PEN=1;
}
void I2C_Restart(void){
    // Initiate I2C Restart Condition Sequence
    I2C_Wait();
    RSEN=1;
}
void I2C_ACK(void){
    // Initiate I2C ACK Condition Sequence
    I2C_Wait();
    ACKDT=0;
    ACKEN=1;
}
void I2C_NACK(void){
    // Initiate I2C ACK Condition Sequence
    I2C_Wait();
    ACKDT=1;
    ACKEN=1;
}
unsigned char I2C_Write(unsigned char Data){
    I2C_Wait();
    SSPBUF=Data;
    I2C_Wait();
    return ACKSTAT;
}
unsigned char I2C_Read(void){
    unsigned char Data;
    I2C_Wait();
    RCEN=1;     // Enables Receive mode for I2C
    I2C_Wait();
    Data = SSPBUF;
    I2C_NACK();
    return Data;
}