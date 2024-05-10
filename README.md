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
-  RB0-3 as input for buttons
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
- 3 Buttons
#### Configuration
-  Transmitter
    -  RB0 & RB2 as input for buttons
    -  RC6 as UART transmitter
-  Reciever
    -  RB0-5 as output LCD
    -  RC0 as input for a button
    -  RC7 UART reciever

### Lab_9.2_UART_HC-05_Bluetooth_Controller

#### Purpose 
- This project uses the HC-05 Bluetooth module with PIC microcontrollers. And develop the necessary firmware in order to receive data from a Smartphone over the Bluetooth to control embedded systems, RC robots, LEDs or whatever.\
- for this to work you'll need to 
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
-  Transmitter(HC-05)
    -  TXD as UART transmitter
-  Reciever
    -  RB0-1 as output LEDs
    -  RC7 UART reciever
