#include <Wire.h>
#include <FastLED.h>
#define LED_COUNT 10
#define LED_PIN 7
#define SELF_ADDRESS 10
#define sensePin 12

const int addrs[] = {65,67,69,71,73,75};
bool blueAlliance = false;
int patternID = 0;

//Instance LED Strip LED array.
CRGB leds[LED_COUNT];

void setup() {
  pinMode(sensePin,INPUT);
  Wire.begin(SELF_ADDRESS);
  Wire.onReceive(onRecv);
  Serial.begin(9600);
  Serial.println(F("UL blinky mk1: initialized."));
  if (analogRead(sensePin) > 750)
  {
    blueAlliance = true;
  }
  FastLED.addLeds<WS2812,LED_PIN,GRB>(leds,LED_COUNT);
}

void loop() {

}

void onRecv(int howMany)
{
  if (Wire.available())
  {
    patternID = Wire.read();
    switch(patternID)
    {
      case SELF_ADDRESS:
        Serial.println(F("UL blinky mk1: address received."));
        patternID = Wire.read();       
      case 65:
        allSet(0,0,0);        
        break;
      case 67:
        if (blueAlliance)
        {
          bluePulse();
        }
        else
        {
          redPulse();
        }
        break;
      case 69:
        greenPulse();
        break;
      case 71:
        allSet(0,220,0);
        break;
      case 73:
        tripleFlash();
        break;
      case 75:
        makeItRain();
        break;
      default:
        allSet(240,0,240);
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
    for (int i = 254; i>0; i--)
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
    for (int i = 254; i>0; i--)
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
    for (int i = 254; i>0; i--)
    {
      allSet(i,0,0);
      FastLED.show();
      delay(20);
    }
  }
}
void bluePulse()
{
  while (patternID == 67)
  {  
    for (int i = 0; i<254; i++)
    {
      allSet(0,0,i);
      FastLED.show();
      delay(20);
    }
    for (int i = 254; i>0; i--)
    {
      allSet(0,0,i);
      FastLED.show();
      delay(20);
    }
  }
}
void greenPulse()
{
  while (patternID == 69)
  {  
    for (int i = 0; i<254; i++)
    {
      allSet(0,0,i);
      FastLED.show();
      delay(20);
    }
    for (int i = 254; i>0; i--)
    {
      allSet(0,0,i);
      FastLED.show();
      delay(20);
    }
  }
}

void tripleFlash()
{
  byte Rval = 254;
  byte Bval = 0;
  if (blueAlliance)
  {
    Rval = 0;
    Bval = 254;
  }
  for (int i = 0; i<3; i++)
  {
    allSet(Rval,0,Bval);
    FastLED.show();
    delay(200);
    allSet(0,0,0);
    FastLED.show();
    delay(200);
  }
  patternID = 67;
  if (blueAlliance)
  {
    bluePulse();
  }
  else
  {
    redPulse();
  }
}

void makeItRain()
{
  //RAINBOW
  //WILL HAVE TO LOOK UP  
}