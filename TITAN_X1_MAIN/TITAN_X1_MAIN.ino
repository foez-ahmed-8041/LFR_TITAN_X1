
// Last Updated: 22.09.2019   16:00

// Declares
#include <EEPROM.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(30, 32, 36, 34, 38, 40);


// LCD Bits---------------------------------------------------------------------------
byte b0[8] = {0b01110, 0b11111, 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b11111};
byte b1[8] = {0b01110, 0b11111, 0b10001, 0b10001, 0b10001, 0b10001, 0b10011, 0b11111};
byte b2[8] = {0b01110, 0b11111, 0b10001, 0b10001, 0b10001, 0b10011, 0b10111, 0b11111};
byte b3[8] = {0b01110, 0b11111, 0b10001, 0b10001, 0b10011, 0b10111, 0b11111, 0b11111};
byte b4[8] = {0b01110, 0b11111, 0b10001, 0b10011, 0b10111, 0b11111, 0b11111, 0b11111};
byte b5[8] = {0b01110, 0b11111, 0b10011, 0b10111, 0b11111, 0b11111, 0b11111, 0b11111};
byte b6[8] = {0b01110, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111};
byte b7[8] = {0b11111, 0b10001, 0b10101, 0b10101, 0b10001, 0b10101, 0b10001, 0b11111};


// Functions
int readPWM(int x);
void updateInterface(int k = 0);
void turnLeft();
void turnRight();


int s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, IRL = 0 , IRR = 0;
//  Sensor Compare Match------------------------------------------- Forgot------------

bool i0 = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, lnmd = 0;
//   Sensor Digital Read-------------------------------------------- Line MOde

bool i0p = 0, i1p = 0, i2p = 0, i3p = 0, i4p = 0, i5p = 0, i6p = 0, i7p = 0;
//   Sensor Old Digital Read------------------------------------------------

float lx = 0, rx = 0;
//    Motor register-

char z = 0;
//   Bluetooth 
//   Register-

float rp = 0, vp = 0, vp1 = 0, vp2 = 0, vp3 = 0, vp4 = 0, vp5 = 0, vp6 = 0, vp7 = 0, vp8 = 0, vp9 = 0, vp10 = 0;
//    PID values------------------------------------------------------------------------------------------------

float pF = 1,   inr = 0,   pFV = 0;
//    Power--   Inertia-   Power--- 
//    Factor-   --------   Target--

int pos = 0,   pcl = 0,   bkx = 0, bkx2 = 0,   cld = 0,   cpPointer = 0;
//  Line----   Line----   Break Indexes-----   Break---   Code Pointer--
//  Loss----   Loss----   ------------------   Cool----   --------------
//  Position   Clock---   ------------------   Down----   --------------

byte xF = 0, xRF = 0, xLF = 0, xRB = 0, xLB = 0, xFT = 0;
//   Sonar Serial read-------------------------- FSnBreak-
//                                               Threshold

int Ecnt = 0, Tcnt = 0, Pcnt = 0, Lcnt = 0, Rcnt = 0, Bcnt = 0;
//  Turns counters---------------------------------------------

char MazeSolution[500];
//   Maze register-----

int mazn = 0,   iLFR = 0;
//  Maze-----   LFR------
//  index----   index----








void setup() {

  lnmd = 0;

  lcd.begin(20, 4);
  lcd.createChar(0, b0);
  lcd.createChar(1, b1);
  lcd.createChar(2, b2);
  lcd.createChar(3, b3);
  lcd.createChar(4, b4);
  lcd.createChar(5, b5);
  lcd.createChar(6, b6);
  lcd.createChar(7, b7);

  pinMode(26, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);

  pinMode(42, INPUT);
  pinMode(44, INPUT);
  pinMode(46, INPUT);
  pinMode(48, INPUT);
  pinMode(50, INPUT);
  pinMode(52, INPUT);

  s0 = (EEPROM.read(0) * 4);
  s1 = (EEPROM.read(1) * 4);
  s2 = (EEPROM.read(2) * 4);
  s3 = (EEPROM.read(3) * 4);
  s4 = (EEPROM.read(4) * 4);
  s5 = (EEPROM.read(5) * 4);
  s6 = (EEPROM.read(6) * 4);
  s7 = (EEPROM.read(7) * 4);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);

  pinMode(22, OUTPUT);
  if (digitalRead(26) == 0 && digitalRead(28) == 0)
  {
    //////////////////////////////////////////digitalWrite(22, HIGH);////////////////////////////////////////////////////////////////////////
    digitalWrite(22, HIGH);
    byte bx = 1;
    while (bx < 255)
    {
      BLU(bx);
      delay(5);
      bx++;
    }
    while (bx > 1)
    {
      BLU(bx);
      delay(5);
      bx--;
    }
    BLU(0);
  }
  else
    digitalWrite(22, LOW);

  if (digitalRead(26) == 0 && digitalRead(28) == 1)
  {
    lcd.clear();
    lcd.print(" Serial Ping Denied");
    lcd.setCursor(0, 1);
    byte bx = 1;
    while (bx < 255)
    {
      RED(bx);
      delay(5);
      bx++;
    }
    while (bx > 1)
    {
      RED(bx);
      delay(5);
      bx--;
    }
    RED(0);
  }
  else
  {
    Serial2.begin(2000000);
    Serial3.begin(2000000);
  }

  if (digitalRead(26) == 1 && digitalRead(28) == 0) {
    lcd.clear();
    lcd.print("RESTORING DEFAULT");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    if (digitalRead(26) == 1 && digitalRead(28) == 0)
      EEPROM.write(8, 90);
    else if (digitalRead(26) == 0 && digitalRead(28) == 1)
      EEPROM.write(8, 125);
    else
      EEPROM.write(8, 110);
  }

  pinMode(A5, INPUT_PULLUP);
  pinMode(A6, INPUT_PULLUP);
  pinMode(A7, INPUT_PULLUP);
  pinMode(A8, INPUT_PULLUP);
  pinMode(A9, INPUT_PULLUP);
  pinMode(A10, INPUT_PULLUP);
  pinMode(A11, INPUT_PULLUP);
  pinMode(A12, INPUT_PULLUP);
  pinMode(A4, INPUT);

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(24, OUTPUT);

  homePage();

  rp = 0; vp = 0;

  Serial.begin(9600);

}

int l = 0, ky = 0;

void loop() {

  l++;
  analogWrite(7, (sin(l * 0.0174) * 127 + 128));
  analogWrite(8, (sin(l * 0.0174 + 3.1416) * 127 + 128));

  z = ' ';
  if (Serial.available())
    z = Serial.read();
  else
    delay(10);

  btSys();

  ky = getClick();

  if (ky != 0)
    updateInterface(ky);

}
