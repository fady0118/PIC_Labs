/* UART_HC-05_Bluetooth_DC_MOTOR_Controller
 * File:   main.c
 * Author: fady
 *
 * Created on May 11, 2024, 4:28 PM
 */



//---------Preprocessor---------
#include <xc.h>
#include <stdint.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
#define Baud 9600
//--[ Control Data ]--
#define REV    49
#define LVL0   50
#define LVL1   51
#define LVL2   52
#define LVL3   53
//----------prototype--------------
void PWM_duty_cycle(unsigned short int);
void UART_RX_Init(void);
//----------Globals----------------
uint8_t UART_Buffer = 0;
//----------Port_Init--------------
// initializes portA and configures I/O pins
// RD0-1 as output for motor direction
void Port_Init(void){
   TRISD&=~0x03;    // RD0-1 as output for direction
   PORTD=0x01;      // Set RD0 & Clear RD1
}
//---------Timer2_init----------
// Work horse of the PWM module
void Timer2_Init(void){
T2CON&=~0x03;  // 1 prescale value    
}
//--------CCP_PWM_mode_config---------
// RC2 CCP/PWM output pin
void CCP_PWM(void){
PR2=199;         // PR2 controlling the PWM freq 5khz
TRISC&=~0x04;    // RC2/CCP1 PWM output pin
CCP1CON|=0x0C;   // PWM mode   
T2CON|=0x04;     // Enable Timer2
PWM_duty_cycle(0);
}
//-----------Main_routine-----------
void main(void) {
    Port_Init();
    Timer2_Init();
    CCP_PWM();
    UART_RX_Init();
    while(1){
    // everything is handled in the ISR
    }
    return;
}
void UART_RX_Init(){
  BRGH = 1; // Set For High-Speed Baud Rate
  SPBRG = 25; // Set The Baud Rate To Be 9600 bps
  // Enable The Ascynchronous Serial Port
  SYNC = 0;
  SPEN = 1;
  // Set The RX-TX Pins to be in UART mode (not io)
  TRISC6 = 1; // As stated in the datasheet
  TRISC7 = 1; // As stated in the datasheet
  //--[ Enable UART Receiving Interrupts ]--
  RCIE = 1; // UART Receving Interrupt Enable Bit
  PEIE = 1; // Peripherals Interrupt Enable Bit
  GIE = 1; // Global Interrupt Enable Bit
  //------------------
  CREN = 1; // Enable Data Continous Reception
}

void __interrupt() ISR (void){
  if (RCIF == 1)
  {
    UART_Buffer = RCREG; // Read The Received Data Buffer
 
    if(UART_Buffer == REV){ // Reverse motor
    PORTD^=0x03;            // toggle RD0-1 to reverse the motor direction
    }
    if(UART_Buffer == LVL0){ // Motor OFF
    PWM_duty_cycle(0);       // set duty cycle
    PORTC&=~0x04;            // clear RC2/CCP1
    }
    if(UART_Buffer == LVL1){ // Motor 33%
    PWM_duty_cycle(267);       // set duty cycle
    }
    if(UART_Buffer == LVL2){ // Motor 67%
    PWM_duty_cycle(534);       // set duty cycle
    }
    if(UART_Buffer == LVL3){ // Motor 100%
    PWM_duty_cycle(800);       // set duty cycle
    }
    RCIF = 0; // Clear The Interrupt Flag
  }
}

//---------PWM_duty_cycle------------
void PWM_duty_cycle(unsigned short int duty_cycle){
CCP1Y  = duty_cycle & 1;  // duty cycle LSB
CCP1X  = duty_cycle & 2;  // duty cycle 2nd LSB
CCPR1L = duty_cycle >> 2; // duty cycle remaining bits
}