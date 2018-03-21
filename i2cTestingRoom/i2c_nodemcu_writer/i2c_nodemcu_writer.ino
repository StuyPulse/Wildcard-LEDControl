#include <Wire.h>

void setup() {
  Wire.begin(D1,D2);
  Serial.begin(9600);
  Serial.println("Master Initialized.");
}

void loop() {
	if (Serial.available())
	{
		byte ch = Serial.read();
    Serial.print(ch);Serial.println(" sending");
		Wire.beginTransmission(95); // transmit to device #8       
		Wire.write(ch);              // sends one byte
		Wire.endTransmission();   
	}
}
