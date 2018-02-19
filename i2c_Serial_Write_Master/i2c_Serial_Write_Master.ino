#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Master Initialized.");
}

void loop() {
    Serial.println("Written");
    Wire.beginTransmission(10); // transmit to device #8       
    Wire.write('A');              // sends one byte
    Wire.endTransmission();   
    delay(1000);
    Wire.beginTransmission(10); // transmit to device #8       
    Wire.write('C');              // sends one byte
    Wire.endTransmission();  
    delay(1000);
    Wire.beginTransmission(10); // transmit to device #8       
    Wire.write('E');              // sends one byte
    Wire.endTransmission();  
    delay(1000);

}
