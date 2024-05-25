/* 
 * File:   LCD.h
 * Author: fady
 *
 * Created on May 24, 2024, 10:41 AM
 */


#include <xc.h>

#define _XTAL_FREQ 4000000

#define LCD_EN_Delay 500
#define LCD_DATA_PORT_D TRISB
#define LCD_RS_D TRISB5
#define LCD_EN_D TRISB4
#define LCD_RS RB5
#define LCD_EN RB4
#define LCD_D4 RB0
#define LCD_D5 RB1
#define LCD_D6 RB2
#define LCD_D7 RB3

//==========================================
//-----[ Prototypes For All Functions ]-----

void LCD_Init(void);  // Initialize The LCD For 4-Bit Interface
void LCD_Clear(void); // Clear The LCD Display
void LCD_SL(void);    // Shift The Entire Display To The Left
void LCD_SR(void);    // Shift The Entire Display To The Right

void LCD_Command(unsigned char);   // Send Command To LCD
void LCD_DATA(unsigned char);  // Send 4-Bit Data To LCD
void LCD_Set_Cursor(unsigned char, unsigned char);  // Set Cursor Position
void LCD_Write_Char(char);     // Write Character To LCD At Current Position
void LCD_Write_String(char*);  // Write A String To LCD
//------------------------------------------
