/*
 * File:   I2C_EEPROM.c
 * Author: fady
 *
 * Created on June 3, 2024, 5:54 PM
 */

//------------Preprocessor--------------
#include "I2C_EEPROM.h"

//---------------[ I2C EEPROM Routines ]----------------
//-----[ Write Operations ]-----
// EEPROM Write Byte
void EEPROM_Write(unsigned int add, unsigned char data){
    I2C_Master_Start();
    
    // Wait Until EEPROM Is IDLE
    while(I2C_Master_Write(EEPROM_Address_W)){
    I2C_Master_Repeated_Start();}

    I2C_Master_Write(add>>8);               // First word address
    I2C_Master_Write((unsigned char)add);   // Second word address
    I2C_Master_Write(data);                 // Write data byte
    I2C_Master_Stop();
}
// EEPROM Write Page
void EEPROM_Write_Page(unsigned int add,unsigned char *data,unsigned char len){
    I2C_Master_Start();
    
    // Wait Until EEPROM Is IDLE
    while(I2C_Master_Write(EEPROM_Address_W)){
    I2C_Master_Repeated_Start();}
    
    I2C_Master_Write(add>>8);               // First word address
    I2C_Master_Write((unsigned char)add);   // Second word address
    for(unsigned short i=0;i<len;i++){
        I2C_Master_Write(data[i]);
    }
    I2C_Master_Stop();
}
//-----[ Read Operations ]-----
// EEPROM Current Address Read
unsigned char EEPROM_Current_Address_Read(void){
    unsigned char Data;
    I2C_Master_Start();
    // Wait Until EEPROM Is IDLE
    while(I2C_Master_Write(EEPROM_Address_W)){
    I2C_Master_Repeated_Start();}
    
    Data = I2C_Read_Byte();
    void I2C_NACK(void);
    I2C_Master_Stop();
    
    return Data;
}

// EEPROM Byte Read
unsigned char EEPROM_Byte_Read(unsigned int add){
    unsigned char Data;
    I2C_Master_Start();
    
    // Dummy write
    while(I2C_Master_Write(EEPROM_Address_W)){
    I2C_Master_Repeated_Start();}
    I2C_Master_Write(add>>8);
    I2C_Master_Write((unsigned char)add);
    I2C_Master_Repeated_Start();
    
    I2C_Master_Write(EEPROM_Address_R);
    Data = I2C_Read_Byte();
    I2C_NACK();
    I2C_Master_Stop();
    
    return Data;
}

// EEPROM Sequential Read
void EEPROM_Sequential_Read(unsigned int add,unsigned char *data,unsigned char len){
    I2C_Master_Start();
    
    while(I2C_Master_Write(EEPROM_Address_W)){
    I2C_Master_Repeated_Start();}
    
    I2C_Master_Write(add>>8);
    I2C_Master_Write((unsigned char)add);
    I2C_Master_Repeated_Start();
    I2C_Master_Write(EEPROM_Address_R);
    
    for(unsigned short i=0;i<len;i++){
        data[i]=I2C_Read_Byte();
        I2C_ACK();
    }
    I2C_NACK();
    I2C_Master_Stop();
}
