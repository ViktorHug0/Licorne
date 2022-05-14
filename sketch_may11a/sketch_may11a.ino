#include <FastLED.h>

#define NUM_LEDS 40
#define LED_PIN  2

CRGB Leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B , LED_PIN , GRB>(Leds,NUM_LEDS);
  FastLED.setBrightness(50);
}

int[5] lighten( int pos ) {
  int result[5];
  if (pos<=2){
    for (int i=0 ; i<5 ; i++){
      if ((pos-2+i)<0){
        result[i] = NUM_LEDS - 1 + pos - 2+i;
      }
      else {
        result[i]= pos -2+i;
      }
    }
  }

  if (pos> NUM_LEDS - 1 -2){
    for (int i=0 ; i<5 ; i++){
      if ((pos-2 + i)> NUM_LEDS-1){
        result[i] = pos - 2 + i - NUM_LEDS + 1;
      }
      else {
        result[i]= pos -2+i;
      }
    }
  }
  return result;
}   
    
int B[5];
void loop() {
  
  
  for (int i=0 ; i<NUM_LEDS ; i++){
    B=lighten(i);

    for (int j=0 ; j<5 ; j++){
      Leds[B[j]] = CRGB::Red;
    }
   if (B[0]>=0){
    Leds[B[0]] = CRGB::Black;
   }
   }
  
  for (int i=0; i<NUM_LEDS ; i++){
    if (i!=0){
      Leds[i-1] = CRGB::Black;
    }
    else {
      Leds[NUM_LEDS-1] = CRGB::Black;
    }
    Leds[i] = CRGB::Red;
    FastLED.show();
    delay(100);
    
  }


}
