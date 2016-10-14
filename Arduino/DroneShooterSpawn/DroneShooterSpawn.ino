#include <IRremote.h>

/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#define MY_ID 0xb01
IRsend irsend;
int state;

void setup()
{
  state = 0;
  pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
}

void loop() {
  digitalWrite(13, state++&0b100);
  
  irsend.sendSony(MY_ID, 12);
  delay(400);
}

