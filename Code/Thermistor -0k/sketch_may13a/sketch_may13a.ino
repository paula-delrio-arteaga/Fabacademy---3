void setup() {
  // put your setup code here, to run once:
  pinMode(A7, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int tempReading = analogRead(A7);
  // This is OK
  double tempK = log(10000.0 * ((4095.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
  float tempC = tempK - 273.15;            // Convert Kelvin to Celcius
  Serial.print( "T = " );
  Serial.print( tempC, 1 );
  Serial.print( "     " );
  Serial.println( tempReading );
  delay(500);
}
