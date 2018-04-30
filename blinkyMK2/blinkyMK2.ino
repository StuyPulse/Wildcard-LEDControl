/*
Made by DOE Brian Leung - Class of 2018

Made for Teensy++ 2.0

For the future, if you guys ever want a pretty lit bot :(

Youre gonna need the Patterns.h file.
*/
#include "Patterns.h"
int statusPin = 6;
boolean stat = true;

//Lists of pattern functions here, makes it slightly easier to add new patterns.
patternList ULactives = {ULOff,ULSolidA,ULPulse,ULRainbow,ULPopo,ULSolidG};
patternList LLactives = {LLOff,LLSolidA,LLPulse,LLRainbow,LLPopo,LLSolidG,LLSolidY,LLSolidHP,LLStrobeB,LLSolidW};
byte ULactivesLen = 6;
byte LLactivesLen = 10;

//For timing
unsigned long prevMillis = 0;
byte blinkFrame = 0;

//For tracking pattern numbers
int ULpat = 0;
int LLpat = 0;


void setup()
{
  pinMode(statusPin,OUTPUT);
  digitalWrite(statusPin,HIGH);
  Wire.begin(SELF_ADDRESS);
  Wire.onReceive(recvEvent);
  FastLED.addLeds<WS2812,ULPIN,GRB>(ULleds,ULLEDCOUNT);
  FastLED.addLeds<WS2812,LLPIN,GRB>(LLleds,LLLEDCOUNT);
  Serial.begin(9600);
  Serial.println(F("BMK2: Initialized, accepting fan mail"));
  Serial.print(F("BMK2: Start up time (ms): "));Serial.println(millis());
  prevMillis = millis();
}

//You can modify frameLife in the header by modifying FPS.
void loop()
{
  if (millis() - prevMillis >= frameLife)
  {
    //Update the board with a new pattern/frame
    if (blinkFrame < 40)
    {
      blinkFrame+=1;
    }
    else
    {
      blinkFrame = 0;
      digitalWrite(statusPin,!stat);
      stat = !stat;
    }
    prevMillis = millis();
    ULactives[ULpat]();
    LLactives[LLpat]();
    FastLED.show();
  }
}

//Lowercase characters will control the liftlighting: "a" for ULactives[0], "b" for ULactives[1], etc.
//Uppercase characters will control the underlighting.

//Will trim address bytes from the roborio.

void recvEvent(int numBytes)
{
  if (Wire.available())
  { 
     ULOff();
     LLOff();
     Serial.print(F("Bytes available: "));Serial.println(numBytes);
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
//        blue = false;
        Serial.println(F("RED ALLIANCE."));
      }
      if (temp == 64)
      {
        blue = true;
        Serial.println(F("BLUE ALLIANCE."));
      }
     }
     if (temp>64 && temp<91)
     {
      ULpat = temp-65;
      if (ULpat > ULactivesLen)
      {
        ULpat = 0;
      }
      Serial.print(F("UL Pattern: "));Serial.println(ULpat);
     }
     if (temp>96)
     {
      LLpat = temp-97;
      if (LLpat > LLactivesLen)
      {
        LLpat = 0;
      }
      Serial.print(F("LL Pattern: "));Serial.println(LLpat);
     }
     return;
  }
}
