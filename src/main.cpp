#include <Arduino.h>

#define MA_BROCHE_BOUTON 39 //bouton
#include <MicroOscSlip.h>
#define MA_BROCHE_ANGLE 32 //potentiomètre
#include <FastLED.h>

MicroOscSlip<128> monOsc(& Serial); // nombre entre 0 à 128
CRGB pixelATOM;

void setup() {
  Serial.begin(115200);
  pinMode( MA_BROCHE_BOUTON , INPUT );
  FastLED.addLeds < WS2812,27,GRB> ( & pixelATOM, 1);
}

void loop() {
  int maLectureAngle;
  maLectureAngle = analogRead(MA_BROCHE_ANGLE); 
  //Serial.print(maLectureAngle);
  //Serial.println()
  monOsc.sendInt("/pot", maLectureAngle);

  int maLectureBouton = digitalRead( MA_BROCHE_BOUTON );
  //Serial.println(maLectureBouton);
  monOsc.sendInt("/but", maLectureBouton);

  if ( maLectureAngle >= 0 && maLectureAngle <=2048) {
    pixelATOM = CRGB(255, 255, 0); //jaune
    FastLED.show();
   } else {
    pixelATOM = CRGB(0,0,255); //bleu
    FastLED.show();
  }

  delay(50);

}
