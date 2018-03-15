/*
Made by DOE Brian Leung - Class of 2018

Made for Teensy++ 2.0 and (will post board layout)

For the future, if you guys ever want a pretty lit bot :(
*/

#include <Wire.h>
#include <FastLED.h>

#define FPS 60

#define ULPIN 7
#define ULLEDCOUNT 8
CRGB ULleds[ULLEDCOUNT];
int ULpat
int ULhold

#define LLPIN 5
#define LLLEDCOUNT 8
CRGB LLleds[LLLEDCOUNT];
int LLpat
int LLhold

#define SELF_ADDRESS 98

void setup()
{
  pinMode(6,OUTPUT);
  Wire.begin(SELF_ADDRESS);
  Wire.onReceive(recvEvent);
  Serial.begin(9600);
  Serial.println(F("BMK2: Initialized :)"));
  FastLED.addLeds<WS2812,ULPIN,GRB>(ULleds,ULLEDCOUNT);
  FastLED.addLeds<WS2812,LLPIN,GRB>(LLleds,LLLEDCOUNT);
}

void loop()
{
  updateFrame(ULpat,LLpat);
  delay(1000/FPS);
} 

void recvEvent(int numBytes)
{
  if (Wire.available())
  {
     Serial.print(numBytes);Serial.println(" bytes available");
  }
}

void allSet(int R, int G, int B, int strip)
{
  if (strip)
  {
    for (int index = 0; index<LLLEDCOUNT; index++)
    {
      LLleds[index] = CRGB(R,G,B);
    }
  }
  else
  {
    for (int index = 0; index<ULLEDCOUNT; index++)
    {
      ULleds[index] = CRGB(R,G,B);
    }
  }
  FastLED.show();
}