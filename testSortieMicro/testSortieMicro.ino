#define ANALOGARDUINOPIN 34

float ValA0_f=0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

   ValA0_f = analogRead(ANALOGARDUINOPIN);
   ValA0_f=2.0*ValA0_f;
   
   Serial.println(ValA0_f);

}
