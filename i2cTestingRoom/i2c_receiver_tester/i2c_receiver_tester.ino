#include <Wire.h>
#define SELF_ADDRESS 98
void setup()
{
  Wire.begin(SELF_ADDRESS);
  Wire.onReceive(onRecv);
  Serial.begin(9600);
  Serial.println("Tester Initialized");
}

void loop()
{
}

void onRecv(int howMany)
{
  if (Wire.available())
  {
    byte recv = (byte) Wire.read();
    Serial.println(recv);
  }
}
