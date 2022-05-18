//1.1///////////////// Init Pump Timer ///////////////////

// Pump Test
const long pumpInterval = 10000;
const long pumpRuntime = 2000;

//PUMP RUNNING
//const long pumpInterval = 3600000;
//const long pumpRuntime = 300000;

unsigned long lastTimePumpStart = 0;

int Relay = 13;

int statusIndicatorLED = 27; // Status LED


void setup() {

  pinMode(Relay,OUTPUT); // Set Relay Output
  
  pinMode(statusIndicatorLED,OUTPUT); // Set Indicator LED Output

  ///////////////////
  
  Serial.begin(115200);
  Serial.println("Setup finished");
}


void loop() {

//Pump Control
  if (millis() - lastTimePumpStart >= pumpInterval) {
    lastTimePumpStart = millis();
    digitalWrite(Relay,HIGH);
    digitalWrite(statusIndicatorLED, HIGH); // Indicating Pump Start
  }

  if (millis() - lastTimePumpStart >= pumpRuntime) {
   digitalWrite(Relay,LOW);
   digitalWrite(statusIndicatorLED, LOW); // Indicating Pump Finish
  }

}
