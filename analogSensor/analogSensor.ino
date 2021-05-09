int sensorPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int lightValue = analogRead(sensorPin);
  Serial.print("Light Intensity: ");
  Serial.println(lightValue);



  int percent = map(lightValue, 0, 1023, 0, 100);
  Serial.print("Light %: ");
  Serial.println(percent);

  Serial.println("----------------------");
  delay(1000);
}
