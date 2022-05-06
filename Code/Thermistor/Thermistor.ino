/**
 * Copyright (c) 2015 panStamp S.L.U. <contact@panstamp.com>
 * 
 * This file is part of the panStamp project.
 * 
 * panStamp  is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * panStamp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with panStamp; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 
 * USA
 * 
 * Author: Daniel Berenguer
 * Creation date: 06/24/2015
 */
 
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

//Light_ sensor
#define LIGHT  12

void setup()
{
  Serial.begin(9600);
  pinMode(GROW_LEDS,   OUTPUT);
}

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
}
