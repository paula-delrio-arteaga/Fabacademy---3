
//////////////////Thermistor//////////////
#include "thermistor.h"
#include "HardwareSerial.h"

// Analog pin used to read the NTC
#define NTC_PIN    A7
#define GROW_LEDS  A2

// Thermistor object
THERMISTOR thermistor(NTC_PIN,        // Analog pin
                      10000,          // Nominal resistance at 25 ºC
                      3950,           // thermistor's beta coefficient
                      10000);         // Value of the series resistor

// Global temperature reading
uint16_t temp;

//////////////////////Light_ sensor/////////////////////////
#define LIGHT  A9

/////////////////// Init Air Pump Timer ///////////////////

// Pump Test
const long AirpumpInterval = 10000;
const long AirpumpRuntime = 2000;

//PUMP RUNNING
//const long AirpumpInterval = 3600000;
//const long AirpumpRuntime = 300000;

unsigned long lastTimePumpStart = 0;
unsigned long lastTimePumpStop = 0;

int Relay = 19;
int Mosfet = 13;
boolean IsPumpOn = true;
/////////////////////Peristaltic Pump///////////////

// Pump Test
//const long LiquidInterval = 10000;
//const long LiquidRuntime = 2000;

//PUMP RUNNING
//const long LiquidInterval = 3600000;
//const long LiquidRuntime = 300000;

//unsigned long lastTimeLiquidPumpStart = 0;


float temp1;

String LightText = "";
String TempText = "";
String Temperature;

#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>

/*Put your SSID & Password*/
const char* ssid = "Iaac-Wifi";  // Enter SSID here
const char* password = "EnterIaac22@";  //Enter Password here

WebServer server(80);

void setup() {
  Serial.begin(9600);
  pinMode(Relay, OUTPUT);
  pinMode(Mosfet, OUTPUT);
  pinMode(GROW_LEDS, OUTPUT);

  /////////////////////////////////


  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
  digitalWrite(Relay, HIGH);
  lastTimePumpStart = millis();
  digitalWrite(Mosfet, HIGH);
}


void loop()
{
  server.handleClient();

  temp = thermistor.read();   // Read temperature
  Serial.print("Temp in 1/10 ºC : ");
  Serial.println(temp);
  temp1 = temp * 0.1;
  Serial.print(temp1);
  TempText = "Temp in 1/10 ºC : " ;

  if (temp > 200) {
    digitalWrite(GROW_LEDS,   LOW);;

  } else {
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

  if (analogValue < 40) {
    LightText = "Dark" ;
  } else if (analogValue < 800) {
    LightText = "Dim" ;
  } else if (analogValue < 2000) {
    LightText = "Light" ;
  } else if (analogValue < 3200) {
    LightText = "Bright" ;
  } else {
    LightText = "Very Bright" ;
  }

  delay(2000);

  ////////////////////Pumps contro
  if (IsPumpOn && (millis() - lastTimePumpStart >= AirpumpRuntime)) {
    digitalWrite(Relay, LOW);
    digitalWrite(Mosfet, LOW);
    IsPumpOn = false;
    lastTimePumpStop = millis();
    Serial.println("Turning pump off");
  } else if (!IsPumpOn && (millis() - lastTimePumpStop >= AirpumpInterval)) {
    digitalWrite(Relay, HIGH);
    digitalWrite(Mosfet, HIGH);
    IsPumpOn = true;
    Serial.println("Turning pump on");
    lastTimePumpStart = millis();
  }

}

void handle_OnConnect() {
  //Temperature = thermistor.read();
  //Light = analogRead(LIGHT);

  server.send(200, "text/html", SendHTML(LightText, temp1));
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}

String SendHTML( String LightText, float temp1) {
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<meta http-equiv='Refresh' content='3'>";
  ptr += "<title>Spirulina Station</title>\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 100px;} h1 {color: #164719;font-size: 60px; margin: 50px auto 30px;}\n";
  ptr += "p {font-size: 40px;color: #164719;margin-bottom: 10px;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<div id=\"webpage\">\n";
  ptr += "<h1>Spirulina Station</h1>\n";
  ptr += "<p>Temperature: ";
  ptr += temp1;
  ptr += "&deg;C</p>";
  ptr += "<p>Light: ";
  ptr += LightText;
  ptr += "</p>";
  ptr += "</div>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}
