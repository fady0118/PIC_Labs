/* SPI_Slave
 * File:   main.c
 * Author: fady
 *
 * Created on May 25, 2024, 5:50 PM
 */

//------------Preprocessor--------------
#include <xc.h>
#include <stdint.h>
#include "Config.h"
#include "LCD.h"
// Macros
#define CLEAR_LCD RC0
// Global
char string[20];
uint8_t i=0;
uint8_t LCD_Flag=0;
uint8_t LEN;
//----------prototype-------------
void SPI_Slave_Init(void);
void Shift_String_Left(char*);
//------------Main_Routine--------------
void main(void) {
    SPI_Slave_Init();
    LCD_Init();
    LCD_Clear();
    LCD_Set_Cursor(1,1);
    while(1){
        if(CLEAR_LCD){
        LCD_Clear();    // clear LCD
        LCD_Set_Cursor(1,1);
        }
        
        if(LCD_Flag==1){
        Shift_String_Left(string);
        LCD_Set_Cursor(1,1);
        LCD_Write_String(string);
        LCD_Flag=0;     // clear flag    
        }
    }
    return;
}
//-----------Functions_Implementations------------
//---------SPI_Slave_Init-----------
void SPI_Slave_Init(void){
// SPI Slave mode, clock = SCK pin. SS pin control enabled SSPM3:SSPM0 -> 0100
    SSPM0=0;
    SSPM1=0;
    SSPM2=1;
    SSPM3=0;
// Enable Synchronous Serial Port 
    SSPEN=1;
    CKP=0;      // Idle state for clock is a low level
    CKE=0;      // Transmit occurs on Leading edge
// SMP must be cleared when SPI is used in Slave mode (Datasheet)    
    SMP=0;     
// I/O configuration
    TRISC3=1;
    TRISC4=1;
    TRISC5=0;
    // set SS line (RA5/AN4) as Digital I/O [ADCON1 REGISTER]
    PCFG0=0;
    PCFG1=0;
    PCFG2=1;
    PCFG3=0;
    TRISA5=1;   // SS/RA5  input
    // Enable SPI Interrupts
    SSPIE=1;
    PEIE=1;
    GIE=1;
}


//------------ISR----------------
void __interrupt() ISR(void){
    if(SSPIF){
    SSPIF=0;    // clear interrupt flag
        string[i]=SSPBUF;
        i++;
        LEN=string[0]-0x30;  // first element is the string length (converted form ASCII)
        if(i>LEN){
            string[i]='\0'; // Terminate the flag
            LCD_Flag=1;     // Set LCD flag
            i=0;
        }
    }
}

void Shift_String_Left(char* str){
        int i;
        for(i=0;str[i+1]!='\0';i++){
            // shift each character one position to the left
            str[i]=str[i+1];
        }
        str[i]='\0';    // Null-terminate the string

}