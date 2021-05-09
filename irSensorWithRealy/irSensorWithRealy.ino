int sensorPin = 8;
int relayPin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read sensor
  int irState = digitalRead(sensorPin);

  // do something
  if (irState == 0){
    digitalWrite(relayPin, LOW);
  }
  else {
    digitalWrite(relayPin, HIGH);
  }
}
