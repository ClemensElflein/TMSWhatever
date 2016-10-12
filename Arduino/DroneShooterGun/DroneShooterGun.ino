#include <Adafruit_NeoPixel.h>

/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#define GUN_RELOADABLE

#include <IRremote.h>

// Cannot change this, only reminder
#define PIN_TRANSMIT 1
#define PIN_RECEIVE 2
#define PIN_PIXEL 4


#define PIN_TRIGGER 5
#define PIN_STATUS 13
#define PIXEL_COUNT 4
#define PIN_RELOAD_TRIGGER 6


// Send SHOOT_COUNT often if we want to shoot
#define SHOOT_COUNT 4

IRsend irsend;
IRrecv irrecv(PIN_RECEIVE);
decode_results results;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIN_PIXEL, NEO_GRB + NEO_KHZ800);

bool alive;
bool triggerDown;

#ifdef GUN_RELOADABLE
  bool loaded;
  int blinkCounter = 0;
  bool blinkState;
#endif

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();

  
  strip.begin();


  pinMode(PIN_TRIGGER, INPUT);
  digitalWrite(PIN_TRIGGER, HIGH);
  pinMode(PIN_STATUS, OUTPUT);
  digitalWrite(PIN_STATUS, LOW);
#ifdef GUN_RELOADABLE
  blinkCounter = 0;
  blinkState = 1;
  
  pinMode(PIN_RELOAD_TRIGGER, INPUT);
  digitalWrite(PIN_RELOAD_TRIGGER, HIGH);
  loaded = true;
#endif
  triggerDown = !digitalRead(PIN_TRIGGER);


  setAlive(true);
}

void loop() {

  bool triggerDownNow = !digitalRead(PIN_TRIGGER);
  if(triggerDownNow && !triggerDown) {
    delay(10);
    triggerDownNow &= !digitalRead(PIN_TRIGGER);
  }

#ifdef GUN_RELOADABLE
  blinkCounter++;
  if(blinkCounter > 300) {
    blinkState = !blinkState;
    blinkCounter = 0;
  }
  bool reloadTriggerDown = !digitalRead(PIN_RELOAD_TRIGGER);
  if(reloadTriggerDown) {
    delay(10);
    reloadTriggerDown &= !digitalRead(PIN_RELOAD_TRIGGER);
  }
  if(reloadTriggerDown) {
    reload();
  }
#endif
  
  if(triggerDownNow && !triggerDown) {
    shoot();
  }
  triggerDown = triggerDownNow;

  
	if (irrecv.decode(&results)) {
    irrecv.resume();
    if(results.decode_type == SONY) {
      setAlive(false);
      delay(1000);
      setAlive(true);
      
    }
  }


  updateColor();
}


#ifdef GUN_RELOADABLE
void reload() {
  loaded = true;
}
#endif


void shoot() {

#ifdef GUN_RELOADABLE
  if(!loaded)
    return;
  loaded = false;
#endif
  digitalWrite(PIN_STATUS, HIGH);

  for (int i = 0; i < SHOOT_COUNT; i++) {
    irsend.sendSony(0x123, 12);
    delay(40);
  }

  delay(100);
  digitalWrite(PIN_STATUS, LOW);

  irrecv.enableIRIn();
}

void setAlive(bool a) {

  Serial.println(a ? "alive" : "dead");    

  alive = a;
  updateColor();
}

void updateColor() {
  bool a = alive;
#ifndef GUN_RELOADABLE
  if(a) {
    setColor(0,255,0);
  } else {
    setColor(255,0,0);
  }
#else
  if(!a) {
    setColor(255,0,0);  
  } else {
    if(loaded) {
      setColor(0,255,0);
    } else {
      if(blinkState) {
        setColor(0,20,0);
      } else {
        setColor(0,255,0);
      }
    }
  }
#endif
  strip.show();
}

void setColor(byte r, byte g, byte b) {
    for(int i = 0; i < PIXEL_COUNT; i++)
      strip.setPixelColor(i, r,g,b);
}

