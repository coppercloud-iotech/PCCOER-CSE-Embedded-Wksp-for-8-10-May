int sensorPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long val = analogRead(sensorPin);
  Serial.println("----");
  Serial.print("Sensor Reading: "); Serial.println(val);
  Serial.print("Temperature (degC): "); Serial.println(val*500/1024);

  if(val > = 45) {
    digitalWrite(relayPin, LOW);
  }
  else {
     digitalWrite(relayPin, HIGH);
  }
  
  delay(1000);
}
