# Wildcard-LEDControl
Brian's house of LED development, code that will be run on the Arduinos to control the lighting on our 2018 robot. 


<b>Post season thoughts (4/30/18): Brian:</b> While the animation portion is pretty, the overall project is buggy. It was fun though. Perhaps this can be perfected by future generations. 

Hypotheses of Failure/Bugginess:
- The teensy's i2c was hanging occasionally due to no pullup resistor between signal and power?
- The radio interference coming from the motors caused weird signals to run through the signal line, causing it to hang?

Possible Solutions:
- Utilize the MCP2515 CAN Module for better signal reliability no single use of i2c.

## Required Libraries:
- FastLED.h - lib for controlling WS2812B LEDs
- Wire.h - for i2c

## Required Hardware:
- WS2812B LED Strip
- Arduinos/teensy
- 5V power source

### Hardware Hookup Info:
5V power through 5V pin

:warning: Caution: Use power source with sufficient amperage. :warning:

Data through center LED strip pin - see code for proper pin on Arduino

#### blinkyMK2:
See layout: 
White wire - SDA

Red wire - SCL

Black wire - GND


Port closest to power terminal - for Underlighting

Other 2 ports - for Liftlighting

## Description of Files:

### blinkyMK1 
The code for blinkyMK1, only controls the underlighting. Not recommended, does not use "state machine"/"FPS" control style

### blinkyMK2
The code for blinkyMK2. Controls lift lighting. Can control underlighting, but it was never used. Version used for WildCard

### blinkyMK3 - UNFINISHED
The code for blinkyMK3, possible implementation of MCP2515

### __TestingRoom:
Some unfinished ideas or testing things. Take a look if you dare.

### LED_Control_simple_patterns.ino:
Just 2 functions with LED subroutines in them. - Credits to Anna Li

### LED_Control_complex_patterns.ino:
LED subroutines with more complex patterns. - also credits to Anna Li

### i2c_Serial_Write_Master.ino:
A master device that will write a single byte to a slave device. You can choose the byte via serial monitor/console. Please be aware that pressing the key on the keyboard will send the byte.

### i2c_LED_Control_Slave.ino:
The very first prototype of the code for the slave device controlled by the roborio. Will output a WS2812 pattern according to data sent from the Roborio via i2c. Will also print the LED Pattern ID if connected to the Arduino via serial.

### i2c_LED_Control_Slave_MemoryHappy.ino:
Essentially i2c_LED_Control_Slave.ino but uses the MemoryFree.h library. It is just to fully verify that there will be no memory problems.

...Will possibly repurpose for Arduino Nano...

Good luck with your lighting!





<b>Electronics<sup>TM</sup></b>
