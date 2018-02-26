#include <Wire.h>
#include <FastLED.h>

#define ULPIN
#define ULLEDCOUNT

#define LLPIN 
#define LLLEDCOUNT

#define SELF_ADDRESS

CRGB LLleds[LLLEDCOUNT];
CRGB ULleds[ULLEDCOUNT];
int patternID;

void setup()
{
  Wire.begin(SELF_ADDRESS);
  Wire.onReceive(recvEvent);
  Serial.begin(9600);
  Serial.println(F("BMK2: Initialized :)"));
  
}
void loop()
{
  
}

void recvEvent(int numBytes)
{

}