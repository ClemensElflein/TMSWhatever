#include <Adafruit_NeoPixel.h>

/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */


#include <IRremote.h>

// Cannot change this, only reminder
#define PIN_TRANSMIT 1
#define PIN_RECEIVE 3
#define PIN_PIXEL 4

// Send SHOOT_COUNT often if we want to shoot
#define SHOOT_COUNT 1

IRsend irsend;
IRrecv irrecv(PIN_RECEIVE);
decode_results results;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN_PIXEL, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();

  strip.begin();
  strip.show();
  strip.setPixelColor(0, 255, 0, 0);
  strip.show();
  delay(500);
  strip.setPixelColor(0, 0, 255, 0);
  strip.show();
}

void loop() {
	if (irrecv.decode(&results)) {
    irrecv.resume();
    if(results.decode_type == SONY) {
      strip.setPixelColor(0, 0, 0, 255);
      strip.show();
      shoot();
    }
  }
}

void shoot() {
  for (int i = 0; i < SHOOT_COUNT; i++) {
    irsend.sendSony(0x123, 12);
    delay(40);
  }
  irrecv.enableIRIn();
}

