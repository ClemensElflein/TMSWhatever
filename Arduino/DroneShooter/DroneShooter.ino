#include <WS2811.h>


/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

#include "TinyWireS.h"
#define I2C_SLAVE_ADDR  0x26

// Cannot change this, only reminder
#define PIN_TRANSMIT 1
#define PIN_RECEIVE 3
#define PIXEL_COUNT 1
#define PIN_PIXEL 4

// Send SHOOT_COUNT often if we want to shoot
#define SHOOT_COUNT 4

IRsend irsend;
IRrecv irrecv(PIN_RECEIVE);
decode_results results;

DEFINE_WS2811_FN(WS2811RGB, PORTB, PIN_PIXEL)
RGB_t rgb[1];

bool alive;
bool triggerDown;

void setup()
{

  irrecv.enableIRIn();
  pinMode(PIN_PIXEL, OUTPUT);
 
  TinyWireS.begin(I2C_SLAVE_ADDR);
  setAlive(true);

  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(1, LOW);
  delay(100);
}

void loop() {
  
  if (irrecv.decode(&results)) {
    irrecv.resume();
    if(results.decode_type == SONY) {
      setAlive(false);
      delay(1000);
      setAlive(true);
    }
  }

  if(TinyWireS.available()) {
    while(TinyWireS.available())
      TinyWireS.receive();
    shoot();
  }

  updateColor();
}


void shoot() {
  for (int i = 0; i < SHOOT_COUNT; i++) {
    irsend.sendSony(0x123, 12);
    delay(40);
  }
  irrecv.enableIRIn();
  TinyWireS.begin(I2C_SLAVE_ADDR);
}

void setAlive(bool a) {
  alive = a;
  updateColor();
}

void updateColor() {
  bool a = alive;
  if(a) {
    setColor(0,255,0);
  } else {
    setColor(255,0,0);
  }
  WS2811RGB(rgb, ARRAYLEN(rgb));
}

void setColor(byte r, byte g, byte b) {
    rgb[0].r=r;
    rgb[0].g=g;
    rgb[0].b=b;
}

