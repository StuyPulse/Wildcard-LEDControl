#include <FastLED.h>
#define NUM_LEDS 10
#define LED_PIN 7
CRGB leds[NUM_LEDS];
void setup() {
  FastLED.addLeds<WS2812,LED_PIN,GRB>(leds,NUM_LEDS);
}

void loop(){
  fire1();      //yellow looks green
  //fire2();
  //pulsinglights();
  //flashinglights();
  //onecolorstrobe();
  //rainbowstrobe();
  //movinglight();
  //testcolorhsv(30,255,100);
}

void fire1() {
  for(int i=0;i<10;i++){
    if (i<4){
      leds[i]=CHSV(random(20,25),255,255);}
    if (4<=i and i<=6){
      leds[i]=CHSV(random(10,20),255,255);}
    if (6<i and i<10){
      leds[i]=CHSV(random(0,10),255,255);}
    }
    FastLED.show();
    delay(random(100));
}

void fire2(){
  for(int i=0;i<10;i++){
    leds[i]=CHSV(0+(i*3),255,255);
    FastLED.show();
    }
}

void pulsinglights(){
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

void flashinglights(){
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
  delay(100);
}
}

void onecolorstrobe(){
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
}
}

void rainbowstrobe(){
for(int i=0;i<2;i++){
  if (i%2==0){
    for(int x=0; x<10; x++){
      leds[x]=CHSV(random(0,255),255,150);
      //leds[x]=CRGB(random(0,255),random(0,255),random(0,255));
      FastLED.show();
      }
  }
  if (i%2==1){
    for(int y=0;y<10;y++){
      leds[y]=CRGB(0,0,0);
      FastLED.show();
      }
  }
}
}

void movinglight(){
  for(int i=0;i<11;i++){
    leds[i]=CRGB(0,255,0);
    leds[i-1]=CRGB(0,0,0);
    FastLED.show();
    delay(100);
  }
}

void testcolorhsv(int h, int s, int v){
  leds[0]=CHSV(h,s,v);
  FastLED.show();
}
