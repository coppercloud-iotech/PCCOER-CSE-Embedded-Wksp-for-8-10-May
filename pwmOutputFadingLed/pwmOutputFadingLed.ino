int ledPin = 9;    // LED connected to digital pin 9

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int fadeValue=0; fadeValue<=255; fadeValue+=5) {
    analogWrite(ledPin, fadeValue);
    delay(50);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255; fadeValue>=0; fadeValue-=5) {
    analogWrite(ledPin, fadeValue);
    delay(50);
  }
}
