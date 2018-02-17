#include <Wire.h>
#include <FastLED.h>
#define LED_COUNT 10
#define LED_PIN 7
#define SELF_ADDRESS 10
#define sensePin 12

int addrs = {65,67,69,71,73,75};
bool blueAlliance = false;
int patternID = 0;

//Instance LED Strip LED array.
CRGB leds[LED_COUNT];

void setup() {
  Wire.begin(SELF_ADDRESS);
  Wire.onReceive(onRecv);
  Serial.begin(9600);
  Serial.println(F("UL blinky mk1: initialized."));
  FastLED.addLeds<WS2812,LED_PIN,GRB>(leds,LED_COUNT);
}

void loop() {

}

void onRecv(int howMany)
{
  if (Wire.available())
  {
    patternID = Wire.read();
    if (patternID == SELF_ADDRESS)
    {
      Serial.println(F("UL blinky mk1: address received."))
      patternID = Wire.read();
    }
    if (patternID == addrs[0])
    {
      allSet(0,0,0);
    }
    if (patternID == addrs[1])
    {
      if (blueAlliance)
      {
        bluePulse();
      }
      else
      {
        redPulse();
      }
    }
    if (patternID == addrs[2])
    {
      greenPulse();
    }
    if (patternID == addrs[3])
    {
      allSet(0,220,0);
    }
    if (patternID == addrs[4])
    {
      tripleFlash();
    }
    if (patternID == addrs[5])
    {
      makeItRain();
    }
  }
}

//LED helper functions
void allSet(int R,int G,int B)
{
  for (int ledIndex = 0; ledIndex<LED_COUNT; ledIndex++)
  {
    leds[ledIndex] = CRGB(R,G,B);
  }
  FastLED.show();
}
void redBreathe()
{ 
  while (patternID == 0)  
    for (int i = 0; i<254; i++)
    {
      allSet(i,0,0);
      FastLED.show();
      delay(30);
    }
    for (int i = 0; i<254; i--)
    {
      allSet(i,0,0);
      FastLED.show();
      delay(40);
    }
    delay(1500);
}
void blueBreathe()
{
  while (patternID == 0)  
  {
    for (int i = 0; i<254; i++)
    {
      allSet(0,0,i);
      FastLED.show();
      delay(30);
    }
    for (int i = 0; i<254; i--)
    {
      allSet(0,0,i);
      FastLED.show();
      delay(40);
    }
    delay(1500);
  }
}

//i2c LED helper functions

//Pulse
void redPulse()
{
  while (patternID == 67)
  {  
    for (int i = 0; i<254; i++)
    {
      allSet(i,0,0);
      FastLED.show();
      delay(20);
    }
    for (int i = 0; i<254; i--)
    {
      allSet(i,0,0);
      FastLED.show();
      delay(20);
    }
  }
}
void bluePulse()
{

}
void greenPulse()
{
  
}

void tripleFlash()
{
}

void makeItRain()
{
}