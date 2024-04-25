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
