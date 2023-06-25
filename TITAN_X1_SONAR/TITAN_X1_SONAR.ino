void sonarF();
void pri3d(int x);

void setup() {
  pinMode(4, INPUT);
  pinMode(7, OUTPUT);
  pinMode(13, INPUT);
  pinMode(2, OUTPUT);
  pinMode(8, INPUT);
  pinMode(12, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(2000000);
}
int xF = 250, xRF = 250, xLF = 250, xRB = 250, xLB = 250, x = 0, y = 0;
char z;
void loop() {

  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  if (Serial.available()) {
    z = Serial.read();

    if (z == 't')
      SerialS();


    else if (z == 'a') {
      while (z != 'x') {

FUNCA:
        z = 'a';

        if (Serial.available())
          z = Serial.read();

        if (z == 't')
          SerialS();

        if (z == 'l')
          goto FUNCL;

        if (z == 'r')
          goto FUNCR;

        sonarF();
        sonarRF();
        sonarF();
        sonarLF();
        sonarF();
        sonarRB();
        sonarF();
        sonarLB();
        if (xLB < xLF)y = xLB; else y = xLF;
        if (xRB < xRF)x = xRB; else x = xRF;


        if (x > 255)x = 255; else if (x < 0)x = 0;
        if (y > 255)y = 255; else if (y < 0)y = 0;
        analogWrite(10, (255 - x));
        analogWrite(9, (255 - y));

      }
    }

    else if (z == 'r') {
      while (z != 'x') {

FUNCR:
        z = 'r';

        if (Serial.available())
          z = Serial.read();

        if (z == 't')
          SerialS();

        if (z == 'l')
          goto FUNCL;

        if (z == 'a')
          goto FUNCA;

        sonarF();
        sonarRF();
        sonarF();
        sonarLF();
        sonarF();
        sonarRB();
        sonarF();
        sonarLB();
        if ((xLB + xLF) < 500) Serial.print('A');
        y = xRB; x = xRF;
        if (x > 255)x = 255;
        if (y > 255)y = 255;
        analogWrite(10, 255 - x);
        analogWrite(9, 255 - y);
      }
    }

    else if (z == 'l') {
      while (z != 'x') {

FUNCL:
        z = 'l';

        if (Serial.available())
          z = Serial.read();

        if (z == 't')
          SerialS();

        if (z == 'a')
          goto FUNCA;

        if (z == 'r')
          goto FUNCR;

        sonarF();
        sonarRF();
        sonarF();
        sonarLF();
        sonarF();
        sonarRB();
        sonarF();
        sonarLB();
        if ((xRB + xRF) < 500) Serial.print('A');
        y = xLF; x = xLB;
        if (x > 255)x = 255;
        if (y > 255)y = 255;
        analogWrite(10, 255 - x);
        analogWrite(9, 255 - y);
      }
    }
  }
  sonarF();
  delay(1);

}
