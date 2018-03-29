#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Master Initialized.");
}

void loop() {
	if (Serial.available())
	{
		byte ch = Serial.read();
		Wire.beginTransmission(95); // transmit to device #8       
		Wire.write(ch);              // sends one byte
		Wire.endTransmission();   
	}
}
