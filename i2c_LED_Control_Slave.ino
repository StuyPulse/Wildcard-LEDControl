#include <Wire.h>
#include <FastLED.h>
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
  Serial.println("Initialized");
  FastLED.addLeds<WS2812,LED_PIN,GRB>(leds,LEDcount);
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
      Serial.println("Address received");
      PatternStyle = Wire.read();
    }
    if (PatternStyle==65)
    {
      allRed();
      Serial.println("Turned on");
    }
    if (PatternStyle==66)
    {
      allOff();
      Serial.println("Turned off");
    }
    if (PatternStyle == 68)
    {
      blinkRed();
      Serial.println("Finished");
    }
    Serial.print("\nPattern Style: ");
    Serial.print(PatternStyle);
    Serial.print("\n");
  }
}

void allRed()
{
  for (int i = 0; i<LEDcount; i++)
  {
    leds[i] = CRGB(127,0,0);
  }
  FastLED.show();
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
    
  }
}
void allOff()
{
  for (int i = 0; i<LEDcount; i++)
  {
    leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
}
