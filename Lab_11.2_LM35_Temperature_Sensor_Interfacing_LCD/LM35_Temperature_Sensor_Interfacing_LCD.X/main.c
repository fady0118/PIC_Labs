/* LM35_Temperature_Sensor_Interfacing_LCD
 * File:   main.c
 * Author: fady
 *
 * Created on May 20, 2024, 2:47 PM
 */

//---------Preprocessor---------
#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include "Config.h"
#include "LCD.h"
#define _XTAL_FREQ 4000000
//Global_variable
uint16_t result=0;
double Temperature;
char* Temp_String[25];
//----------prototype-------------
void ADC_Read(uint8_t);
void ADC_Init(void);

//------------Main_Routine--------------
void main(void) {
    return;
}
