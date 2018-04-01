#include <FastLED.h>
#include <Wire.h>

#define SELF_ADDRESS 95
#define FPS 60
#define ULPIN 7
#define ULLEDCOUNT 8
#define LLPIN 5
#define LLLEDCOUNT 7

int const frameLife = 1000/FPS;
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

//Pulse
void ULPulse()
{
if (blue)
  {
    if (ULhold == -1)
    {
      if (ULleds[0].blue >= 230)
      {
        ULhold = 1;
      }
      allSet(0,0,ULleds[0].blue+5,0);
    }
    else
    {
      if (ULleds[0].blue <= 10)
      {
        ULhold = -1;
      }
      allSet(0,0,ULleds[0].blue-5,0);
    }
  }
  else
  {
    if (ULhold == -1)
    {
      if (ULleds[0].red >= 230)
      {
        ULhold = 1;
      }
      allSet(ULleds[0].red+5,0,0,0);
    }
    else
    {
      if (ULleds[0].red <= 10)
      {
        ULhold = -1;
      }
      allSet(ULleds[0].red-5,0,0,0);
    }
  }}
void LLPulse()
{
  if (blue)
  {
    if (LLhold == -1)
    {
      if (LLleds[0].blue >= 230)
      {
        LLhold = 1;
      }
      allSet(0,0,LLleds[0].blue+5,1);
    }
    else
    {
      if (LLleds[0].blue <= 10)
      {
        LLhold = -1;
      }
      allSet(0,0,LLleds[0].blue-5,1);
    }
  }
  else
  {
    if (LLhold == -1)
    {
      if (LLleds[0].red >= 230)
      {
        LLhold = 1;
      }
      allSet(LLleds[0].red+5,0,0,1);
    }
    else
    {
      if (LLleds[0].red <= 10)
      {
        LLhold = -1;
      }
      allSet(LLleds[0].red-5,0,0,1);
    }
  } 
}

//Rainbow
void ULRainbow()
{
  fill_rainbow(ULleds,ULLEDCOUNT,0,10);
}
void LLRainbow()
{
  fill_rainbow(LLleds,LLLEDCOUNT,0,10);
}