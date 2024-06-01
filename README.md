# PIC_Labs
Embedded projects using pic16f877a microcontroller.\
Coded in MPLAB X IDE.\
Simulated in Proteus 8 Professional
![medium-PIC16F877A-PDIP-40](https://github.com/fady0118/PIC_Labs/assets/121246084/42e68fce-8ce4-482e-8879-d901ca14ea78)

## Labs
### Lab_1.0_GPIO_blinking_led

#### Purpose 
- Use GPIO pins for generating a digital output signal and use it for flashing an LED.
#### Components   
- Interface includes one LED and one switch
#### Configuration
- PB0 -> input from switch
- PB1 -> output to LED


### Lab_1.1_ON_OFF_MultiSwitch_LED

#### Purpose 
- Use GPIO pins for generating a digital output signal and use it for toggeling an LED.
#### Components   
- Interface includes one LED and 3 switches
#### Configuration
- PB0,1,2 -> input from switches
- PB3 -> output to LED

### Lab_1.2_Flashing_LEDs

#### Purpose 
- Use GPIO pins for generating a digital output signal and use it for flashing some LEDs.
#### Components   
- Interface includes 3 LEDs and 3 switches
#### Configuration
- PB0,1,2 -> input from switches
- PB3,4,5 -> output to LEDs

### Lab_2.0_7-Segment_display

#### Purpose 
- Use GPIO pins for generating a digital output signal and use it for 7-segment display.
#### Components   
- Interface includes a 7-segment display
#### Configuration
- PB1~7 -> output to 7-segment display pins

### Lab_3.0_Unipolar_Stepper_Motor

#### Purpose 
- drive unipolar stepper motor, do rotation in clockwise then counter clockwise, while waiting 1 sec after every ratation
#### Components   
- 1-unipolar stepper motor
- stepper motor driver (ULN2003A)
- battery
- diode to protect the motor driver form voltage spikes
#### Configuration
- PC0-3 -> output to the motor driver

### Lab_3.1_Bipolar_Stepper_Motor

#### Purpose 
- drive bipolar stepper motor, do rotation in clockwise then counter clockwise, while waiting 1 sec after every ratation
#### Components   
- 1-Bipolar stepper motor
- stepper motor driver (L293D)
- battery
#### Configuration
- PB0-3 -> output to the motor driver  

### Lab_4.0_1-second_Delay_with_Timer1

#### Purpose 
- configure the Timer1 Module in PIC Microcontroller to operate in the timer mode. And also to use it to generate 1-Second time interval, which will be used to toggle an LED to indicate the termination of the time interval
#### Components   
- LED
#### Configuration
- PB0 -> output to the LED

### Lab_4.1_Timer_Mode_LEDs

#### Purpose 
- use the timer in counter mode
#### Components   
- 4 LEDs
- button, capacitor, Schmitt trigger
#### Configuration
- PB0-3 -> output to the LEDs
- PC1 -> input from the button (external clock)

### Lab_4.2_Timer_Mode_7-segment

#### Purpose 
- This is just an alternative to Lab_4.1 with 7-segment display instead of the LEDs
#### Components   
- 7-segment display
- button, capacitor, Schmitt trigger
#### Configuration
- PB0-6 -> output to the 7-segment display
- PC1 -> input from the button (external clock)


### Lab_5.0_Ultrasonic_Sensor_Distance

#### Purpose 
- Read distance measures from HC_SR04 ultrasonic sensor & output them as an LED code
#### Components   
- HC_SR04 ultrasonic sensor
- 4-LEDs
#### Configuration
- PB0 -> output to HC_SR04 ultrasonic sensor (trigger)
- PB1 -> input from HC_SR04 ultrasonic sensor (echo)
- PC2-5 -> output to the LEDs

### Lab_6.0_IRQ_Lab

#### Purpose 
-  Create a basic (LED toggle) application with IRQ hardware pins.
#### Components   
- LED
- Button
#### Configuration
- PB0 -> IRQ hardware pin
- PB2 -> output (LED)

### Lab_7.0_CCP_capture_mode

#### Purpose 
-  use the CCP module in Capture mode.
#### Components   
- 8 LEDs (4 for Timer which is in counter mode) & (4 for CCP capture)
- 2 Button (1 for counter) & (1 for capture)
- Schmitt trigger for button debouncing
#### Configuration
- PB0-3 as output (LEDs) for TMR1
- PD0-3 as output (LEDs) for CPPR1
- RC1 input Counter button
- RC2 input for CCP capture

### Lab_7.1_CCP_compare_mode

#### Purpose 
- Use the CCP module in compare mode.
- Use it to generate periodic interrupts by using timer1 hardware as resource.
- Generate an interrupt every 0.5 sec that toggles the LED.
#### Components   
- LED
#### Configuration
- PB0 as output (LED)

### Lab_7.2.1_CCP_PWM_LED_Dimmer

#### Purpose 
- Use CCP in PWM mode to control the brightness of an LED by continuously changing the duty cycle 
#### Components   
- LED
#### Configuration
- CCP1/RC2 output (LED)

### Lab_7.2.2_CCP_PWM_DC_Motor

#### Purpose 
- Use CCP in PWM mode to control the direction & speed of a DC motor
- The PIC16F877A has only RB0 as IRQ INT (edge-triggered) and RB4-7 as IOC (interrupt-on-change)
- I originally wanted to generate 6 interrupts 1 for direction and 5 for speeds (0 25 50 75 100)
- Unfortunately as stated the PIC16F877A can generate a total of 5 interrupts
- So it's either reduce the speed control levels to 4 or use (polling)
- since it's better to use interrupts we'll resort to reducing the speed levels controls to 4 (0 33 67 100)
#### Components   
- DC Motor
- L293D motor driver
- 5 buttons (1 for reversing the direction & 4 for speed controls)
#### Configuration
- RD0-1 as output for motor direction
- RC2 CCP/PWM output pin (duty cycle)
- RB0 IRQ input (switch) for motor direction control
- RB4-7 as IOC (interrupt-on-change) input (switches) for motor speed control

### Lab_8.0_EEPROM

#### Purpose 
- Use the internal EEPROM Memory to write/read data.
#### Components   
- 4 LEDs
- 4 Buttons
#### Configuration
-  RB0-3 as input C
-  RC0-3 as output LEDs

### Lab_9.0_UART_Communication

#### Purpose 
- Create a serial communication interface between 2 microcontrollers using UART Protocol.
#### Components   
- 8 LEDs
- 3 Buttons
#### Configuration
-  Transmitter
    -  RB0-2 as input for buttons
    -  RD0-3 as output LEDs
    -  RC6 as UART transmitter
-  Reciever
    -  RB0-3 as output LEDs
    -  RC7 UART reciever
      
### Lab_9.1_UART_LCD_strings

#### Purpose 
- Create a serial communication interface between 2 microcontrollers using UART Protocol and use it to send string messages and display it using an 16*2 LCD
#### Components   
- LCD
- 4 Buttons
#### Configuration
-  Transmitter
    -  RB0 , RB1 & RB2 as input for buttons
    -  RC6 as UART transmitter
-  Reciever
    -  RB0-5 as output LCD
    -  RC0 as input for a button
    -  RC7 UART reciever

### Lab_9.2_UART_HC-05_Bluetooth_Controller

#### Purpose 
- This project uses the HC-05 Bluetooth module with PIC microcontrollers. And develop the necessary firmware in order to receive data from a Smartphone over the Bluetooth to control LEDs
- for this to work you'll need to
    - add the HC-05 library to proteus [https://www.theengineeringprojects.com/2018/10/sound-sensor-library-for-proteus.html]
    - open bluetooth settings on your pc
    - go to COM Ports
    - add incoming serial port (COM5 or anything but it must match with the HC-05 configuration)
    - install "serial bluetooth terminal" app form playstore on an android phone
    - open it and select the pc from devices tab
    - connect the phone to the PC using bluetooth 
    - Send "1" to turn on the blue LED
    - Send "2" to turn off the blue LED
    - Send "3" to toggle the yellow LED
#### Components   
- HC-05 Bluetooth Module
- 2 LEDs
#### Configuration
-  Transmitter (HC-05)
    -  TXD as UART transmitter
-  Reciever (PIC16F877A)
    -  RB0-1 as output LEDs
    -  RC7 UART reciever

### Lab_9.3_UART_HC-05_Bluetooth_DC_MOTOR_Controller

#### Purpose 
- This project uses the HC-05 Bluetooth module with PIC microcontrollers. And develop the necessary firmware in order to receive data from a Smartphone over the Bluetooth to control DC motors
- for this to work you'll need to 
    - open bluetooth settings on your pc
    - go to COM Ports
    - add incoming serial port (COM5 or anything but it must match with the HC-05 configuration)
    - install "serial bluetooth terminal" app form playstore on an android phone
    - open it and select the pc from devices tab
    - connect the phone to the PC using bluetooth 
    - Send "1" to reverse the motor
    - Send "2" to turn off the motor
    - Send "3" to set the motor at 33% power
    - Send "4" to set the motor at 67% power
    - Send "5" to set the motor at 100% power
#### Components   
- HC-05 Bluetooth Module
- DC Motor
- L293D motor driver
#### Configuration
-  Transmitter (HC-05)
    -  TXD as UART transmitter
-  Reciever (PIC16F877A)
    - RD0-1 as output for motor direction
    - RC2 CCP/PWM output pin (duty cycle)

### Lab_10_SPI_Communication

#### Purpose 
- Create a serial communication interface between 2 microcontrollers using SPI Protocol.
#### Components   
- 8 LEDs
- 3 Buttons
#### Configuration
-  Master
    -  RB0-2 as input for buttons
    -  RD0-3 as output LEDs
    -  SCK/RC3 output (clock)
    -  SDI/RC4 input (data)
    -  SDO/RC5 output (data)
-  Slave
    -  RB0-3 as output LEDs
    -  SCK/RC3 input(clock)
    -  SDI/RC4 input (data)
    -  SDO/RC5 output (data)
    -  RA5/SS line input (slave select attached to ground since when the SS pin is low, transmission and
reception are enabled)

### Lab_10.1_SPI_HC-05_Bluetooth_Controller

#### Purpose 
- This project uses the HC-05 Bluetooth module with PIC microcontrollers. And develop the necessary firmware in order to receive data from a Smartphone over the Bluetooth to control LEDs
- The Recieved data is then transmitted to the Slave device using SPI protocol
- for this to work you'll need to
    - open bluetooth settings on your pc
    - go to COM Ports
    - add incoming serial port (COM5 or anything but it must match with the HC-05 configuration)
    - install "serial bluetooth terminal" app form playstore on an android phone
    - open it and select the pc from devices tab
    - connect the phone to the PC using bluetooth 
    - Send "1" to Increment data
    - Send "2" to Decrement data
    - Send "3" to Send data through SPI transmission
#### Components   
- HC-05 Bluetooth Module
- 8 LEDs
#### Configuration
-  Master
    -  SCK/RC3 output (clock)
    -  SDI/RC4 input (data)
    -  SDO/RC5 output (data)
    -  RD0-3 as output LEDs
    -  RC7 UART reciever
    -  (HC-05) TXD as UART transmitter
-  Slave
    -  RB0-3 as output LEDs
    -  SCK/RC3 input(clock)
    -  SDI/RC4 input (data)
    -  SDO/RC5 output (data)
    -  RA5/SS line input (slave select attached to ground since when the SS pin is low, transmission and
reception are enabled)

### Lab_10.2_SPI_LCD_strings

#### Purpose 
- Create a serial communication interface between 2 microcontrollers using SPI Protocol.
- Use this protocol to transmit a string serially and display it on an Alphanumeric LCD 16×2 after recieving it on the slave device
#### Components   
- LCD
- 3 push buttons 
- 2 PIC M.Cs Master and a Slave
#### Configuration
-  Master
    -  SCK/RC3 output (clock)
    -  SDI/RC4 input (data)
    -  SDO/RC5 output (data)
    -  RB0 input (Button-String Define)
    -  RB2 input (Button-Send)
-  Slave
    -  SCK/RC3 input(clock)
    -  SDI/RC4 input (data)
    -  SDO/RC5 output (data)
    -  RA5/SS line input (slave select attached to ground since when the SS pin is low, transmission and reception are enabled)
    -  RC0 input (Button-Clear LCD)
    -  LCD 
       -  RB0-3 LCD Data pins
       -  RB5 LCD_RS
       -  RB4 LCD_EN 

### Lab_10.3_SPI_ Independent_Slave

#### Purpose 
- Create a serial communication interface between 3 microcontrollers (A master and two slaves) using SPI Protocol.
- Use this protocol to transmit a string serially and display it on an Alphanumeric LCD 16×2 after recieving it on the slave device
#### Components   
- 2 LCDs
- 6 push buttons 
- 3 PIC M.Cs (Master and two Slaves)
#### Configuration
-  Master
    -  SCK/RC3 output (clock)
    -  SDI/RC4 input (data)
    -  SDO/RC5 output (data)
    -  RD0/SS1 output (slave1 select)
    -  RD1/SS2 output (slave2 select)
    -  RB0 input (Button-String1)
    -  RB1 input (Button-String2)
    -  RB2 input (Button-Send1)
    -  RB3 input (Button-Send2)
-  Slave
    -  SCK/RC3 input(clock)
    -  SDI/RC4 input (data)
    -  SDO/RC5 output (data)
    -  RA5/SS line input (slave select attached to ground since when the SS pin is low, transmission and reception are enabled)
    -  RC0 input (Button-Clear LCD)
    -  LCD 
       -  RB0-3 LCD Data pins
       -  RB5 LCD_RS
       -  RB4 LCD_EN 

### Lab_11.0_ADC_LED_Dimmer

#### Purpose 
-  Configure The ADC Module and read analog signals.
-  Combine the analog readings from a potentiometer with PWM to control LED brightness.
#### Components   
- LED
- Battery, potentiometer 
#### Configuration
- RA0/AN0 as the analog channel input
- RC2/CCP1 as PWM output pin (duty cycle)

### Lab_11.1_LM35_Temperature_Sensor_Interfacing

#### Purpose 
-  Configure The ADC Module and read analog signals. 
-  Interface The LM35 Temperature Sensor and print out the result to the serial monitor on your computer.
#### Components   
- LM35
- Virtual Terminal (UART Reciever)
#### Configuration
- RA3/AN3 as the analog channel input
- RC6/TX as the UART transmitter

### Lab_11.2_LM35_Temperature_Sensor_Interfacing_LCD

#### Purpose 
-  Configure The ADC Module and read analog signals. 
-  Interface The LM35 Temperature Sensor and print out the result to the 16*2 LCD Monitor.
#### Components   
- LM35
- LCD
#### Configuration
- RA3/AN3 as the analog channel input
- RB0-5 as output LCD

### Lab_12.0_DAC_R-2R ladder

#### Purpose 
-  Configure The ADC Module and read analog signals.
-  Transfer the digital output of the 10-bit ADC to the input of an 8-bit DAC to reconstruct the analog signal again
#### Components   
- Battery, potentiometer 
- R-2R resistor ladder  
#### Configuration
- RA3/AN3 as the analog channel input
- PORTB as the ADC digital output 


### Lab_12.1_DAC_R-2R ladder_Wave_Generation

#### Purpose 
-  Create an 8-bit digital  sinewave.
-  Transfer the digital 8-bit sinewave to the input of an 8-bit DAC to construct analog signal
#### Components   
- R-2R resistor ladder  
#### Configuration
- PORTB as the ADC digital output 

### Lab_12.2_Sawtooth_Out_DAC

#### Purpose 
-  Create an 8-bit digital sawtooth signal.
-  Transfer the digital 8-bit sawtooth to the input of an 8-bit DAC to construct analog signal
-  Control the frequency (10Hz) using Timer1 module
#### Components   
- R-2R resistor ladder  
#### Configuration
- PORTB as the ADC digital output 


### Lab_12.3_Triangular_Waveform_Out_DAC

#### Purpose 
-  Create an 8-bit digital Triangular signal.
-  Transfer the digital 8-bit sawtooth to the input of an 8-bit DAC to construct analog signal
-  Control the frequency (10Hz) using Timer1 module
#### Components   
- R-2R resistor ladder  
#### Configuration
- PORTB as the ADC digital output 

### Lab_12.4_Sine_Waveform_Out_DAC

#### Purpose 
-  Create an 8-bit digital Sinewave signal.
-  Transfer the digital 8-bit Sinewave to the input of an 8-bit DAC to construct analog signal
-  Control the frequency (10Hz) using Timer1 module
#### Components   
- R-2R resistor ladder  
#### Configuration
- PORTB as the ADC digital output 

### Lab_12.5_Piano_DDS_DAC

#### Purpose 
-  Generate Sinewave using look-up table
-  Implement the DDS [direct digital synthesis] algorithm to control the frequency of the generated sinewave and generate music notes
#### Components   
- R-2R resistor ladder 
- Speaker 
#### Configuration
- PORTB as the ADC digital output 
- PORTA as input for buttons

### Lab_13.0_LCD_4-Bit_Interface

#### Purpose 
-  Interface the LCD 16×2 module with a microcontroller and write text to it starting at a specific position and move it back and forth to screen edges.
#### Components   
- LCD
#### Configuration
-  RB0-3 LCD Data pins
-  RB5 LCD_RS
-  RB4 LCD_EN 

### Lab_14.0_I2C_Communication

#### Purpose 
- Create a serial communication interface between 2 microcontrollers using I2C Protocol.
#### Components   
- 9 LEDs
#### Configuration
-  Master
    -  RC5 as output LED
    -  SCL/RC3 input (serial clock line)
    -  SDI/RC4 input (seial data line)
    -  SDO/RC5 output (data)
-  Slave
    -  RD0-7 as output LEDs
    -  SCL/RC3 input (serial clock line)
    -  SDI/RC4 input (seial data line)
