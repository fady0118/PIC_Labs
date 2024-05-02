/* Lab_5.0_Ultrasonic_Sensor_Distance
 * File:   main.c
 * Author: Fady Abd Elshahid
 *
 * Created on April 25, 2024, 12:53 PM
 */

//---------Preprocessor---------
#include <xc.h>
#include "Config.h"
#define _XTAL_FREQ 4000000
//---------Prototype---------
double get_dist(void);
//----------Port_Init--------------
// initializes portA and configures I/O pins
// PB0 as output
// PB1 as input
void Port_Init(void){
    TRISB&=~0x01;    // pins PB0 output (sensor trigger)
    PORTB&=~0x01;    // clear PB0
    TRISB|=0x02;     // pins PB1 input (sensor echo)
    PORTB&=~0x02;    // clear PB1
    TRISC&=~0x3C;     // PortC pins 2-5 output (LEDs)
    PORTC&=~0x3C;    // clear PortC pins
}
//---------Timer1_Init-----------
void Timer1_Init(void){
T1CON&=~0x02; // Internal clock (FOSC/4)
T1CON|=0x08;  // Oscillator is enabled
T1CON&=~0x30; // 1:1 prescale value

}

void main(void) {
Port_Init();
Timer1_Init();
unsigned char distance;
while(1){
    distance = get_dist(); // distance resolution is 1cm

    if(distance<=5){PORTC=0x04;}         // flash LED_1     (x<=5cm)       .
    else if(distance<=10){PORTC=0x0C;}   // flash LEDs_1-2  (5cm<x<=10cm)  ..
    else if(distance<=15){PORTC=0x1C;}   // flash LEDs_1-3  (10cm<x<=15cm) ...
    else if(distance<=20){PORTC=0x3C;}   // flash LEDs_1-4  (15cm<x<=20cm) ....
    else{PORTC&=~0x3C;}                  // LEDs off
    __delay_ms(100);     //delay 100ms
}
}

double get_dist(void){
    double dist;
    TMR1=0; // reset timer
    
    //trigger the sensor
    PORTB|=0x01;    // set PB0
    __delay_us(10); // wait 10us
    PORTB&=~0x01;    // clear PB0
    
    // wait for echo
    while(!(PORTB&0x02));
    T1CON|=0x01;  // Enable Timer1
    
    // wait for echo to end
    while((PORTB&0x02));
    T1CON&=~0x01;  // stop Timer1
    
    dist=TMR1/58.823;
    return dist;
}