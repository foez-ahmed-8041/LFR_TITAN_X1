void SerialS() {
  sonarRF();
  sonarLF();
  sonarF();
  sonarRB();
  sonarLB();
  pri3d(xF);
  pri3d(xRF);
  pri3d(xLF);
  pri3d(xRB);
  pri3d(xLB);
  z = ' ';
}

void sonarF() {
  int x;
  digitalWrite(7, LOW);
  delayMicroseconds(2);
  digitalWrite(7, HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);
  x = pulseIn(4, HIGH, 2500);
  if (x == 0) x = 2500;
  xF = xF * 2.8571 + (x - 115) * 0.5;
  //xF = (x - 115);
  //        0.5 / 0.175       
  xF = xF * 0.175;
  if (xF < 250) {
    analogWrite(11, 255 - xF);
  }
  else
    digitalWrite(11, LOW);
}

void sonarRF() {
  int x;
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  x = pulseIn(8, HIGH, 2500);
  if (x == 0) x = 2500;
  xRF = (x - 200);
  xRF = xRF * 0.175;
}

void sonarLF() {
  int x;
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  x = pulseIn(13, HIGH, 2500);
  if (x == 0) x = 2500;
  xLF = (x - 200);
  xLF = xLF * 0.175;
}



void sonarRB() {
  int x;
  digitalWrite(A1, LOW);
  delayMicroseconds(2);
  digitalWrite(A1, HIGH);
  delayMicroseconds(10);
  digitalWrite(A1, LOW);
  x = pulseIn(A0, HIGH, 2500);
  if (x == 0) x = 2500;
  xRB = (x - 70);
  xRB = xRB * 0.175;
}

void sonarLB() {
  int x;
  digitalWrite(A3, LOW);
  delayMicroseconds(2);
  digitalWrite(A3, HIGH);
  delayMicroseconds(10);
  digitalWrite(A3, LOW);
  x = pulseIn(A2, HIGH, 2500);
  if (x == 0) x = 2500;
  xLB = (x - 70);
  xLB = xLB * 0.175;
}

void pri3d(int x) {
  if (x < 9) {
    Serial.print('0');
    Serial.print('0');
    Serial.print(x);
  }
  else if (x < 99) {
    Serial.print('0');
    Serial.print(x);
  }
  else {
    Serial.print(x);
  }
}

