// (c) Michael Schoeffler 2017, http://www.mschoeffler.de
#include "FastLED.h"

#define DATA_PIN 3
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 119
#define BRIGHTNESS 96

CRGB leds[NUM_LEDS];

void setup() {
  delay(3000); // initial delay of a few seconds is recommended
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip); // initializes LED strip
  FastLED.setBrightness(BRIGHTNESS);// global brightness
}

// switches off all LEDs
void showProgramCleanUp(long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(delayTime);
}

void theaterChase(uint32_t c, uint8_t delayTime, CHSV Rand) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < NUM_LEDS; i=i+3) {
        leds[i+q] = Rand;    //turn every third pixel on
      }
      delay(delayTime);
      FastLED.show();
      
      for (uint16_t i=0; i < NUM_LEDS; i=i+3) {
        leds[i+q] = CHSV(0,0,0);        //turn every third pixel off
      }
      
      delay(delayTime);
    }
  }
}

void theaterChase2(uint32_t c, uint8_t delayTime, CHSV Rand) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 2; q++) {
      for (uint16_t i=0; i < NUM_LEDS; i=i+2) {
        leds[i+q] = Rand;    //turn every third pixel on
      }
      delay(delayTime);
      FastLED.show();
      
      for (uint16_t i=0; i < NUM_LEDS; i=i+2) {
        leds[i+q] = CHSV(0,0,0);        //turn every third pixel off
      }
      
      delay(delayTime);
    }
  }
}

void showProgramShiftSinglePixel(CHSV crgb, long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = crgb;
    FastLED.show();
    delay(delayTime);
    leds[i] = CRGB::Black;
  }
}

void showProgramShiftSinglePixelReverse(CHSV crgb, long delayTime) {
  for (int i = NUM_LEDS; i > 0; --i) {
    leds[i] = crgb;
    FastLED.show();
    delay(delayTime);
    leds[i] = CRGB::Black;
  }
}

void Sections(CHSV crgb) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = crgb;
    FastLED.show();
  }
}

void reverseSections(CHSV crgb) {
  for (int i = NUM_LEDS; i > 0; --i) {
    leds[i] = crgb;
    FastLED.show();
  }
}


// main program
void loop() {
  Sections(CHSV(random8(),255,255));
  delay(500);
  reverseSections(CHSV(random8(),255,255));
  delay(200);
  showProgramShiftSinglePixel(CHSV(random8(),255,255), 5);
  reverseSections(CHSV(random8(),255,255));
  delay(100);
  showProgramShiftSinglePixelReverse(CHSV(random8(),255,255), 5);
  reverseSections(CHSV(random8(),255,255));
  showProgramShiftSinglePixelReverse(CHSV(random8(),255,255), 5);
  Sections(CHSV(random8(),255,255));
  showProgramShiftSinglePixel(CHSV(random8(),255,255), 5);
  reverseSections(CHSV(random8(),255,255));
  delay(20);
  showProgramShiftSinglePixelReverse(CHSV(random8(),255,255), 5);
  Sections(CHSV(random8(),255,255));
  Sections(CHSV(random8(),255,255));
  delay(250);
  showProgramShiftSinglePixel(CHSV(random8(),255,255), 5);
  reverseSections(CHSV(random8(),255,255));
  delay(100);
  showProgramShiftSinglePixel(CHSV(random8(),255,255), 5);
  reverseSections(CHSV(random8(),255,255));
  delay(20);
  reverseSections(CHSV(random8(),255,255));
  delay(400);
  showProgramShiftSinglePixelReverse(CHSV(random8(),255,255), 5);

  theaterChase(100, 25, CHSV(random8(), 255,255));
  theaterChase(100, 50, CHSV(random8(), 255,255));
  theaterChase2(100, 50, CHSV(random8(), 255,255));
  
  Sections(CHSV(random8(),255,255));
  delay(200);
  showProgramCleanUp(100);
  reverseSections(CHSV(random8(),255,255));
  delay(500);
  showProgramCleanUp(100);
  Sections(CHSV(random8(),255,255));
  delay(100);
  showProgramCleanUp(100);
  reverseSections(CHSV(random8(),255,255));
  delay(10);
  showProgramCleanUp(100);
  Sections(CHSV(random8(),255,255));
  delay(800);
  showProgramCleanUp(100);
  reverseSections(CHSV(random8(),255,255));  
  delay(500);
  showProgramCleanUp(100);
  Sections(CHSV(random8(),255,255));
  delay(100);
  showProgramCleanUp(100);
  reverseSections(CHSV(random8(),255,255));
  delay(50);
  showProgramCleanUp(100);
  Sections(CHSV(random8(),255,255));
  delay(100);
  
  theaterChase(100, 25, CHSV(random8(), 255,255));
  theaterChase(100, 50, CHSV(random8(), 255,255));
  theaterChase2(100, 50, CHSV(random8(), 255,255));
  
  showProgramCleanUp(100);
  
}
