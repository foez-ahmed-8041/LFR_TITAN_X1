void motorWrite(float lm , float rm) {

  lm = constrain(lm, -25, 25);
  rm = constrain(rm, -25, 25);

  inr = inr * 0.9985 + (lm + rm) * 0.0015;

  if (inr > 16  && inr < 16.25)
    digitalWrite(24, HIGH);
  else
    digitalWrite(24, LOW);

  if (lm > 0)
  {
    analogWrite(9, 0);
    lm = lm * 10 * pF;
    lm = (int)lm;
    analogWrite(10, lm);
  }
  else
  {
    analogWrite(10, 0);
    lm = lm * 10 * pF;
    lm = ((int)lm) * -1;
    analogWrite(9, lm);
  }


  if (rm > 0)
  {
    analogWrite(12, 0);
    rm = rm * 10 * pF;
    rm = (int)rm;
    analogWrite(11, rm);
  }
  else
  {
    analogWrite(11, 0);
    rm = rm * 10 * pF;
    rm = ((int)rm) * -1;
    analogWrite(12, rm);
  }
}


void breaks() {
  RED(1);
  digitalWrite(24, HIGH);
  int x = inr;
  if (inr > (10.5 / pFV))
    while (x > 0)
    {
      motorWrite(-25, -25);
      delay(5);
      motorWrite(2, 2);
      delay(5);
      x--;
    }
  inr = 0;
  motorWrite(0, 0);
  RED(0);
}

void moveIR(bool x) { // 0 = normal   1 = maze

  vp1 = vp1 * 0.95 + rp * 0.05;
  vp = (vp1 - vp10) * 10 + vp1;
  vp10 = vp9;
  vp9 = vp8;
  vp8 = vp7;
  vp7 = vp6;
  vp6 = vp5;
  vp5 = vp4;
  vp4 = vp3;
  vp3 = vp2;
  vp2 = vp1;

  if (x == 0)
    vp = constrain(vp, -50, 50);
  else
    vp = constrain(vp, -25, 25);

  vp = (int) vp;

  rx = 25 - vp;
  lx = 25 + vp;

  motorWrite(lx, rx);

}


void TD(float TX) {
  int TTXX = 0;
  while (TTXX < (TX / pFV)) {
    int T2 = 0;
    while (T2 < 120) {
      readLine(0);
      moveIR(0);
      T2++;
    }

    TTXX++;
  }
}





void turnLeft() {
  motorWrite(25, 25);
  delay(800 / pFV);
  breaks();
  motorWrite(-20, 10);
  delay(4000 / pFV);
  motorWrite(20, -10);
  delay(400 / pFV);
  motorWrite(0, 0);
  intcnt();
  readLine(0);
}

void turnRight() {
  motorWrite(25, 25);
  delay(800 / pFV);
  breaks();
  motorWrite(10, -20);
  delay(4000 / pFV);
  motorWrite(-10, 20);
  delay(400 / pFV);
  motorWrite(0, 0);
  intcnt();
  readLine(0);
}

void turnSonarLeft() {
  Serial2.print('r');
  motorWrite(-13, 6);
  while (readPWM(52) > 10)
    delay(1);
  delay(150);
  int Mx48 = 0, Mx50 = 0, Mx4850 = 0;
  while (1)
  {
    Mx48 = 255 - readPWM(48);
    Mx50 = 255 - readPWM(50);
    Mx4850 = abs(Mx50 - Mx48);
    if (Mx4850 < 5 && Mx48 < 200 && Mx50 < 200)
      break;
  }
  motorWrite(13, -6);
  delay(50);
  motorWrite(0, 0);
}

void turnSonarRight() {
  Serial2.print('l');
  motorWrite(6, -13);
  while (readPWM(52) > 10)
    delay(1);
  delay(150);
  int Mx48 = 0, Mx50 = 0, Mx4850 = 0;
  while (1)
  {
    Mx48 = 255 - readPWM(48);
    Mx50 = 255 - readPWM(50);
    Mx4850 = abs(Mx50 - Mx48);
    if (Mx4850 < 5 && Mx48 < 200 && Mx50 < 200)
      break;
  }
  motorWrite(-6, 13);
  delay(50);
  motorWrite(0, 0);
}










// Maze Turns
void takeBack() {

  while (inr < (200 / pFV)) {
    motorWrite(25, 25);
    delayMicroseconds(200);
  }

  setpF();
  breaks();
  motorWrite(20, -25);
  delay(3500 / pFV);
  readLine(1);
  int CCC = 0;
  while (1) {
    readLine(1);
    if ((i2 + i3 + i4 + i5) > 0)
    {
      CCC++;
      if (CCC > (350 / pFV))
        break;
    }
    else CCC = 0;
  }
  motorWrite(-25, 25);
  delay(500 / pFV);
  motorWrite(0, 0);
  int TTXX = 0;
  while (TTXX < (1000 / pFV)) {
    readLine(1);
    moveIR(0);
    TTXX++;
  }
  intcnt();
  GRN(0);
}

void takeStraight() {

  motorWrite(25, 25);
  setpF();
  int TTXX = 0;
  while (TTXX < (1500 / pFV)) {
    readLine(1);
    moveIR(0);
    TTXX++;
  }
  motorWrite(0, 0);
  GRN(0);
  inr = 8;
}

void takeLeft() {

  while (inr < (120 / pFV)) {
    motorWrite(25, 25);
    delayMicroseconds(75);
  }
  setpF();

  motorWrite(-25, 10);
  delay(2200 / pFV);
  readLine(1);
  int CCC = 0;
  while (1) {
    readLine(1);
    if ((i3 + i4) > 0)
    {
      CCC++;
      if (CCC > (350 / pFV))
        break;
    }
    else CCC = 0;
  }
  motorWrite(25, -10);
  delay(250 / pFV);
  int TTXX = 0;
  while (TTXX < (2000 / pFV)) {
    readLine(1);
    moveIR(0);
    TTXX++;
  }
  motorWrite(0, 0);
  inr = 0;
  GRN(0);
}

void takeRight() {

  while (inr < (120 / pFV)) {
    motorWrite(25, 25);
    delayMicroseconds(75);
  }
  setpF();

  motorWrite(10, -25);
  delay(2200 / pFV);
  readLine(1);
  int CCC = 0;
  while (1) {
    readLine(1);
    if ((i3 + i4) > 0)
    {
      CCC++;
      if (CCC > (350 / pFV))
        break;
    }
    else CCC = 0;
  }
  motorWrite(-10, 25);
  delay(250 / pFV);
  int TTXX = 0;
  while (TTXX < (2000 / pFV)) {
    readLine(1);
    moveIR(0);
    TTXX++;
  }
  motorWrite(0, 0);
  inr = 0;
  GRN(0);
}
