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

typedef void (*patternList[])();
patternList actives = {allSet,};

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
     byte temp = 0;
     temp = Wire.read();
     if (temp == SELF_ADDRESS)
     {
      Serial.print("Address Received: ");Serial.println(temp);
      temp = Wire.read();
     }
     if (temp<65 || temp>126)
     {
      Serial.print("Invalid value received: ");Serial.println(temp);
      return;
     }
     actives[temp-65]();
  }
}

void updateFrame(int UL, int LL)
{
  
}

void allSet(int R, int G, int B, int strip)
{
  if (strip)
  {
    fill_solid(LLleds,LLLEDCOUNT,CRGB(R,G,B));
  }
  else
  {
    fill_solid(ULleds,ULLEDCOUNT,CRGB(R,G,B));
  }
  FastLED.show();
}