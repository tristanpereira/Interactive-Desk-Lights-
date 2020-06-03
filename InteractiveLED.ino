/*****************  NEEDED TO MAKE NODEMCU WORK ***************************/
#define FASTLED_INTERRUPT_RETRY_COUNT 0
#define FASTLED_ESP8266_RAW_PIN_ORDER
/******************  LIBRARY SECTION *************************************/
#include <FastLED.h>
/*****************  LED LAYOUT AND SETUP *********************************/
#define NUM_LEDS 31
/*****************  DECLARATIONS  ****************************************/
CRGB leds[NUM_LEDS];
/*****************  GLOBAL VARIABLES  ************************************/
const int ledPin = 4; //marked as D2 on the board
int i = 0;
int c = 1;
const int analogInPin = A0;  // ESP8266 Analog Pin ADC0 = A0
int sensorValue = 0;  // value read from the pot
int colorValue = 0;  // value to output to a PWM pin
int modeValue = 0;
const int digitalPin = 16;
int digitalValue = 0;

/*****************  SETUP FUNCTIONS  ****************************************/
void setup()
{
  Serial.begin(115200);
  FastLED.addLeds<WS2812B, ledPin, GRB>(leds, NUM_LEDS);
  pinMode(digitalPin, INPUT);
}
/*****************  MAIN LOOP  ****************************************/
void loop()
{
  // read the Potentiometer/Sound Detection Module values
  sensorValue = analogRead(analogInPin);
  digitalValue = digitalRead(digitalPin);
  // if statements
  if (sensorValue <= 333) {
    modeValue = 1;
    leds[i] = CHSV (c, 255, 192);
    FastLED.show();
    delay(100);
    i = i + 1 ;

    if (i == 31) {
      i = 0;
      c = c + 5;
    }
    if ( c == 255) {
      c = 0 ;
    }
  }
  else if (333 < sensorValue && sensorValue <= 666) {
    modeValue = 2;
    colorValue = map(sensorValue, 666, 1023, 0, 255);
    leds[i] = CHSV (colorValue, 255, 192);
    FastLED.show();
    delay(100);
    i = i + 1 ;

    if (i == 31) {
      i = 0;
    }

  }
  else if (666 < sensorValue && sensorValue <= 1024 ) {
    modeValue = 3;
    if (digitalValue == HIGH) {
      int x = random(1, 3);

      if (x == 1) {
        leds[(NUM_LEDS / 2)] = CHSV(160, 200, 150);
      }
      else if (x == 2) {
        leds[(NUM_LEDS / 2)] = CHSV(140, 200, 150);
      }
      else if (x == 3) {
        leds[(NUM_LEDS / 2)] = CHSV(180, 200, 150);
      }
      FastLED.show();
      delay(100);
      for (int z = NUM_LEDS; z > (NUM_LEDS / 2); z--) {
        leds[z] = leds[z - 1];
      }
      for (int z = 0; z < (NUM_LEDS / 2); z++) {
        leds[z] = leds[z + 1];
      }
    }
    else {
      leds[(NUM_LEDS / 2)] = CHSV(255, 0, 150);
      FastLED.show();
      delay(100);
      for (int z = NUM_LEDS; z > (NUM_LEDS / 2); z--) {
        leds[z] = leds[z - 1];
      }
      for (int z = 0; z < (NUM_LEDS / 2); z++) {
        leds[z] = leds[z + 1];
      }
      
    }
  }
  else {
    modeValue = 0;
  }
}
