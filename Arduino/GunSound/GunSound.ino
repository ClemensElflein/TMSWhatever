
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <WiFiUdp.h>
const char* ssid = "PLAY_DRONETAG";
const char* password = "DRONETAGROCKS";

WiFiUDP udp;

#define PIN_SOUND1 D2
#define PIN_SOUND2 D3
#define PIN_SOUND3 D4
#define PIN_SOUND4 D5
#define PIN_SOUND5 D6

#define PLAYER_ID 1

struct __attribute__((packed)) {
  uint32_t id;
  uint8_t playerID;
  uint8_t soundID;
} soundStruct;

void playSound(uint8_t sound) {
  soundStruct.id++;
  soundStruct.soundID = sound;

  Serial.print("Playing Sound:");
  Serial.println(sound);

IPAddress ip(192,168,1,2);
  udp.beginPacket(ip, 12345);
  udp.write((byte*)&soundStruct, sizeof(soundStruct));
  udp.endPacket();
}

void setup() {
  Serial.begin(115200);
  soundStruct.id = 0;
  soundStruct.playerID = PLAYER_ID;

  
  pinMode(PIN_SOUND1, INPUT_PULLUP);
  pinMode(PIN_SOUND2, INPUT_PULLUP);
  pinMode(PIN_SOUND3, INPUT_PULLUP);
  pinMode(PIN_SOUND4, INPUT_PULLUP);
  pinMode(PIN_SOUND5, INPUT_PULLUP);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  bool state = 1;
  
  Serial.print("Connecting");
  /*while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    digitalWrite(LED_BUILTIN, state);
    state = !state;
    delay(100);
  }
  Serial.println(".. done!");
*/
  // Setup OTA
  ArduinoOTA.begin();
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  attachInterrupt(PIN_SOUND1, playSound1, RISING);
  attachInterrupt(PIN_SOUND2, playSound2, RISING);
  attachInterrupt(PIN_SOUND3, playSound3, RISING);
  attachInterrupt(PIN_SOUND4, playSound4, RISING);
  attachInterrupt(PIN_SOUND5, playSound5, RISING);
  
}

void playSound1() {
  playSound(1);
}
void playSound2() {
  playSound(2);
}
void playSound3() {
  playSound(3);
}
void playSound4() {
  playSound(4);
}
void playSound5() {
  playSound(5);
}

void loop() {
/*  bool S1 = digitalRead(PIN_SOUND1);
  //bool S2= digitalRead(PIN_SOUND2);
  bool S3 = digitalRead(PIN_SOUND3);

  if(S1 && !lastS1) 
    playSound(1);
  //if(S2 && !lastS2)
  //  playSound(2);
  if(S3 && !lastS3)
    playSound(3);

  lastS1 = S1;
  //lastS2 = S2;
  lastS3 = S3;*/
  digitalWrite(LED_BUILTIN, WiFi.status() == WL_CONNECTED);
  ArduinoOTA.handle();
}
