void setup() {
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
}

void loop() {
  int val = digitalRead(7);
  int val2 = digitalRead(6);
  int val3 = digitalRead(5);
  int val4 = digitalRead(4);
  if (val == LOW) {
      analogWrite(3, 255);
  delay(1000);
  }
  if (val2 == LOW) {
     analogWrite(3, 191);
  delay(1000);
  }
  if (val3 == LOW) {
    analogWrite(3, 127);
  delay(1000);
  }
  if (val4 == LOW) {
    analogWrite(3, 64);
  delay(1000);
  }
}
