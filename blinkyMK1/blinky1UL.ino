#include <Wire.h>
#include <FastLED.h>

#define LED_PIN 13
#define LED_COUNT 10
#define SELF_ADDRESS 13

int patternID = 0;
bool blueAlliance = false;

void setup()
{
	Wire.begin(SELF_ADDRESS);
	Wire.onReceive(recv);
	Serial.begin(9600);
	Serial.println(F("BLINKY:UL:INITIALIZED"))

}

void recv(int numBytes)
{
	if (Wire.available())
	{
		patternID = Wire.read();
	}
}

void loop()
{
	
}