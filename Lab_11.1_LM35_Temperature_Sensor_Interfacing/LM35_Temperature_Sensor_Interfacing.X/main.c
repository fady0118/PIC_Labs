/* LM35_Temperature_Sensor_Interfacing
 * File:   main.c
 * Author: fady
 *
 * Created on May 20, 2024, 12:40 PM
 */

//---------Preprocessor---------
#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
//Global_variable
uint16_t result=0;
double Temperature;
char* Temp_String[25];
//----------prototype-------------
void ADC_Read(uint8_t);
void ADC_Init(void);
void UART_TX_Init(void);
void UART_Write(uint8_t);
void UART_Write_String(char *);
//------------Main_Routine--------------
void main(void) {
    ADC_Init();
    UART_TX_Init();
    while(1){
    // Read The ADC
    ADC_Read(3);    // initiate conversion and update result variable
    // Calculate The Temperature 
        // The ADC is 10-bit meaning the resolution is 5v/2^10 =4.88mv
        // LM35 datasheet states a Linear + 10-mV/°C Scale Factor
        // Temperature is the A/D digital value * 0.488°C
    Temperature = result*0.488;
    // Convert The Temperature From Float To String
    sprintf(Temp_String, "Temperature is -> %.3fc \r\n", Temperature);
    // Print Out The Temperature
    UART_Write_String(Temp_String);
    __delay_ms(10);
    }
    return;
}
//-----------Functions_Implementations------------
//--------ADC_initialization-------------
void ADC_Init(void){
ADCON0|=0x59;   // Turn ADC ON, Select AN3 Channel, ADC Clock = Fosc/8
ADCON1|=0x80;   // All 8 Channels Are Analog, Result is "Right-Justified"
//interrupts
ADIF=0;
ADIE=1;
PEIE=1;
GIE=1;
}
//-----------AD_conversion-------------
// Input: Analog channel number
void ADC_Read(uint8_t AN){
    if(AN>=0 && AN<=7){ // Check Channel Number Validity
    ADCON0&=~0x38;      // clear channel selection
    ADCON0|=AN<<3;      // channel selection
    __delay_us(30);     // Wait The Acquisition Time
    ADCON0|=0x04;       // Set GO/DONE    
    }
    else {result=0;}
}
//------------ISR----------------
void __interrupt() ISR(void){
    if(ADIF){
    ADIF=0;             // clear interrupt flag
    result=(ADRESH<<8)+ADRESL;
    }
}

//---------UART_Implementation-----------
void UART_TX_Init(void){
// baud rate
    BRGH=1;          // Set For High-Speed Baud Rate
    SPBRG=25;        // Set The Baud Rate To Be 9600 bps
// ASync serial
    SYNC=0;          // Asynchronous mode
    SPEN=1;          // Enable Serial Port
// Set The RX-TX Pins to be in UART mode
    TRISC&=~0x40;    // RC6/TX output
    TRISC|=0x80;     // RC7/RX output
    TXEN = 1;        // Enable UART Transmission 
}

void UART_Write(uint8_t data)
{
  while(!TRMT);  // wait for TSR to be empty
  TXREG = data;  // Load the data
}

void UART_Write_String(char *text){
uint8_t i;
for(i=0;text[i]!='\0';i++){
UART_Write(text[i]);}
}
