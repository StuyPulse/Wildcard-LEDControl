#include <Wire.h>
#include <FastLED.h>
#define LEDcount 10
#define LED_PIN 7
#define SELF_ADDRESS 8

//Instance LED Strip LED array.
CRGB leds[LEDcount];

volatile int patternID;


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
    patternID = Wire.read();
	//For trimming address byte sent by the Roborio.
    if (patternID == SELF_ADDRESS)
    {
      Serial.println("Address received");
      patternID = Wire.read();
    }
    if (patternID==65)
    {
      allRed();
      Serial.println("Turned on");
    }
    if (patternID==66)
    {
      allOff();
      Serial.println("Turned off");
    }
    if (patternID == 68)
    {
      blinkRed();
      Serial.println("Blinky finished");
    }
    Serial.print("\nPattern Style: ");
    Serial.print(patternID);
    Serial.print("\n");
  }
}


//LED Helper Functions
//patternID: 65
void allRed()
{
  for (int i = 0; i<LEDcount; i++)
  {
    leds[i] = CRGB(127,0,0);
  }
  FastLED.show();
}
//patternID: 68
void blinkRed()
{
  while (patternID == 68)
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
//patternID: 66
void allOff()
{
  for (int i = 0; i<LEDcount; i++)
  {
    leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
}
