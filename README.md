# crispy-barnacle-LEDControl
Brian's house of LED development, code that will be run on the Arduinos to control the lighting on our 2018 robot. 

## Required Libraries:
- FastLED.h - lib for controlling WS2812B LEDs
- Wire.h - for i2c

## Required Hardware:
- WS2812B LED Strip
- Arduinos
- 5V power source

### Hardware Hookup Info:
5V power through 5V pin

:warning: Caution: Use power source with sufficient amperage. :warning:

Data through center LED strip pin - see code for proper pin on Arduino

## Description of Files:

### LED_Control_simple_patterns.ino:
Just 2 functions with LED subroutines in them. - Credits to Anna Li

### i2c_Serial_Write_Master.ino:
A master device that will write a single byte to a slave device. You can choose the byte via serial monitor/console. Please be aware that pressing the key on the keyboard will send the byte.

### i2c_LED_Control_Slave.ino:
The very first prototype of the code for the slave device controlled by the roborio. Will output a WS2812 pattern according to data sent from the Roborio via i2c. Will also print the LED Pattern ID if connected to the Arduino via serial.

Good luck with your lighting!



<b>Electronics<sup>TM</sup></b>
