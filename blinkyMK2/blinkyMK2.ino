/*
Made by DOE Brian Leung - Class of 2018

Made for Teensy++ 2.0

For the future, if you guys ever want a pretty lit bot :(
*/
#include "Patterns.h"

patternList ULactives = {ULOff,ULSolidA,ULPulse,ULRainbow};
patternList LLactives = {LLOff,LLSolidA,LLPulse,LLRainbow};

unsigned long prevMillis = 0;
int ULpat = -1;
int LLpat = -1;


void setup()
{
  pinMode(6,OUTPUT);
  digitalWrite(6,HIGH);
  Wire.begin(SELF_ADDRESS);
  Wire.onReceive(recvEvent);
  FastLED.addLeds<WS2812,ULPIN,GRB>(ULleds,ULLEDCOUNT);
  FastLED.addLeds<WS2812,LLPIN,GRB>(LLleds,LLLEDCOUNT);
  Serial.begin(9600);
  Serial.println(F("BMK2: Initialized, accepting fan mail"));
  Serial.print(F("Start up time: "));Serial.println(millis());
  prevMillis = millis();
}


void loop()
{
  if (millis() - prevMillis >= frameLife)
  {
    prevMillis = millis();
    updateUL(ULpat);
    updateLL(LLpat);
    FastLED.show();
  }
}

void recvEvent(int numBytes)
{
  if (Wire.available())
  {
     Serial.print(numBytes);Serial.println(F(" bytes available"));
     byte temp = 0;
     temp = Wire.read();
     if (temp == SELF_ADDRESS)
     {
      Serial.print(F("Address received: "));Serial.println(temp);
      temp = Wire.read();
     }
     if (temp<58 || temp>123)
     {
      Serial.print(F("!Invalid value received!: "));Serial.println(temp);
      return;
     }
     if (temp<65)
     {
      Serial.print(F("Non pattern value received: "));Serial.println(temp);
      if (temp == 63)
      {
        ULOff();
        LLOff();
        blue = !blue;
        Serial.println(F("Alliance switched."));
      }
     }
     if (temp>64 && temp<91)
     {
      ULpat = temp-65;
      Serial.print(F("UL Pattern: "));Serial.println(ULpat);
     }
     if (temp>96)
     {
      LLpat = temp-97;
      Serial.print(F("LL Pattern: "));Serial.println(LLpat);
     }
     return;
  }
}

//Update the board with a new pattern/frame
void updateUL(int pat)
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

void updateLL(int pat)
{
  if (pat == -1)
  {
    return;
  }
  else
  {
    LLactives[pat]();
  }
}