#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Master Initialized.");
}

void loop() {
    Serial.println("Written");
		Wire.beginTransmission(8); // transmit to device #8       
		Wire.write("A");              // sends one byte
		Wire.endTransmission();   
    delay(500);
    Wire.beginTransmission(8); // transmit to device #8       
    Wire.write("B");              // sends one byte
    Wire.endTransmission();  
    delay(500);
}
