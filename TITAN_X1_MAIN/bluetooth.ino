char z2 = ' ';
void btSys() {

  if (z == 'F')
  {
    lx = lx * 0.5 + 0.5 * 25;  rx = rx * 0.5 + 0.5 * 25;
    motorWrite(lx, rx);
    if (z2 != 'F') {
      z2 = z;
      digitalWrite(24, HIGH);
    }
    delay(10);
    digitalWrite(24, LOW);
    delay(90);
  }
  else if (z == 'B')
  {
    lx = lx * 0.75 + 0.25 * -25;  rx = rx * 0.75 + 0.25 * -25;
    motorWrite(lx, rx);
    if (z2 != 'B') {
      z2 = z;
      digitalWrite(24, HIGH);
    }
    delay(10);
    digitalWrite(24, LOW);
    delay(90);
  }
  else if (z == 'L')
  {
    lx = lx * 0.75 + 0.25 * -25;  rx = rx * 0.75 + 0.25 * 25;
    motorWrite(lx, rx);
    if (z2 != 'L') {
      z2 = z;
      digitalWrite(24, HIGH);
    }
    delay(10);
    digitalWrite(24, LOW);
    delay(90);
  }
  else if (z == 'R')
  {
    lx = lx * 0.75 + 0.25 * 25;  rx = rx * 0.75 + 0.25 * -25;
    motorWrite(lx, rx);
    if (z2 != 'R') {
      z2 = z;
      digitalWrite(24, HIGH);
    }
    delay(10);
    digitalWrite(24, LOW);
    delay(90);
  }
  else if (z == 'G')
  {
    lx = lx * 0.25 + 0.75 * 2;  rx = rx * 0.25 + 0.75 * 25;
    motorWrite(lx, rx);
    if (z2 != 'G') {
      z2 = z;
      digitalWrite(24, HIGH);
    }
    delay(10);
    digitalWrite(24, LOW);
    delay(90);
  }
  else if (z == 'I')
  {
    lx = lx * 0.25 + 0.75 * 25;  rx = rx * 0.25 + 0.75 * 2;
    motorWrite(lx, rx);
    if (z2 != 'I') {
      z2 = z;
      digitalWrite(24, HIGH);
    }
    delay(10);
    digitalWrite(24, LOW);
    delay(90);
  }
  else if (z == 'H')
  {
    lx = lx * 0.75 + 0.25 * -2;  rx = rx * 0.75 + 0.25 * -25;
    motorWrite(lx, rx);
    if (z2 != 'H') {
      z2 = z;
      digitalWrite(24, HIGH);
    }
    delay(10);
    digitalWrite(24, LOW);
    delay(90);
  }
  else if (z == 'J')
  {
    lx = lx * 0.75 + 0.25 * -25;  rx = rx * 0.75 + 0.25 * -2;
    motorWrite(lx, rx);
    if (z2 != 'J') {
      z2 = z;
      digitalWrite(24, HIGH);
    }
    delay(10);
    digitalWrite(24, LOW);
    delay(90);
  }
  else
  {
    lx = 0;  rx = 0;
    motorWrite(lx, rx);
    if (z2 != 'O')
      z2 = 'O';
  }

}
