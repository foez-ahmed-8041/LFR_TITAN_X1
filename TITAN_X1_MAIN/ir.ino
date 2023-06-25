void calibrateLine() {

  int mx0 = 0, mx1 = 0, mx2 = 0, mx3 = 0, mx4 = 0, mx5 = 0, mx6 = 0, mx7 = 0;
  int mn0 = 1023, mn1 = 1023, mn2 = 1023, mn3 = 1023, mn4 = 1023, mn5 = 1023, mn6 = 1023, mn7 = 1023;
  int x = 0;

  x = 0;
  motorWrite(8, -15);
  delay(1000);
  while (x < 15000)
  {
    s0 = analogRead(A8);
    s1 = analogRead(A7);
    s2 = analogRead(A6);
    s3 = analogRead(A5);
    s4 = analogRead(A12);
    s5 = analogRead(A11);
    s6 = analogRead(A10);
    s7 = analogRead(A9);

    if (s0 < mn0) mn0 = s0;
    if (s1 < mn1) mn1 = s1;
    if (s2 < mn2) mn2 = s2;
    if (s3 < mn3) mn3 = s3;
    if (s4 < mn4) mn4 = s4;
    if (s5 < mn5) mn5 = s5;
    if (s6 < mn6) mn6 = s6;
    if (s7 < mn7) mn7 = s7;

    if (s0 > mx0) mx0 = s0;
    if (s1 > mx1) mx1 = s1;
    if (s2 > mx2) mx2 = s2;
    if (s3 > mx3) mx3 = s3;
    if (s4 > mx4) mx4 = s4;
    if (s5 > mx5) mx5 = s5;
    if (s6 > mx6) mx6 = s6;
    if (s7 > mx7) mx7 = s7;

    x++;
    if (x == 7500) {
      motorWrite(-15, 8);
      delay(1000);
    }
  }

  motorWrite(0, 0);

  s0 = mn0 * 0.5 + mx0 * 0.5;
  s1 = mn1 * 0.5 + mx1 * 0.5;
  s2 = mn2 * 0.5 + mx2 * 0.5;
  s3 = mn3 * 0.5 + mx3 * 0.5;
  s4 = mn4 * 0.5 + mx4 * 0.5;
  s5 = mn5 * 0.5 + mx5 * 0.5;
  s6 = mn6 * 0.5 + mx6 * 0.5;
  s7 = mn7 * 0.5 + mx7 * 0.5;

  EEPROM.write(0, (s0 / 4));
  EEPROM.write(1, (s1 / 4));
  EEPROM.write(2, (s2 / 4));
  EEPROM.write(3, (s3 / 4));
  EEPROM.write(4, (s4 / 4));
  EEPROM.write(5, (s5 / 4));
  EEPROM.write(6, (s6 / 4));
  EEPROM.write(7, (s7 / 4));

  Serial.println("Sensor Reads L-R");
  Serial.print(mx0 - mn0);  Serial.print(" ");  Serial.print(mn0);  Serial.print(" - ");  Serial.println(mx0);
  Serial.print(mx1 - mn1);  Serial.print(" ");  Serial.print(mn1);  Serial.print(" - ");  Serial.println(mx1);
  Serial.print(mx2 - mn2);  Serial.print(" ");  Serial.print(mn2);  Serial.print(" - ");  Serial.println(mx2);
  Serial.print(mx3 - mn3);  Serial.print(" ");  Serial.print(mn3);  Serial.print(" - ");  Serial.println(mx3);
  Serial.print(mx4 - mn4);  Serial.print(" ");  Serial.print(mn4);  Serial.print(" - ");  Serial.println(mx4);
  Serial.print(mx5 - mn5);  Serial.print(" ");  Serial.print(mn5);  Serial.print(" - ");  Serial.println(mx5);
  Serial.print(mx6 - mn6);  Serial.print(" ");  Serial.print(mn6);  Serial.print(" - ");  Serial.println(mx6);
  Serial.print(mx7 - mn7);  Serial.print(" ");  Serial.print(mn7);  Serial.print(" - ");  Serial.println(mx7);

  lcd.clear();
  lcd.setCursor(3, 0);  lcd.print(mx3 - mn3);  lcd.setCursor(14, 0);  lcd.print(mx4 - mn4);
  lcd.setCursor(3, 1);  lcd.print(mx2 - mn2);  lcd.setCursor(14, 1);  lcd.print(mx5 - mn5);
  lcd.setCursor(3, 2);  lcd.print(mx1 - mn1);  lcd.setCursor(14, 2);  lcd.print(mx6 - mn6);
  lcd.setCursor(3, 3);  lcd.print(mx0 - mn0);  lcd.setCursor(14, 3);  lcd.print(mx7 - mn7);

}

void readLine(bool x) { // 0 = normal   1 = maze

  if (analogRead(A8)  > s0)  i0 = 1; else i0 = 0;
  if (analogRead(A7) > s1)   i1 = 1; else i1 = 0;
  if (analogRead(A6) > s2)   i2 = 1; else i2 = 0;
  if (analogRead(A5) > s3)   i3 = 1; else i3 = 0;
  if (analogRead(A12) > s4)  i4 = 1; else i4 = 0;
  if (analogRead(A11) > s5)  i5 = 1; else i5 = 0;
  if (analogRead(A10) > s6)  i6 = 1; else i6 = 0;
  if (analogRead(A9)  > s7)  i7 = 1; else i7 = 0;

  if (lnmd == 1)
  {
    i0 = 1 - i0;
    i1 = 1 - i1;
    i2 = 1 - i2;
    i3 = 1 - i3;
    i4 = 1 - i4;
    i5 = 1 - i5;
    i6 = 1 - i6;
    i7 = 1 - i7;
  }

  i0p = i0; i1p = i1; i2p = i2; i3p = i3; i4p = i4; i5p = i5; i6p = i6; i7p = i7;

  if (x == 1) goto RTX;

  if (i0 == 0 && i1 == 0 && i7 == 1) {
    pos = 1;
    pcl = 3000 / pFV;
    bkx = 0;
    bkx2 = 1;
    BLU(1);
  }

  else if (i0 == 1 && i6 == 0 && i7 == 0) {
    pos = -1;
    pcl = 3000 / pFV;
    bkx = 0;
    bkx2 = 1;
    BLU(1);
  }

  else
  {
    if (pcl > 0) {
      if (i0 == 0 && i1 == 0 && ( i2 == 1 || i3 == 1 || i4 == 1 || i5 == 1 ) && i6 == 0 && i7 == 0)
        pcl--;
      if (pcl == 0)
      {
        pos = 0;
        pcl = 0;
        bkx = 0;
        bkx2 = 0;
        BLU(0);
        setpF();
      }
    }
  }

  if ((i0p + i1p + i2p + i3p + i4p + i5p + i6p + i7p) == 0)
  {
    rp = 0;
    cld++;
    if (cld > (250 / pFV)) {

      if (pos == 1) {
        rp = 50;
        bkx++;
        if (bkx > (120 / pFV) && bkx2 == 1) {
          breaks();
          bkx2 = 0;
        }
      }
      else if (pos == -1) {
        rp = -50;
        bkx++;
        if (bkx > (120 / pFV) && bkx2 == 1) {
          breaks();
          bkx2 = 0;
        }
      }
      else {
        rp = 0;
        bkx = 0;
        bkx2 = 0;
      }

    }

  }
  else {

RTX:

    cld = 0;
    if (i3p == 1 && i4p == 1) {
      i3p = i2p; i4p = i5p;
      i2p = i1p; i5p = i6p;
      i1p = i0p; i6p = i7p;
      i0p = 0;  i7p = 0;
      goto RTX;
    }
    else if (i3p == 0 && i4p == 1 && i5p == 0) rp =    5;
    else if (i3p == 1 && i4p == 0 && i2p == 0) rp =   -5;
    else if (i3p == 0 && i4p == 1 && i5p == 1) rp =   15;
    else if (i3p == 1 && i4p == 0 && i2p == 1) rp =  -15;
    else if (i3p == 0 && i4p == 1)             rp =   10;
    else if (i3p == 1 && i4p == 0)             rp =  -10;
    else if (i2p == 0 && i5p == 1 && i6p == 1) rp =   25;
    else if (i2p == 1 && i5p == 0 && i1p == 1) rp =  -25;
    else if (i2p == 0 && i5p == 1)             rp =   20;
    else if (i2p == 1 && i5p == 0)             rp =  -20;
    else if (i1p == 0 && i6p == 1 && i7p == 1) rp =   38;
    else if (i1p == 1 && i6p == 0 && i0p == 1) rp =  -38;
    else if (i1p == 0 && i6p == 1)             rp =   30;
    else if (i1p == 1 && i6p == 0)             rp =  -30;
    else if (i0p == 0 && i7p == 1)             rp =   45;
    else if (i0p == 1 && i7p == 0)             rp =  -45;
    else                                       rp =    0;
  }


}
