
#define Duty_Cycle 56 //in percent (10->50), usually 33 or 50
//TIP for true 50% use a value of 56, because of rounding errors
//TIP for true 40% use a value of 48, because of rounding errors
//TIP for true 33% use a value of 40, because of rounding errors
 
#define Carrier_Frequency 56000 //usually one of 38000, 40000, 36000, 56000, 33000, 30000
 
#define PERIOD (1000000+Carrier_Frequency/2)/Carrier_Frequency
#define HIGHTIME PERIOD*Duty_Cycle/100
#define LOWTIME PERIOD - HIGHTIME
#define txPinIR 8 //IR carrier output

unsigned long sigTime = 0; //use in mark & space functions to keep track of time
 
/*
 * bits 1-4
 * a -> team, b -> player, c -> drone
 * 
 * bits 5-12
 * team-number
 * 
 */
unsigned int code = 0xa01;

void setup() 
{
 pinMode(txPinIR,OUTPUT);
}


void loop() 
{
  sigTime = micros();
  for (int i = 0; i < sizeof(code) / sizeof(code[0]); i++) 
  {
    mark(code[i++]);
    if (i < sizeof(code) / sizeof(code[0])) space(code[i]);
  }
  delay(5000);
}

void mark(unsigned int mLen) { //uses sigTime as end parameter
  sigTime+= mLen; //mark ends at new sigTime
  unsigned long now = micros();
  unsigned long dur = sigTime - now; //allows for rolling time adjustment due to code execution delays
  if (dur == 0) return;
  while ((micros() - now) < dur) { //just wait here until time is up
    digitalWrite(txPinIR, HIGH);
    delayMicroseconds(HIGHTIME - 5);
    digitalWrite(txPinIR, LOW);
    delayMicroseconds(LOWTIME - 6);
  }
}

void space(unsigned int sLen) { //uses sigTime as end parameter
  sigTime+= sLen; //space ends at new sigTime
  unsigned long now = micros();
  unsigned long dur = sigTime - now; //allows for rolling time adjustment due to code execution delays
  if (dur == 0) return;
  while ((micros() - now) < dur) ; //just wait here until time is up
}
