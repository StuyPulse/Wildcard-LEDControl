#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  //Wire.onReceive(recvEvent);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    Wire.beginTransmission(69); // transmit to device #8       // sends five bytes
    Wire.write(5);              // sends one byte
    Wire.endTransmission();   
    delay(500);   
 
}
