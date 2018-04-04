/*
Made by DOE Brian Leung - Class of 2018

Made for Teensy++ 2.0

For the future, if you guys ever want a pretty lit bot :(

Youre gonna need the blinkyMK2.ino file.
*/
#include <FastLED.h>
#include <Wire.h>

#define FPS 60

//AVOID EDITING THESE
#define SELF_ADDRESS 95
#define ULPIN 7
#define ULLEDCOUNT 8
#define LLPIN 5
#define LLLEDCOUNT 12
#define frameLife 1000/FPS

typedef void (*patternList[])();


CRGB ULleds[ULLEDCOUNT];
int ULhold = -1;

CRGB LLleds[LLLEDCOUNT];
int LLhold = -1;

bool blue = false;

//First Helper
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

//Display alliance color
void ULSolidA()
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
void LLSolidA()
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
//Green
void ULSolidG()
{
  allSet(13,200,13,0);
}
void LLSolidG()
{
  allSet(13,200,13,1);
}

//Hot Pink
void LLSolidHP()
{
  allSet(255,20,147,1);
}
//Yellow
void LLSolidY()
{
  allSet(255,255,0,1);
}
//White
void LLSolidW()
{
  allSet(255,255,255,1);
}
//Strobe Popo
void LLStrobeB()
{
  if (LLhold <= 4)
  {
    LLhold+=1;
    return;
  }
  else
  {
    if (LLleds[0].blue == 0)
    {
      allSet(0,0,240,1);
    }
    else
    {
      allSet(240,0,0,1);
    }
    LLhold = -1;
  }
}

//Pulse
void ULPulse()
{
if (blue)
{
    if (ULhold == -1)
    {
      allSet(0,0,ULleds[0].blue+3,0);
      if (ULleds[0].blue >= 230)
      {
        ULhold = 1;
      }
    }
    else
    {
      allSet(0,0,ULleds[0].blue-3,0);
      if (ULleds[0].blue <= 10)
      {
        ULhold = -1;
      }
    }
  }
  else
  {
    if (ULhold == -1)
    {
      allSet(ULleds[0].red+3,0,0,0);
      if (ULleds[0].red >= 230)
      {
        ULhold = 1;
      }
    }
    else
    {
      allSet(ULleds[0].red-3,0,0,0);
      if (ULleds[0].red <= 10)
      {
        ULhold = -1;
      }
    }
  }
}
void LLPulse()
{
  if (blue)
  {
    if (LLhold == -1)
    {
      allSet(0,0,LLleds[0].blue+3,1);
      if (LLleds[0].blue >= 230)
      {
        LLhold = 1;
      }
    }
    else
    {
      allSet(0,0,LLleds[0].blue-3,1);
      if (LLleds[0].blue <= 10)
      {
        LLhold = -1;
      }
    }
  }
  else
  {
    if (LLhold == -1)
    {
      allSet(LLleds[0].red+3,0,0,1);
      if (LLleds[0].red >= 230)
      {
        LLhold = 1;
      }
    }
    else
    {
      allSet(LLleds[0].red-3,0,0,1);
      if (LLleds[0].red <= 10)
      {
        LLhold = -1;
      }
    }
  } 
}

//Rainbow scroll
void ULRainbow()
{
  fill_rainbow(ULleds,ULLEDCOUNT,0,10);
}
void LLRainbow()
{
  fill_rainbow(LLleds,LLLEDCOUNT,0,10);
}

//woop woop 
void ULPopo()
{
  if (ULhold <= 12)
  {
    ULhold+=1;
    return;
  }
  else
  {
    for (int i = 0; i<ULLEDCOUNT/2; i++)
    {
      if (ULleds[i].red == 239)
      {
        ULleds[i] = CRGB(0,0,239);
      }
      else
      {
        ULleds[i] = CRGB(239,0,0);
      }
    }
    for (int i = ULLEDCOUNT/2; i<ULLEDCOUNT; i++)
    {
      if (ULleds[i].blue == 239)
      {
        ULleds[i] = CRGB(239,0,0);
      }
      else
      {
        ULleds[i] = CRGB(0,0,239);
      }
    }
    ULhold = -1;
  }

}
void LLPopo()
{
  if (LLhold <= 12)
  {
    LLhold+=1;
    return;
  }
  else
  {
    for (int i = 0; i<LLLEDCOUNT/2; i++)
    {
      if (LLleds[i].red == 239)
      {
        LLleds[i] = CRGB(0,0,239);
      }
      else
      {
        LLleds[i] = CRGB(239,0,0);
      }
    }
    for (int i = LLLEDCOUNT/2; i<LLLEDCOUNT; i++)
    {
      if (LLleds[i].blue == 239)
      {
        LLleds[i] = CRGB(239,0,0);
      }
      else
      {
        LLleds[i] = CRGB(0,0,239);
      }
    }
    LLhold = -1;
  }
}
