#include <FastLED.h>
#define NUM_LEDS 10
#define LED_PIN 7
CRGB leds[NUM_LEDS];

void setup() {
  //Initialize the LEDs	
  FastLED.addLeds<WS2812,LED_PIN,GRB>(leds,NUM_LEDS);
}


void blinkinglights(){
for(int i=0;i<2;i++){
  if (i%2==0){
    for(int x=0; x<10; x++){
      leds[x]=CRGB(255,0,0);
      FastLED.show();
      }
  }
  if (i%2==1){
    for(int y=0;y<10;y++){
      leds[y]=CRGB(0,0,0);
      FastLED.show();
      }
  }
  delay(500);
}
}

//Moves single pixel across LED strip
void movinglight(){
  for(int i=0;i<11;i++){
    leds[i]=CRGB(0,255,0);
    leds[i-1]=CRGB(0,0,0);
    FastLED.show();
    delay(100);
  }
}

void loop(){
  blinkinglights();
  movinglight();
}

