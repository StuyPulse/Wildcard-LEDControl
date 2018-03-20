#include <Wire.h>
#include <FastLED.h>
#include <MemoryFree.h>
#define LEDcount 10
#define LED_PIN 7
#define SELF_ADDRESS 10
CRGB leds[LEDcount];
volatile int PatternStyle;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(SELF_ADDRESS);
  Wire.onReceive(recvEvent);
  Serial.begin(9600);
  Serial.println(F("Initialized"));
  FastLED.addLeds<WS2812,LED_PIN,GRB>(leds,LEDcount);
  Serial.print(F("INIT: Memory free: "));
  Serial.println(freeMemory());
}

void loop() {
  // put your main code here, to run repeatedly:
}

void recvEvent(int howMany)
{
  if (Wire.available())
  {
    PatternStyle = Wire.read();
    if (PatternStyle == SELF_ADDRESS)
    {
      Serial.println(F("Address received"));
      PatternStyle = Wire.read();
    }
    Serial.print(F("BEGIN: Memory free: "));
    Serial.println(freeMemory());

    if (PatternStyle==65)
    {
      allRed();
      //Serial.println(F("Turned on"));
    }
    if (PatternStyle==66)
    {
      allOff();
      //Serial.println(F("Turned off"));
    }
    if (PatternStyle == 68)
    {
      blinkRed();
      Serial.println(F("Finished"));
    }
    Serial.print(F("\nPattern Style: "));
    Serial.print(PatternStyle);
    Serial.print("\n");
    Serial.print(F("END: Memory free: "));
    Serial.println(freeMemory());
  }
}

void allRed()
{
  for (int i = 0; i<LEDcount; i++)
  {
    leds[i] = CRGB(127,0,0);
  }
  FastLED.show();
  Serial.print(F("ON: Memory free: "));
  Serial.println(freeMemory());

}
void blinkRed()
{
  while (PatternStyle == 68)
  {
    for (int i = 0; i<LEDcount; i++)
    {
      leds[i] = CRGB(127,0,0);
    }
    FastLED.show();
    delay(1000);
    
    for (int i = 0; i<LEDcount; i++)
    {
      leds[i] = CRGB(0,0,0);
    }
    FastLED.show();
    delay(1000);
    Serial.print(F("LOOP: Memory free: "));
    Serial.println(freeMemory());

  }
}
void allOff()
{
  for (int i = 0; i<LEDcount; i++)
  {
    leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
  Serial.print(F("OFF: Memory free: "));
  Serial.println(freeMemory());

}
