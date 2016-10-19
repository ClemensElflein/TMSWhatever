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

// Team One
//#define TEAM_COLOR 100,150,0,0
#define TEAM_COLOR 0,100,150,0


// Cannot change this, only reminder
#define PIN_TRANSMIT 3
#define PIN_PIXEL2 7
#define PIN_RECEIVE 2
//#define PIN_LED D2
#define PIN_PIXEL 4
#define PIN_PLAY_SOUND_SHOOT 8
#define PIN_PLAY_SOUND_RELOAD 9
#define PIN_PLAY_SOUND_DEAD 10
#define PIN_PLAY_SOUND_ALIVE 11
#define PIN_PLAY_SOUND_SHOOT_NOAMMO 12
#define PIN_LASER 13
#define PIN_FLASHLIGHT A0

#define SOUND_SHOOT 1
#define SOUND_RELOAD 2
#define SOUND_DEAD 3
#define SOUND_ALIVE 4
#define SOUND_SHOOT_NOAMMO 5

#define PIN_TRIGGER 5
//#define PIN_STATUS D2
#define PIXEL_COUNT 4
#define PIXEL_COUNT2 12

#define PIN_RELOAD_TRIGGER 6


// Send SHOOT_COUNT often if we want to shoot
#define SHOOT_COUNT 2
#define MAX_AMMO 4

IRsend irsend;
IRrecv irrecv(PIN_RECEIVE);
decode_results results;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIN_PIXEL, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(PIXEL_COUNT2, PIN_PIXEL2, NEO_GRBW + NEO_KHZ800);

bool alive;
bool triggerDown;
bool reloadTriggerDown;
bool flashlightState;

#ifdef GUN_RELOADABLE
  int bullets;
  int blinkCounter = 0;
  bool blinkState;
#endif

void setup()
{
  flashlightState = false;
  pinMode(PIN_PLAY_SOUND_DEAD, INPUT);
  pinMode(PIN_PLAY_SOUND_SHOOT, INPUT);
  pinMode(PIN_PLAY_SOUND_ALIVE, INPUT);
  pinMode(PIN_PLAY_SOUND_RELOAD, INPUT);
  pinMode(PIN_PLAY_SOUND_SHOOT_NOAMMO, INPUT);

  pinMode(PIN_LASER, OUTPUT);
  digitalWrite(PIN_LASER, LOW);

  pinMode(PIN_FLASHLIGHT, INPUT_PULLUP);
  
  
  Serial.begin(115200);
  Serial.println("Booting");
  
  pinMode(PIN_RECEIVE, INPUT);
  digitalWrite(PIN_RECEIVE, HIGH);
  irrecv.enableIRIn();
  
  strip.begin();
  strip2.begin();
  
  pinMode(PIN_TRIGGER, INPUT_PULLUP);

  
#ifdef GUN_RELOADABLE
  bullets = MAX_AMMO;
  blinkCounter = 0;
  blinkState = 1;
  
  pinMode(PIN_RELOAD_TRIGGER, INPUT_PULLUP);
#endif
  triggerDown = !digitalRead(PIN_TRIGGER);

  setAlive(true);

  setColorFront(0,0,0,0);
  strip2.show();
  
  Serial.println("setup done");
}

void loop() {
  bool flashlightStateNow = !digitalRead(PIN_FLASHLIGHT);
  if(flashlightStateNow != flashlightState) {
    flashlightState = flashlightStateNow;
    setColorFront(0,0,0,0);
    strip2.show();
  }
  
  bool triggerDownNow = !digitalRead(PIN_TRIGGER);
  if(triggerDownNow && !triggerDown) {
    delay(10);
    triggerDownNow &= !digitalRead(PIN_TRIGGER);
  }

#ifdef GUN_RELOADABLE
  blinkCounter++;
  if(blinkCounter > 5) {
    blinkState = !blinkState;
    blinkCounter = 0;
  }
  bool reloadTriggerDownNow = !digitalRead(PIN_RELOAD_TRIGGER);
  
  if(reloadTriggerDownNow) {
    delay(10);
    reloadTriggerDownNow &= !digitalRead(PIN_RELOAD_TRIGGER);
  }
  if(reloadTriggerDownNow && !reloadTriggerDown) {
    reload();
  }
  reloadTriggerDown = reloadTriggerDownNow;
#endif
  
  if(triggerDownNow && !triggerDown) {
    shoot();
  }
  triggerDown = triggerDownNow;

  if (irrecv.decode(&results)) {
    irrecv.resume();
    if(results.decode_type == SONY) {
      if((results.value & 0xf00) == 0xa00) {
        // Spawn
        if(!alive) {
          playSound(SOUND_ALIVE);
        }
        setAlive(true);
      } else {
        if(alive) {
          playSound(SOUND_DEAD);
        }
        setAlive(false);
      }
    }
  }


  updateColor();
}

void playSound(uint8_t id) {
  int pin = 0;
  switch(id) {
    case SOUND_SHOOT:
    pin = PIN_PLAY_SOUND_SHOOT;
    break;
    case SOUND_DEAD:
    pin = PIN_PLAY_SOUND_DEAD;
    break;
    case SOUND_ALIVE:
    pin = PIN_PLAY_SOUND_ALIVE;
    break;
    case SOUND_RELOAD:
    pin = PIN_PLAY_SOUND_RELOAD;
    break;
    case SOUND_SHOOT_NOAMMO:
    pin = PIN_PLAY_SOUND_SHOOT_NOAMMO;
    break;
    default:
    return;
  }

  //Down the pin for some time and let it free again
  pinMode(pin, OUTPUT);
  delay(1);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
}

#ifdef GUN_RELOADABLE
void reload() {
  playSound(SOUND_RELOAD);
  
  bullets = MAX_AMMO;
  updateColor();
}
#endif


void shoot() {  
#ifdef GUN_RELOADABLE
  if(!alive) {
    return;
  }
  if(bullets <= 0) {
    playSound(SOUND_SHOOT_NOAMMO);
    return;
  }
  bullets--;
  blinkState = 0;
  updateColor();
#endif
  playSound(1);

  setColorFront(0,0,0,255);
  strip2.show();
  digitalWrite(PIN_LASER, HIGH);


  for (int i = 0; i < SHOOT_COUNT; i++) {
    irsend.sendSony(0xb01, 12);
    delay(10);
  }

  setColorFront(0,0,0,0);
  strip2.show();
  digitalWrite(PIN_LASER, LOW);

  for (int i = 0; i < SHOOT_COUNT; i++) {
    irsend.sendSony(0xb01, 12);
    delay(10);
  }
  
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
    if(bullets > 0) {
      setColorBullets(0,255,0);
    } else {
      if(blinkState) {
        setColor(0,255,0);
      } else {
        setColor(0,0,0);
      }
    }
  }
#endif
  strip.show();
  delay(10);
}

void setColor(byte r, byte g, byte b) {
    for(int i = 0; i < PIXEL_COUNT; i++)
      strip.setPixelColor(i, r,g,b,0);
}

void setColorFront(byte r, byte g, byte b, byte w) {
  if(!flashlightState) {
    if(r || b || g || w) {
     for(int i = 0; i < PIXEL_COUNT2; i++)
      strip2.setPixelColor(i, r,g,b,w); 
    } else {
     for(int i = 0; i < PIXEL_COUNT2; i++) {
        strip2.setPixelColor(i, TEAM_COLOR);
     }
    }
  } else {
    if(r || b || g || w) {
     for(int i = 0; i < PIXEL_COUNT2; i++) {
      strip2.setPixelColor(i, r,g,b,i%2 == 0 ? w : 255);
     }
    } else {
     for(int i = 0; i < PIXEL_COUNT2; i++) {
      if(i%2 == 0) {
        strip2.setPixelColor(i, 0,0,0,255);
      } else {
        strip2.setPixelColor(i, TEAM_COLOR);
      }
     }       
    }
  }
}


void setColorBullets(byte r, byte g, byte b) {
    for(int i = 0; i < PIXEL_COUNT; i++) {
      if(PIXEL_COUNT-i <= bullets)
        strip.setPixelColor(i, r,g,b,0);
      else
        strip.setPixelColor(i, 0,0,0,0);
      }
}

