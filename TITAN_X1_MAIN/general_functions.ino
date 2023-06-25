void intcnt() {
  Ecnt = 0; Tcnt = 0; Pcnt = 0; Lcnt = 0; Rcnt = 0; Bcnt = 0;
  rp = 0; vp = 0; vp1 = 0; vp2 = 0; vp3 = 0; vp4 = 0; vp5 = 0; vp6 = 0; vp7 = 0; vp8 = 0; vp9 = 0; vp10 = 0;
}

void RED(int x)
{
  if (x == 1)
    digitalWrite(6, HIGH);
  else if (x > 1 && x < 256)
    analogWrite(6, x);
  else
    digitalWrite(6, LOW);
}

void GRN(int x)
{
  if (x == 1)
    digitalWrite(7, HIGH);
  else if (x > 1 && x < 256)
    analogWrite(7, x);
  else
    digitalWrite(7, LOW);
}

void BLU(int x)
{
  if (x == 1)
    digitalWrite(8, HIGH);
  else if (x > 1 && x < 256)
    analogWrite(8, x);
  else
    digitalWrite(8, LOW);
}

void setpF() {
  if (pFV != 0)
    pF = pFV / getVolts();
  else
    pF = 1;
}

float getVolts() {
  float x =  analogRead(A4);
  x = x / 51.71;
  return x;
}

void printVolts() {
  float x = getVolts();
  x = (x - 14.8) * 50;
  if (x > 85.71) lcd.write(byte(6));
  else if (x > 71.4) lcd.write(byte(5));
  else if (x > 57.1) lcd.write(byte(4));
  else if (x > 42.8) lcd.write(byte(3));
  else if (x > 28.6) lcd.write(byte(2));
  else if (x > 14.2) lcd.write(byte(1));
  else lcd.write(byte(0));

}

int readPWM(int x) {
  long int a, b;
  a = pulseIn(x, LOW, 10000);
  b = pulseIn(x, HIGH, 10000);
  if (a == 0 && b == 0) {
    if (digitalRead(x) == 1) x = 255;
    else x = 0;
  }
  else
    x = ((255 * b) / (a + b - 2));
  return x;
}



int getClick() {
  int t = 0, v = 0;

  if (digitalRead(26) == LOW)
  {
    RED(25);
    GRN(25);
    BLU(25);
    while (digitalRead(26) == LOW && t < 3000)
    {
      t++;
      if (t == 350) {
        motorWrite(-25, -25);
        delay(5);
        motorWrite(25, 25);
        delay(5);
        motorWrite(0, 0);
      }
      if (t > 350) {
        RED(250);
      }
      delay(1);
    }
    if (t < 350 && t > 25) v = 2;
    else if (t > 350) v = 1;
    RED(0);
    GRN(0);
    BLU(0);
  }

  else if (digitalRead(28) == LOW)
  {
    RED(25);
    GRN(25);
    BLU(25);
    while (digitalRead(28) == LOW && t < 3000)
    {
      t++;
      if (t == 350) {
        motorWrite(-25, -25);
        delay(5);
        motorWrite(25, 25);
        delay(5);
        motorWrite(0, 0);
      }
      if (t > 350) {
        GRN(250);
      }
      delay(1);
    }
    if (t < 350 && t > 25) v = 3;
    else if (t > 350) v = 4;
    RED(0);
    GRN(0);
    BLU(0);
  }

  while (digitalRead(26) == 0 || digitalRead(28) == 0)
    delay(1);

  delay(1);
  return v;
}
