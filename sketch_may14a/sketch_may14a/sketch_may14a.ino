#include <FastLED.h>


#define ANALOGARDUINOPIN A0
#define LED_PIN 2
#define NUM_LEDS 230

word ValA0=0;
float ValA0_f=0.0;
float test;
float maxValue = 0;
float minValue = 10000;
float minValue_Val0=66;
float maxSeg = 5;
int mode = 0;
int compteur = 0; 
int R = 0;
int G = 0;
int B = 0;

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
    
    //Serial.println(ValA0_f);
    if (ValA0_f > maxValue) {
      maxValue = ValA0_f;
    }
    if (ValA0_f < minValue) {
      minValue = ValA0_f;
    }
    test = 255.0*(ValA0_f - minValue)/maxValue ;
    //Serial.println(test);
    Serial.println(minValue);
    //Serial.println(maxValue);
    minValue *= 1.01;
    maxValue *= 0.99;
    
    if(test<0) { test=0;}
    
    if(test>255) {test=255;}
    
    /*
    for (int i=0 ; i<5 ; i++){
      Leds[i] = CRGB(test , 0 ,255 -test); 
      moveRight();
      
      FastLED.show();
      delay(5);
    */
   
    if (test >127){
      compteur +=1;
      if (compteur > 20) {
        compteur = 0;
      }
      if (compteur == 10 || compteur == 20) {
        
        R = random(0, 255);
        G = random(0, 255);
        B = random(0, 255);
      }
      
      for (int i=0 ; i< NUM_LEDS ; i++){
        Leds[i] = CRGB(R, G, B);      
        }
        FastLED.show();
        delay(120);
      }
      
    else {
      for (int i=0 ; i< NUM_LEDS ; i++){
        Leds[i] = CRGB::Red;
    }}

    FastLED.show();
  }

void moveRight(){
  for (int i=NUM_LEDS-1 ; i>3 ; i--){
    Leds[i] = Leds[i-1];
  }
}
