/*
Made by DOE Brian Leung - Class of 2018

Made for Teensy++ 2.0 and (will post board layout)

For the future, if you guys ever want a pretty lit bot :(
*/

#include <Wire.h>
#include <FastLED.h>

#define FPS 60
typedef void (*patternList[])();

#define ULPIN 7
#define ULLEDCOUNT 8
CRGB ULleds[ULLEDCOUNT];
int ULpat = -1;
int ULhold;
patternList ULactives = {ULOff,ULSolidAli};


#define LLPIN 5
#define LLLEDCOUNT 8
CRGB LLleds[LLLEDCOUNT];
int LLpat = -1;
int LLhold;
patternList LLactives = {LLOff,LLSolidAli};

#define SELF_ADDRESS 98

bool blue = false;


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
  updateUL(ULpat);
  updateLL(LLpat);
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
     if (temp<58 || temp>123)
     {
      Serial.print("Invalid value received: ");Serial.println(temp);
      return;
     }
     if (temp<65)
     {
      Serial.print("Non value received: ");Serial.println(temp);
      if (temp == 63)
      {
        blue = !blue;
        Serial.println("Alliance switched.");
      }
     }
     if (temp>64 && temp<91)
     {
      ULpat = temp-65;
      Serial.print("UL Pattern: ");Serial.println(ULpat);
     }
     if (temp>96)
     {
      LLpat = temp-97;
      Serial.print("LL Pattern: ");Serial.println(LLpat);
     }
     return;
  }
}

void updateUL(pat)
{
  if (pat == -1)
  {
    return;
  }
  else
  {
    ULactives[pat]();
  }
}

void updateLL(pat)
{
  if (pat == -1)
  {
    return;
  }
  else
  {
    LLactives[pats]();
  }
}

void ULPulse()
{
}
void LLPulse()
{ 
}

//Solid
void ULSolidAli()
{
  if (blue)
  {
    allSet(0,0,230,0);
  }
  else
  {
    allSet(230,0,0,0);
  }
}
void LLSolidAli()
{
  if (blue)
  {
    allSet(0,0,230,1);
  }
  else
  {
    allSet(230,0,0,1);
  }
}

//Off 
void ULOff()
{
  allSet(0,0,0,0);
}
void LLOff()
{
  allSet(0,0,0,1);
}

//Helper functions
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

