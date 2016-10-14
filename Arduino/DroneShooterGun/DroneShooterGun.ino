#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

const char* ssid = "#tms";
const char* password = "ilovetms2016";

#include <Adafruit_NeoPixel.h>

#define OTA_EVERYTIME

/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#define GUN_RELOADABLE

#include <IRremoteESP8266.h>

// Cannot change this, only reminder
#define PIN_TRANSMIT D7
#define PIN_PIXEL2 D8
#define PIN_RECEIVE 1
//#define PIN_LED D2
#define PIN_PIXEL D4


#define PIN_TRIGGER D5
//#define PIN_STATUS D2
#define PIXEL_COUNT 4
#define PIXEL_COUNT2 12

#define PIN_RELOAD_TRIGGER D6


// Send SHOOT_COUNT often if we want to shoot
#define SHOOT_COUNT 2
#define MAX_AMMO 4

IRsend irsend(PIN_TRANSMIT);
IRrecv irrecv(PIN_RECEIVE);
decode_results results;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIN_PIXEL, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(PIXEL_COUNT2, PIN_PIXEL2, NEO_GRBW + NEO_KHZ800);

bool alive;
bool triggerDown;

bool hasWifi;
bool otaMode;

#ifdef GUN_RELOADABLE
  int bullets;
  int blinkCounter = 0;
  bool blinkState;
#endif

void setup()
{
  hasWifi = false;
  otaMode = false;
  Serial.begin(115200);
  Serial.println("Booting");
  
  
  strip.begin();
  strip2.begin();
  
  pinMode(PIN_TRIGGER, INPUT_PULLUP);
#ifndef OTA_EVERYTIME
    
  if(!digitalRead(PIN_TRIGGER)) {
    otaSetup();
    return;
  }
  #else
  otaSetup();
  #endif
  irrecv.enableIRIn();

#ifdef GUN_RELOADABLE
  bullets = MAX_AMMO;
  blinkCounter = 0;
  blinkState = 1;
  
  pinMode(PIN_RELOAD_TRIGGER, INPUT_PULLUP);
#endif
  triggerDown = !digitalRead(PIN_TRIGGER);

  setAlive(true);
  
  Serial.println("setup done");
}

void otaSetup() {
  otaMode = true;
  Serial.println("OTA Mode!");
  setColor(0,0,255);
  strip.show();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    setColor(255,0,255);
    strip.show();
    delay(100);
    setColor(0,0,255);
    strip.show();
    delay(100);
    Serial.print(".");
  }
  
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
  Serial.println("Connected");
    ArduinoOTA.onStart([]() {
      Serial.println("Start");
    });
    ArduinoOTA.onEnd([]() {
      Serial.println("\nEnd");
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });
  
  
    ArduinoOTA.begin();
    Serial.println("Ready");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

void otaLoop() {
  ArduinoOTA.handle();  
  #ifndef OTA_EVERYTIME
    setColor(0,255,0);
  strip.show();
  delay(100);
  ArduinoOTA.handle();  
  setColor(0,0,0);
  strip.show();
  delay(100);
  #endif
}

void loop() {
  if(otaMode) {
    otaLoop();
    #ifndef OTA_EVERYTIME
    return;
    #endif
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
    shoot();
    irrecv.resume();
    if(results.decode_type == SONY) {
      if((results.value & 0xf00) == 0xa00) {
        // Spawn
        setAlive(true);
      } else {
        setAlive(false);
      }
    }
  }


  updateColor();
}


#ifdef GUN_RELOADABLE
void reload() {
  for (int i = 0; i < SHOOT_COUNT; i++) {
    irsend.sendSony(0xa01, 12);
    delay(10);
  }
  Serial.println("reload");
  bullets = MAX_AMMO;
  updateColor();
}
#endif


void shoot() {  
#ifdef GUN_RELOADABLE
  if(bullets <= 0)
    return;
  bullets--;
  blinkState = 0;
  updateColor();
#endif
  setColorFront(0,0,0,255);
  strip2.show();
  


  for (int i = 0; i < SHOOT_COUNT; i++) {
    irsend.sendSony(0xb01, 12);
    delay(10);
  }

  setColorFront(0,0,0,0);
  strip2.show();

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
     for(int i = 0; i < PIXEL_COUNT2; i++)
      strip2.setPixelColor(i, r,g,b,w); 
}


void setColorBullets(byte r, byte g, byte b) {
    for(int i = 0; i < PIXEL_COUNT; i++) {
      if(PIXEL_COUNT-i <= bullets)
        strip.setPixelColor(i, r,g,b,0);
      else
        strip.setPixelColor(i, 0,0,0,0);
      }
}

