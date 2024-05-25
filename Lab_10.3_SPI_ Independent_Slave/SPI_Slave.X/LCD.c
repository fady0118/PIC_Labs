/*
 * File:   LCD.c
 * Author: fady
 *
 * Created on May 24, 2024, 10:41 AM
 */

//---------Preprocessor---------
#include "LCD.h"

//-----[ Alphanumeric LCD 16x2 Routines ]-----
void LCD_Command(unsigned char CMD) {
     // Select Command Register
    LCD_RS = 0;           
    // Move The Command Data To LCD
    LCD_DATA(CMD);
    // Send The EN Clock Signal
    LCD_EN  = 1;         
    __delay_us(LCD_EN_Delay);
    LCD_EN  = 0;        
}

void LCD_DATA(unsigned char Data) {

  if(Data & 1)
    LCD_D4 = 1;
  else
    LCD_D4 = 0;
  if(Data & 2)
    LCD_D5 = 1;
  else
    LCD_D5 = 0;
  if(Data & 4)
    LCD_D6 = 1;
  else
    LCD_D6 = 0;
  if(Data & 8)
    LCD_D7 = 1;
  else
    LCD_D7 = 0;
}

void LCD_Init(void) {

    // IO Pin Configurations
  LCD_DATA_PORT_D = 0x00;
  LCD_RS_D = 0;
  LCD_EN_D = 0;
  // The Init. Procedure As Described In The Datasheet
  LCD_DATA(0x00);
  __delay_ms(30);
  __delay_us(LCD_EN_Delay); 
  LCD_Command(0x03);
  __delay_ms(5);
  LCD_Command(0x03);
  __delay_us(150);
  LCD_Command(0x03); 
  LCD_Command(0x02);
  LCD_Command(0x02);
  LCD_Command(0x08);
  LCD_Command(0x00);
  LCD_Command(0x0C);
  LCD_Command(0x00);
  LCD_Command(0x06);
}

void LCD_Clear(void){
    LCD_Command(0);
    LCD_Command(1);
}

void LCD_Set_Cursor(unsigned char r, unsigned char c){
    unsigned char Temp,Low4,High4;
    if(r == 1)
    {
      Temp  = 0x80 + c - 1; //0x80 is used to move the cursor
      High4 = Temp >> 4;
      Low4  = Temp & 0x0F;
      LCD_Command(High4);
      LCD_Command(Low4);
    }
    if(r == 2)
    {
      Temp  = 0xC0 + c - 1;
      High4 = Temp >> 4;
      Low4  = Temp & 0x0F;
      LCD_Command(High4);
      LCD_Command(Low4);
    }
}

void LCD_Write_Char(char Data)
{   
   char Low4,High4;
   Low4  = Data & 0x0F;
   High4 = Data & 0xF0;
   LCD_RS = 1;  
   LCD_DATA(High4>>4);  
   LCD_EN = 1;
   __delay_us(LCD_EN_Delay); 
   LCD_EN = 0;
   __delay_us(LCD_EN_Delay); 
   LCD_DATA(Low4); 
   LCD_EN = 1;
   __delay_us(LCD_EN_Delay); 
   LCD_EN = 0;
   __delay_us(LCD_EN_Delay); 
}

void LCD_Write_String(char *str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
       LCD_Write_Char(str[i]);
}

void LCD_SL(void){
    LCD_Command(0x01);
    LCD_Command(0x08);
}

void LCD_SR(void){
    LCD_Command(0x01);
    LCD_Command(0x0C);
}