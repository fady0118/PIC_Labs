/* I2C_EEPROM
 * File:   main.c
 * Author: fady
 *
 * Created on June 3, 2024, 12:18 PM
 */

//------------Preprocessor--------------
#include "Config.h"
#include "I2C_EEPROM.h"
#include "I2C_Master.h"
/*  The device address word consists of a mandatory one, zero sequence (1010) 
    for the first four most significant bits
*/

//--------port_initialization----------
// initializes I/O ports and configures I/O pins
void port_init(void){
    TRISD&=~0xFF;   // RD0-7 outputs
    PORTD=0;        // initial state low
}

//---------Main_Routine----------
void main(void) {
    port_init();
    I2C_Master_Init(100000); // Initiate I2C Master mode with 100KHz baud rate
    
    // EEPROM Write data then Read them 
    unsigned int Address=0x0022;        // random address to write to
    unsigned char data=0x01;            // random data to write

    EEPROM_Write(Address,data);         // Write 0x01 @ 0x0040
    __delay_ms(10);  
    EEPROM_Write(++Address,++data);     // Write 0x02 @ 0x0041
    __delay_ms(10);  
    EEPROM_Write(++Address,++data);     // Write 0x03 @ 0x0042
    __delay_ms(10);                  // Wait tWR=10ms For Write To Complete
    
    Address=0x0022;
    PORTD=EEPROM_Byte_Read(Address);    // Read data @ 0x0040
    __delay_ms(1000);   // 1 Sec delay
    PORTD=EEPROM_Byte_Read(++Address);    // Read data @ 0x0041
    __delay_ms(1000);   // 1 Sec delay
    PORTD=EEPROM_Byte_Read(++Address);    // Read data @ 0x0042
    __delay_ms(1000);   // 1 Sec delay
    
    while(1){
        // Stay Idle
    }
    return;
}
