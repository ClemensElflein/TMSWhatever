/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 0); // RX, TX
bool state;


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
  crtp.checksum = crtp.header+crtp.len+crtp.command+crtp.data1+crtp.data2+crtp.data3;

  mySerial.write((uint8_t*)&crtp, sizeof(crtp));
}

void setup()
{
  state = 0;
  pinMode(1, OUTPUT);
  pinMode(2, INPUT);
  pinMode(0, OUTPUT);
  // set the data rate for the SoftwareSerial port
  mySerial.begin(115200);
  
  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(1, LOW);
  delay(100);
}

void loop() // run over and over
{
  /*if (mySerial.available()) {
    mySerial.read();
    digitalWrite(1, state);
    state = !state;
    delay(50);
  }*/

  delay(500);
  sendToCrazyflie('s', 1);
    digitalWrite(1, state);
    state = !state;
  
  
}

