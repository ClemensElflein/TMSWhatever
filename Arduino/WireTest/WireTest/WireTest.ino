#include <Wire.h>

#define MY_ADDR 8
void setup() {
  pinMode(13, OUTPUT);
  Wire.begin(MY_ADDR);
  digitalWrite(13, HIGH);
  Serial.begin(9600);
  while(!Serial);
  digitalWrite(13, LOW);
  Wire.onReceive(i2crec);
}

void loop() {
  delay(1000);
  Serial.print("alive\r\n");
}

void i2crec(int bytes) {
  while(Wire.available() > 0) {
    int i = Wire.read();
    Serial.print(i);
  }
  Serial.println("done");
}

