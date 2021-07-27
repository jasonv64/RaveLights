// (c) Michael Schoeffler 2017, http://www.mschoeffler.de
#include "FastLED.h"

#define DATA_PIN 3
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 150
#define BRIGHTNESS 96

CRGB leds[NUM_LEDS];

void setup() {
  delay(3000); // initial delay of a few seconds is recommended
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip); // initializes LED strip
  FastLED.setBrightness(BRIGHTNESS);// global brightness
}

// switches off all LEDs
//void showProgramCleanUp(long delayTime) {
//  for (int i = 0; i < NUM_LEDS; ++i) {
//    leds[i] = CRGB::Black;
//  }
//  FastLED.show();
//  delay(delayTime);
//}

// switches on all LEDs. Each LED is shown in random color.
// numIterations: indicates how often LEDs are switched on in random colors
// delayTime: indicates for how long LEDs are switched on.
void showProgramRandom(int numIterations, long delayTime) {
  for (int iteration = 0; iteration < numIterations; ++iteration) {
    for (int i = 0; i < NUM_LEDS; ++i) {
      leds[i] = CHSV(random8(),255,255); // hue, saturation, value
    }
    FastLED.show();
    delay(delayTime);
  }
}

// Shifts a single pixel from the start of strip to the end.
// crgb: color of shifted pixel
// delayTime: indicates how long the pixel is shown on each LED
void showProgramShiftSinglePixel(CRGB crgb, long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = crgb;
    FastLED.show();
    delay(delayTime);
    leds[i] = CRGB::Black;
  }
}

// main program
void loop() {
//  showProgramCleanUp(2500); // clean up
  showProgramRandom(100, 100); // show "random" program
  
 // showProgramCleanUp(2500); // clean up
  showProgramShiftSinglePixel(CRGB::Blue, 25); // show "shift single pixel program" with blue pixel
  
 // showProgramCleanUp(2500); // clean up
  showProgramShiftSinglePixel(CRGB::Maroon, 25); // show "shift single pixel program" with maroon pixel
  
}
