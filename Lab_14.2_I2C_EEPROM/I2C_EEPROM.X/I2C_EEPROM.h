/* 
 * File:   I2C_EEPROM.h
 * Author: fady
 *
 * Created on June 3, 2024, 1:39 PM
 */

//------------Preprocessor--------------
#include <xc.h>
#include "I2C_Master.h"
#define EEPROM_Address_R 0xA1   
#define EEPROM_Address_W 0xA0
//-------------prototype-------------

//[I2C EEPROM]
void EEPROM_Write(unsigned int add, unsigned char data);
void EEPROM_Write_Page(unsigned int add,unsigned char *data,unsigned char len);
unsigned char EEPROM_Current_Address_Read(void);
unsigned char EEPROM_Byte_Read(unsigned int add);
void EEPROM_Sequential_Read(unsigned int add,unsigned char *data,unsigned char len);