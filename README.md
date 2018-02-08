# crispy-barnacle-LEDControl
Brian's house of LED development, code that will be run on the Arduinos to control the lighting on our 2018 robot.

## Required Libraries:
- FastLED.h - lib for controlling WS2812B LEDs
- Wire.h - for i2c

## Required Hardware:
- WS2812B LED Strip
- Arduinos

### Hardware Hookup Info:

## Description of Files:

### LED_Control_simple_patterns.ino:
Just 2 functions with LED subroutines.

### i2c_Serial_Write_Master.ino:
A master device that will write a single byte to a slave device. You can choose the byte via serial monitor/console.

### i2c_LED_Control_Slave.ino:
The very first prototype of the code for the slave device controlled by the roborio. Will output a WS2812 pattern according to data sent from the Roborio via i2c.



