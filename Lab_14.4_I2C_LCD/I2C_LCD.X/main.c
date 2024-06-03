/*
 * File:   main.c
 * Author: fady
 *
 * Created on June 3, 2024, 7:16 PM
 */

//------------Preprocessor--------------
#include "Config.h"
#include "I2C_LCD.h"
#include <xc.h>

void main(void) {
    I2C_Master_Init();
    LCD_Init(0x40);     // Initialize LCD with I2C address = 0x40 (A0,1,2 LOW)
    
    LCD_Set_Cursor(1, 7);
    LCD_Write_String("NAIL");
    LCD_Set_Cursor(2, 7);
    LCD_Write_String("GUN!");
    __delay_ms(500);   // 0.5 sec delay
    for(int i=0;i<6;i++){
        LCD_SR();
        __delay_ms(250);   // 0.25 sec delay
    }
    while(1)
    {   
        for(int i=0;i<12;i++){
            LCD_SL();
            __delay_ms(250);   // 0.25 sec delay
        }
        for(int i=0;i<12;i++){
           LCD_SR();
           __delay_ms(250);   // 0.25 sec delay
        }
        
    }
    return;
}
