/* 
 * File:   I2C_Master.h
 * Author: fady
 *
 * Created on June 3, 2024, 6:09 PM
 */

//------------Preprocessor--------------
#include <xc.h>
#define _XTAL_FREQ 4000000
//-------------prototype-------------
//[I2C Master]
void I2C_Master_Init(unsigned long BaudRate);
void I2C_Master_Wait(void);
void I2C_Master_Start(void);
void I2C_Master_Stop(void);
void I2C_Master_Repeated_Start(void);
void I2C_ACK(void);
void I2C_NACK(void);
unsigned char I2C_Master_Write(unsigned char);
unsigned char I2C_Read_Byte(void);

