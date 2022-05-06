     
 //////////////////Thermistor//////////////
#include "thermistor.h"
#include "HardwareSerial.h"

// Analog pin used to read the NTC
#define NTC_PIN    A0
#define GROW_LEDS  A2

// Thermistor object
THERMISTOR thermistor(NTC_PIN,        // Analog pin
                      10000,          // Nominal resistance at 25 ºC
                      3950,           // thermistor's beta coefficient
                      10000);         // Value of the series resistor

// Global temperature reading
uint16_t temp;

//////////////////////Light_ sensor/////////////////////////
#define LIGHT  12

/////////////////// Init Air Pump Timer ///////////////////

// Pump Test
const long AirpumpInterval = 10000;
const long AirpumpRuntime = 2000;

//PUMP RUNNING
//const long AirpumpInterval = 3600000;
//const long AirpumpRuntime = 300000;

unsigned long lastTimePumpStart = 0;

int Relay = 13;

/////////////////////Peristaltic Pump///////////////

// Pump Test
const long LiquidInterval = 10000;
const long LiquidRuntime = 2000;

//PUMP RUNNING
//const long LiquidInterval = 3600000;
//const long LiquidRuntime = 300000;

unsigned long lastTimeLiquidPumpStart = 0;


int Mosfet = 33;


void setup(){
  Serial.begin(9600);
  pinMode(Relay,OUTPUT);
  pinMode(GROW_LEDS, OUTPUT);
  digitalWrite(Relay, HIGH);
  digitalWrite(Mosfet, HIGH);
 } 
  /////////////
  
 

void loop()
{
  temp = thermistor.read();   // Read temperature
  Serial.print("Temp in 1/10 ºC : ");
  Serial.println(temp);

if (temp>200) {
digitalWrite(GROW_LEDS,   LOW);;
  
}else{
digitalWrite(GROW_LEDS,   HIGH);;
  
};

int analogValue = analogRead(LIGHT);

  Serial.print("Analog Value = ");
  Serial.print(analogValue);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (analogValue < 40) {
    Serial.println(" => Dark");
  } else if (analogValue < 800) {
    Serial.println(" => Dim");
  } else if (analogValue < 2000) {
    Serial.println(" => Light");
  } else if (analogValue < 3200) {
    Serial.println(" => Bright");
  } else {
    Serial.println(" => Very bright");
  }

  delay(2000);

  //Pump Control
  if (millis() - lastTimePumpStart >= AirpumpInterval) {
    lastTimePumpStart = millis();
    digitalWrite(Relay,HIGH);
  }

  if (millis() - lastTimePumpStart >= AirpumpRuntime) {
   digitalWrite(Relay,LOW);
  };

    //Peristaltic Pump Control
  if (millis() - lastTimeLiquidPumpStart >= LiquidInterval) {
    lastTimePumpStart = millis();
    digitalWrite(Mosfet,HIGH);
  }

  if (millis() - lastTimeLiquidPumpStart >= LiquidRuntime) {
   digitalWrite(Mosfet,LOW);
  };

}
