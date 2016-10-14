#include <WS2811.h>


/*
   IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
   An IR LED must be connected to Arduino PWM pin 3.
   Version 0.1 July, 2009
   Copyright 2009 Ken Shirriff
   http://arcfn.com
*/

#include <IRremote.h>

#include <SoftSerial.h>


// Cannot change this, only reminder
#define SERIAL_TX 0
#define PIN_TRANSMIT 1
#define SERIAL_RX 2
#define PIN_RECEIVE 3
#define PIN_PIXEL 4

#define PIXEL_COUNT 1

// Send SHOOT_COUNT often if we want to shoot
#define SHOOT_COUNT 4



SoftSerial crazyflie(SERIAL_RX, SERIAL_TX); // RX, TX
IRsend irsend;
IRrecv irrecv(PIN_RECEIVE);
decode_results results;

DEFINE_WS2811_FN(WS2811RGB, PORTB, PIN_PIXEL)
RGB_t rgb[1];

bool alive;
bool triggerDown;
int reviveCounter;

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
  for (int i = 0; i < s; i++)
    crazyflie.write(*(pt + i));
crazyflie.flush();
}

void setup()
{
  reviveCounter = 0;
  pinMode(PIN_RECEIVE, INPUT);
  irrecv.enableIRIn();
  pinMode(PIN_PIXEL, OUTPUT);
  pinMode(PIN_TRANSMIT, OUTPUT);

  pinMode(SERIAL_RX, INPUT);
  pinMode(SERIAL_TX, OUTPUT);

  crazyflie.begin(9600);

  digitalWrite(1, HIGH);
  delay(200);
  digitalWrite(1, LOW);
  delay(200);
  setAlive(true);
}

void loop() {

  if (irrecv.decode(&results)) {
    irrecv.resume();
    if (results.decode_type == SONY) {
      if ((results.value & 0xf00) == 0xa00) {
        reviveCounter ++;
        if (reviveCounter >= 10) {
          setAlive(true);
          sendToCrazyflie('r');
          reviveCounter = 0;
        }
      } else if ((results.value & 0xf00) == 0xb00) {
        reviveCounter = 0;
        setAlive(false);
        sendToCrazyflie('d', results.value & 0xFF);
      }
    }
  }

  // Read the buffer until \n is in front
  while (crazyflie.available() >= 2 && crazyflie.peek() != '\n')
    crazyflie.read();
  if (crazyflie.available() >= 2) {
    // We have a \n and a command, let's process
    crazyflie.read();
    char command = crazyflie.read();
    if (command == 's') {
      shoot();
      crazyflie.begin(9600);
    }
  }


  updateColor();
}


void shoot() {
  digitalWrite(PIN_TRANSMIT, HIGH);
  delay(100);
  digitalWrite(PIN_TRANSMIT, LOW);
  if(!alive) {
    return;
  }
  for (int i = 0; i < SHOOT_COUNT; i++) {
    irsend.sendSony(0xb01, 12);
    delay(40);
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
  WS2811RGB(rgb, ARRAYLEN(rgb));
  delay(5);
}

void setColor(byte r, byte g, byte b) {
  rgb[0].r = r;
  rgb[0].g = g;
  rgb[0].b = b;
}

