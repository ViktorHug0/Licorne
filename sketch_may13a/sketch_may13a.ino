#include <FastLED.h>


#define ANALOGARDUINOPIN A0
#define LED_PIN 2
#define NUM_LEDS 230

word ValA0=0;
float ValA0_f=0.0;
float test;
float minValue_Val0=66;
float maxSeg = 5;
int mode = 0;

CRGB Leds[NUM_LEDS];

void setup() {
  pinMode(ANALOGARDUINOPIN, INPUT);
  FastLED.addLeds<WS2812B , LED_PIN , GRB>(Leds,NUM_LEDS);
  FastLED.setBrightness(50);
  Serial.begin(9600);
}



void loop() {
    ValA0_f = analogRead(ANALOGARDUINOPIN);
    //ValA0_f =(float)ValA0*500.0/1023.0;
    //ValA0_f = ValA0_f-minValue_Val0;
    
 

    test = 255*(ValA0_f-30.0)/1000.0;

    Serial.println(test);
    if(test<0) { test=0;}
    if(test>255) {test=255;}

    if (test>200){
      for (int i=0 ; i<5 ; i++){
        Leds[i] = CRGB::Red; 
        moveRight();
        FastLED.show();
        delay(5);
      }}
    else {
      for (int i=0 ; i<5 ; i++){
        Leds[i] = CRGB::Blue;
        moveRight();
        FastLED.show();
        delay(5);
    }
    }}

    
void moveRight(){
  for (int i=NUM_LEDS-1 ; i>3 ; i--){
    Leds[i] = Leds[i-1];
  }
}
