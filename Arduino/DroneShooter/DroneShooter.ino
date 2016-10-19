#include <Adafruit_NeoPixel.h>

/*
   IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
   An IR LED must be connected to Arduino PWM pin 3.
   Version 0.1 July, 2009
   Copyright 2009 Ken Shirriff
   http://arcfn.com
*/

#include <IRremote.h>


// Cannot change this, only reminder
#define PIN_TRANSMIT 13
#define PIN_RECEIVE 1
#define PIN_PIXEL 4

#define PIXEL_COUNT 1
#define PIN_LASER 20

// Send SHOOT_COUNT often if we want to shoot
#define SHOOT_COUNT 2



IRsend irsend;
IRrecv irrecv(PIN_RECEIVE);
decode_results results;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIN_PIXEL, NEO_GRB + NEO_KHZ800);

bool alive;
bool triggerDown;
int reviveCounter;
unsigned long lastTimeShitReceived;

struct __attribute__((packed)) crtpStuct {
  uint8_t start1;
  uint8_t start2;
  uint8_t header;
  uint8_t len;
  uint8_t command;
  uint8_t data1;
  uint8_t data2;
  uint8_t data3;
  uint8_t checksum;
} crtp;

void sendToCrazyflie(uint8_t c, uint8_t d1 = 0, uint8_t d2 = 0, uint8_t d3 = 0) {
  crtp.start1 = 0xAA;
  crtp.start2 = 0xAA;
  crtp.header = 0x70;
  crtp.len = 4;
  crtp.command = c;
  crtp.data1 = d1;
  crtp.data2 = d2;
  crtp.data3 = d3;
  crtp.checksum = crtp.header + crtp.len + crtp.command + crtp.data1 + crtp.data2 + crtp.data3;

  size_t s = sizeof(crtp);
  uint8_t* pt = (uint8_t*)&crtp;
  Serial.write(pt, s);
  Serial.flush();
}

void setup()
{
  lastTimeShitReceived = millis();
  Serial.begin(9600);
  reviveCounter = 0;
  pinMode(PIN_RECEIVE, INPUT_PULLUP);
  irrecv.enableIRIn();
  pinMode(PIN_PIXEL, OUTPUT);
  pinMode(PIN_TRANSMIT, OUTPUT);
  pinMode(PIN_LASER, OUTPUT);

  strip.begin();

  setColor(0,0,255);
  
  digitalWrite(PIN_TRANSMIT, HIGH);
  digitalWrite(PIN_LASER, HIGH);
  strip.show();
  delay(200);
  digitalWrite(PIN_TRANSMIT, LOW);
  digitalWrite(PIN_LASER, LOW);
  setAlive(true);
}

void loop() {
  if (irrecv.decode(&results)) {
    irrecv.resume();
    if (results.decode_type == SONY) {
      if ((results.value & 0xf00) == 0xa00) {
        reviveCounter ++;
        if (reviveCounter >= 5) {
          if(!alive) {
            sendToCrazyflie('r');
          }
          setAlive(true);
          reviveCounter = 0;
        }
      } else if ((results.value & 0xf00) == 0xb00) {
        if(alive) {
          sendToCrazyflie('d', results.value & 0xFF);
        }
        setAlive(false);
        reviveCounter = 0;
      }
    }
  }

/*
  unsigned long now = millis();
  if(now - lastTimeShitReceived < 20) {
    // Ignore
    while(Serial.available())
      Serial.read();
  }

  if(Serial.available()) {
    shoot();
    while(Serial.available())
      Serial.read();
    lastTimeShitReceived = millis();
  }*/
  
  // Read the buffer until \n is in front
  while (Serial.available() >= 2 && Serial.peek() != '\n')
    Serial.read();
  if (Serial.available() >= 2) {
    // We have a \n and a command, let's process
    Serial.read();
    char command = Serial.read();
    if (command == 's') {
      shoot();
    }
  }


  updateColor();
}


void shoot() {
  if(!alive) {
    return;
  }
  digitalWrite(PIN_LASER, HIGH);
  for (int i = 0; i < SHOOT_COUNT; i++) {
    irsend.sendSony(0xb01, 12);
    delay(60);
  }
  digitalWrite(PIN_LASER, LOW);
  for (int i = 0; i < SHOOT_COUNT; i++) {
    irsend.sendSony(0xb01, 12);
    delay(60);
  }
  
  irrecv.enableIRIn();
}

void setAlive(bool a) {
  alive = a;
  updateColor();
}

void updateColor() {
  bool a = alive;
  if (a) {
    setColor(0, 255, 0);
  } else {
    setColor(255, 0, 0);
  }
  strip.show();
  delay(5);
}

void setColor(byte r, byte g, byte b) {
  strip.setPixelColor(0,r,g,b);
}

