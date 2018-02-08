#include <Wire.h>
#include <FastLED.h>
#define LEDcount 10
#define LED_PIN 7
#define SELF_ADDRESS 10
CRGB leds[LEDcount];
volatile int PatternStyle;

void setup() {
  Wire.begin(SELF_ADDRESS);
  Wire.onReceive(recvEvent);
  Serial.begin(9600);
  Serial.println("Slave initialized.");
  FastLED.addLeds<WS2812,LED_PIN,GRB>(leds,LEDcount);
}

void loop() {
  // Nothing in loop, all dealt with in recvEvent.
}

void recvEvent(int howMany)
{
  if (Wire.available())
  {
    PatternStyle = Wire.read();
	//For trimming address byte sent by the Roborio.
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
      Serial.println("Blinky finished");
    }
    Serial.print("\nPattern Style: ");
    Serial.print(PatternStyle);
    Serial.print("\n");
  }
}


//LED Helper Functions
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
