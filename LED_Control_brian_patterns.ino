#include <fastpin.h>
#include <pixelset.h>
#include <fastled_config.h>
#include <colorutils.h>
#include <fastled_progmem.h>
#include <noise.h>
#include <lib8tion.h>
#include <chipsets.h>
#include <fastspi_dma.h>
#include <platforms.h>
#include <fastspi.h>
#include <led_sysdefs.h>
#include <fastspi_bitbang.h>
#include <cpp_compat.h>
#include <FastLED.h>
#include <fastspi_nop.h>
#include <fastled_delay.h>
#include <pixeltypes.h>
#include <colorpalettes.h>
#include <hsv2rgb.h>
#include <dmx.h>
#include <fastspi_types.h>
#include <color.h>
#include <fastspi_ref.h>
#include <bitswap.h>
#include <power_mgt.h>
#include <controller.h>
#define NUM_LEDS 10
#define LED_PIN 7
CRGB leds[NUM_LEDS];
int redAlliance;
int patternID;

void setup()
{
	FastLED.addLeds<WS2812,LED_PIN,GRB>(leds,NUM_LEDS);
}

void loop()
{
	patternID=10;	
}

//FlatGreen
void allSet(int R,int G,int B)
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
			if (ledIndex%5==0)
			{
				leds[ledIndex] = CRGB(138,43,226);
				leds[ledIndex+1] = CRGB(138,43,226);
			}
		}
	}
}