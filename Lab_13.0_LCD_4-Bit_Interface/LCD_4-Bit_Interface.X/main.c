/*
 * File:   main.c
 * Author: fady
 *
 * Created on May 24, 2024, 11:13 AM
 */

//---------Preprocessor---------
#include <xc.h>
#include "LCD.h"
#include "Config.h"

//------------Main_Routine--------------
void main(void) { 
    LCD_Init();
    LCD_Clear();
    LCD_Set_Cursor(1,1);
    
    LCD_Set_Cursor(1,6);
    LCD_Write_String("HELLO\0");
    LCD_Set_Cursor(2,6);
    LCD_Write_String("WORLD\0");
       for(int i=0; i<6; i++)
    {
      __delay_ms(300);
      LCD_SR();
    }
    while(1){
    
    for(int i=0; i<11; i++){
      __delay_ms(300);
      LCD_SL();
    }
       for(int i=0; i<11; i++){
      __delay_ms(300);
      LCD_SR();
    }
    
    }
    return;
}
