//------------Preprocessor--------------
#include "I2C_Master.h"
//-----------I2C_Functions_Implementation-------------
void I2C_Master_Init(unsigned long BaudRate){
    TRISC|=0x18;    // RC3/SCL & RC4/SDA are inputs
    SSPADD=(_XTAL_FREQ/(4*BaudRate))-1; // Set the baud-rate
    SSPCON=0x28;    // Select Master mode & Enables the serial port and 
    // configures the SDA and SCL pins as the serial port pins
    SSPCON2 = 0;
    SSPSTAT = 0;
}

void I2C_Master_Wait(void){
    while((SSPSTAT&0x04) || (SSPCON2&0x1F));    // wait for master to be idle
}

void I2C_Master_Start(void){
    I2C_Master_Wait();
    SEN=1;  // Initiate Start condition on SDA and SCL pins
}

void I2C_Master_Stop(void){
    I2C_Master_Wait();
    PEN=1;  // Initiate Stop condition on SDA and SCL pins
}

void I2C_Master_Repeated_Start(void){
    I2C_Master_Wait();
    RSEN=1;  // Initiate Repeated Start condition on SDA and SCL pins
}

void I2C_ACK(void){
    // Initiate I2C ACK Condition Sequence
    I2C_Master_Wait();
    ACKDT=0;
    ACKEN=1;
}
void I2C_NACK(void){
    // Initiate I2C ACK Condition Sequence
    I2C_Master_Wait();
    ACKDT=1;
    ACKEN=1;
}

unsigned char I2C_Master_Write(unsigned char data){
  I2C_Master_Wait();
  SSPBUF = data;
  while(!SSPIF); // Wait Until Completion
  SSPIF = 0;
  return ACKSTAT;
}

unsigned char I2C_Read_Byte(void){
    I2C_Master_Wait();
    RCEN = 1; // Enable & Start Reception
    while(!SSPIF); // Wait Until Completion
    SSPIF = 0; // Clear The Interrupt Flag Bit
    I2C_Master_Wait();
    return SSPBUF; // Return The Received Byte
}
 
