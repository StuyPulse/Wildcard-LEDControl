#include <FastLED.h>
#define NUM_LEDS ___
#define LED_PIN ___
CRGB leds[NUM_LEDS];
int redAlliance;
int patternID;

void setup()
{
	FastLED.addLeds<WS2812,LED_PIN,GRB>(leds,NUM_LEDS);
}

void loop()
{
		
}

//FlatGreen
void allSet(R,G,B)
{
	for (int ledIndex = 0; ledIndex<NUM_LEDS; ledIndex++)
	{
		leds[ledIndex] = CRGB(R,G,B);
	}
	FastLED.show();
}

void alliancePulse()
{
	if (redAlliance)
	{
		while (patternID == 10)
		{
			for (int brightness = 0; brightness<255; brightness++)
			{
				leds[ledIndex] = CRGB(brightness,0,0);
				FastLED.show();
				delay(100);
			}
			for (int brightness = 255; brightness>0; brightness--)
			{
				leds[ledIndex] = CRGB(brightness,0,0);
				FastLED.show();
				delay(100);	
			}
		}
	}	
	else
	{
		while (patternID == 10)
		{
			for (int brightness = 0; brightness<255; brightness++)
			{
				leds[ledIndex] = CRGB(0,0,brightness);
				FastLED.show();
				delay(100);
			}
			for (int brightness = 255; brightness>0; brightness--)
			{
				leds[ledIndex] = CRGB(0,0,brightness);
				FastLED.show();
				delay(100);	
			}
		}
	}
}

void liftProgressBar()
{
	ledIndex = 0;
	while (patternID == 11 && ledIndex < LIFT_LED_COUNT)
	{
		leds[ledIndex] = CRGB(0,233,0);
		leds[ledIndex+1] = CRGB(0,233,0);
		FastLED.show();
		delay(1000);
		ledIndex+=2;
	}
}

//SET PATTERN ID
void liftPulseGreen()
{
	while (patternID == 10)
	{
		for (int brightness = 0; brightness<255; brightness++)
		{
			leds[ledIndex] = CRGB(0,brightness,0);
			FastLED.show();
			delay(100);
		}
		for (int brightness = 255; brightness>0; brightness--)
		{
			leds[ledIndex] = CRGB(0,brightness,0);
			FastLED.show();
			delay(100);	
		}
	}
}

//SET PATTERN ID
//rgb(138,43,226)
void liftPurpleRise()
{
	while (patternID == 10)
	{
		for (int ledIndex = 0, ledIndex < LIFT_LED_COUNT, ledIndex++)
		{
			
		}
	}
}