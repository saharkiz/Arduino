int sensorPin = A0;   // select the analog input pin for the photoresistor
int threshold = 900;  // analog input trigger level from photoresistor
int sensorValue = 0;  // photoresistor value read from analog input pin

void setup() {
  pinMode(7, OUTPUT); // built-in LED, usually on pin 13
  Serial.begin(9600);
  
}

void loop() {
  Serial.println(analogRead(sensorPin));
  if (analogRead(sensorPin) < threshold) {
    // low light, so switch the light (LED) on
    digitalWrite(7, HIGH);
  }
  else {
    // light level high enough, so switch the light (LED) off
    digitalWrite(7, LOW);
  }
  // wait for ADC to settle before next reading
  delay(20);
}
