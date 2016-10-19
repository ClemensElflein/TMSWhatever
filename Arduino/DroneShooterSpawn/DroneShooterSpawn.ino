#include <IRremote.h>
#include <Adafruit_NeoPixel.h>


/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#define MY_ID 0xb01
IRsend irsend;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, 4, NEO_GRB + NEO_KHZ800);

int state;

void setup()
{
  state = 0;
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  strip.begin();
  
  strip.setPixelColor(0, 0, 255, 0, 0);
  strip.setPixelColor(1, 0, 255, 0, 0);
  strip.setPixelColor(2, 0, 255, 0, 0);
  strip.setPixelColor(3, 0, 255, 0, 0);
  strip.show();  
}

void loop() {
  //digitalWrite(13, state++&0b1);
  
  /*irsend.sendSony(0xb01, 12);
  delay(2000);
  digitalWrite(13, state++&0b1);
*/
// for(int i = 0; i < 20; i++) {
  irsend.sendSony(0xa01, 12);
  delay(100);
 //}
// delay(2000);

  
}

