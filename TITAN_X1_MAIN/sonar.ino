//  TX Commands
//  t -> Serial Print All
//  x -> Only Front
//  a -> All Sonars
//  l -> Front and Left Sonars
//  r -> Front and Right Sonars


int readSonar() {
  Serial2.print('t');
  int k, x;
  k = 0;
  while (!Serial2.available() && k < 1000) k++;
  x = (Serial2.read() - 48) * 100;
  k = 0;
  while (!Serial2.available() && k < 1000) k++;
  x = x + (Serial2.read() - 48) * 10;
  k = 0;
  while (!Serial2.available() && k < 1000) k++;
  x = x + (Serial2.read() - 48);
  if (x > 250)x = 250;
  xF = x;

  k = 0;
  while (!Serial2.available() && k < 1000) k++;
  x = (Serial2.read() - 48) * 100;
  k = 0;
  while (!Serial2.available() && k < 1000) k++;
  x = x + (Serial2.read() - 48) * 10;
  k = 0;
  while (!Serial2.available() && k < 1000) k++;
  x = x + (Serial2.read() - 48);
  if (x > 250)x = 250;
  xRF = x;

  k = 0;
  while (!Serial2.available() && k < 1000) k++;
  x = (Serial2.read() - 48) * 100;
  k = 0;
  while (!Serial2.available() && k < 1000) k++;
  x = x + (Serial2.read() - 48) * 10;
  k = 0;
  while (!Serial2.available() && k < 1000) k++;
  x = x + (Serial2.read() - 48);
  if (x > 250)x = 250;
  xLF = x;

  k = 0;
  while (!Serial2.available() && k < 1000) k++;
  x = (Serial2.read() - 48) * 100;
  k = 0;
  while (!Serial2.available() && k < 1000) k++;
  x = x + (Serial2.read() - 48) * 10;
  k = 0;
  while (!Serial2.available() && k < 1000) k++;
  x = x + (Serial2.read() - 48);
  if (x > 250)x = 250;
  xRB = x;

  k = 0;
  while (!Serial2.available() && k < 1000) k++;
  x = (Serial2.read() - 48) * 100;
  k = 0;
  while (!Serial2.available() && k < 1000) k++;
  x = x + (Serial2.read() - 48) * 10;
  k = 0;
  while (!Serial2.available() && k < 1000) k++;
  x = x + (Serial2.read() - 48);
  if (x > 250)x = 250;
  xLB = x;
}

void sonarDrive() {

  float pfo = pFV;
  pFV = 11;
  setpF();
  Serial2.print('a');

  int  endC = 0;
  while (1)
  {

    readLine(0);

    if (i0 == 1 || i1 == 1 || i2 == 1 || i3 == 1 || i4 == 1 || i5 == 1 || i6 == 1 || i7 == 1) {
      endC++;
      if (endC > 5) {
        endC = 0;
        break;
      }
    }
    else
      endC = 0;

LN96:

    xF = (255 - readPWM(52));
    lx = (255 - readPWM(48));
    rx = (255 - readPWM(50));

    if (lx > 250 && rx < 250) {
      Serial2.print('r');
      goto LN96;
    }

    else if (rx > 250 && lx < 250) {
      Serial2.print('l');
      goto LN96;
    }

    if (Serial2.available())
      if (Serial2.read() == 'A')
        Serial2.print('a');

    lx = lx / 50;
    rx = rx / 50;

    if (xF < xFT)
    {

      Serial2.print('a');

      breaks();

      delay(500);

      lx = 0; rx = 0;
      lx = 2550 - readPWM(48) - readPWM(48) - readPWM(48) - readPWM(48) - readPWM(48) - readPWM(48) - readPWM(48) - readPWM(48) - readPWM(48) - readPWM(48);
      rx = 2550 - readPWM(50) - readPWM(50) - readPWM(50) - readPWM(50) - readPWM(50) - readPWM(50) - readPWM(50) - readPWM(50) - readPWM(50) - readPWM(50);

      if (lx > rx)
        turnSonarLeft();
      else
        turnSonarRight();

        delay(500);

      Serial2.print('a');

    }


    while (lx < 14 && rx < 14)
    {
      rx = rx * 1.1;
      lx = lx * 1.1;
    }

    motorWrite(rx, lx);

  }

  rx = 255; lx = 255;
  pFV = pfo;
  setpF();
}



void crossObstracle() {

  Serial2.print('x');

  while (1)
  {
    readLine(0);

    if (digitalRead(52) == 1) break;

    moveIR(0);
  }

  inr = inr / 2;
  breaks();

  float pfo = pFV;
  pFV = 8;
  setpF();

  while (readPWM(52) < 75)
  {
    readLine(0);
    moveIR(0);
  }

  breaks();
  delay(200);

  pFV = 11;
  setpF();
  turnRight();
  delay(500);

  motorWrite(11, 25);
  delay(800);
  
  int endC = 0;
  while (1) {
    readLine(0);
    if ((i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7) > 1)
    {
      endC++;
      if (endC > 20) {
        endC = 0;
        break;
      }
    }
    else endC = 0;
  }

  breaks();
  turnRight();

  pFV = pfo;
  setpF();
}
