#include <Wire.h>
#include <FastLED.h>

#define ULPIN 7
#define ULLEDCOUNT 8
/*
#define LLPIN 
#define LLLEDCOUNT

#define SELF_ADDRESS
*/
//CRGB LLleds[LLLEDCOUNT];
CRGB ULleds[ULLEDCOUNT];

void setup()
{
  pinMode(6,OUTPUT);
  //Wire.begin(SELF_ADDRESS);
  Wire.onReceive(recvEvent);
  Serial.begin(9600);
  Serial.println(F("BMK2: Initialized :)"));
  FastLED.addLeds<WS2812,ULPIN,GRB>(ULleds,ULLEDCOUNT);
  allSet(244,0,0,&ULleds);
}
void loop()
{
  digitalWrite(6,HIGH);
  delay(300);
  digitalWrite(6,LOW);
  delay(300);
} 

void recvEvent(int numBytes)
{

}

void allSet(int R, int G, int B, CRGB *arr)
{
  int ledCount = sizeof(arr)/sizeof(arr[0]);
  for (int index = 0; index<ledCount; index++)
  {
    arr[index] = CRGB(R,G,B);
  }
  FastLED.show();
}