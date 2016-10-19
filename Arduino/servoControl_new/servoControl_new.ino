#include <Servo.h>

#define MAX_YAW 180
#define MIN_YAW 0
#define MAX_PITCH 90
#define MIN_PITCH 0

int eulX, eulY, eulZ;
int yaw, pitch;

String eulers;

Servo servoBase, servoTower;  // create servo object to control a servo

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  servoBase.attach(8);  // attaches the servo on pin 9 to the servo object
//  servo1.write(0);
  servoTower.attach(12);  // attaches second servo on pin 11
  servoBase.write(0);
  servoTower.write(0);
  delay(500);
}

void loop() {
  if (Serial.available() > 0)
  {
    if(Serial.read() == 's')
      moveTurret();
  }


}

void moveTurret()
{
      eulX = Serial.parseInt();
      eulY = Serial.parseInt();
      eulZ = Serial.parseInt();

      if (eulX >= 90 && eulX < 180)
        pitch = 180-eulX;
      else if(eulX < -90)
        pitch = MIN_PITCH;
      else if(eulX < 90)
        pitch = MAX_PITCH;

      if (eulY <= 0 && eulY >= -180)
        yaw = abs(eulY);
      else if(eulY > 90)
        yaw = MAX_YAW;
      else if(eulY > 0)
        yaw = MIN_YAW;
//
      servoBase.write(yaw);
      servoTower.write(pitch);
}


void checkLED()
{
  if(digitalRead(LED_BUILTIN) == HIGH);
    digitalWrite(LED_BUILTIN,LOW);
  if(digitalRead(LED_BUILTIN) == LOW);
    digitalWrite(LED_BUILTIN,HIGH);

}

