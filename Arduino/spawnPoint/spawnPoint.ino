//#include <Adafruit_NeoPixel.h>

/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

//#define GUN

#include <IRremote.h>

// Cannot change this, only reminder
#define PIN_TRANSMIT 1
#define PIN_RECEIVE 2
#define PIN_PIXEL 4

#ifdef GUN
#define PIN_TRIGGER 5
#define PIN_STATUS 13
#endif

// Send SHOOT_COUNT often if we want to shoot
#define SHOOT_COUNT 1

IRsend irsend;
IRrecv irrecv(PIN_RECEIVE);
decode_results results;

//Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN_PIXEL, NEO_GRB + NEO_KHZ800);

//bool alive;
//bool triggerDown;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();


//  strip.begin();

#ifdef GUN
  pinMode(PIN_TRIGGER, INPUT);
  digitalWrite(PIN_TRIGGER, HIGH);
  pinMode(PIN_STATUS, OUTPUT);
  digitalWrite(PIN_STATUS, LOW);

  triggerDown = !digitalRead(PIN_TRIGGER);
#endif

//  setAlive(true);
}

void loop() {
//#ifdef GUN
//  bool triggerDownNow = !digitalRead(PIN_TRIGGER);
//  delay(50);
//  triggerDownNow &= !digitalRead(PIN_TRIGGER);
//  
//  if(triggerDownNow && !triggerDown) {
    shoot();
//  }
//  triggerDown = triggerDownNow;
//#endif
  
//	if (irrecv.decode(&results)) {
//    irrecv.resume();
//    if(results.decode_type == SONY) {
//      setAlive(false);
//      delay(1000);
//      setAlive(true);
//      
//    }
//  }
}

void shoot() {
#ifdef GUN
  digitalWrite(PIN_STATUS, HIGH);
#endif
  for (int i = 0; i < SHOOT_COUNT; i++) {
    irsend.sendSony(0x123, 12);
    delay(40);
  }
#ifdef GUN
  delay(100);
  digitalWrite(PIN_STATUS, LOW);
#endif
  irrecv.enableIRIn();
}

//void setAlive(bool a) {
//#ifdef GUN
//  Serial.println(a ? "alive" : "dead");    
//#endif
//  alive = a;
//  if(a) {
//    strip.setPixelColor(0, 0, 255, 0);
//  } else {
//    strip.setPixelColor(0, 255, 0, 0);
//  }
//  strip.show();
//}

