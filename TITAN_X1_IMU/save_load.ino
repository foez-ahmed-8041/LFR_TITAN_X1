
void saveData() {
  int a[3][3];
  if (mo0 < 0)  {
    a[0][0] = 1;
    mo0 = -mo0;
  } else  a[0][0] = 0;
  if (mo1 < 0)  {
    a[1][0] = 1;
    mo1 = -mo1;
  } else  a[1][0] = 0;
  if (mo2 < 0)  {
    a[2][0] = 1;
    mo2 = -mo2;
  } else  a[2][0] = 0;
  a[0][2] = ((int)mo0) % 100;
  a[1][2] = ((int)mo1) % 100;
  a[2][2] = ((int)mo2) % 100;
  a[0][1] = ((int)mo0 - a[0][2]) / 100;
  a[1][1] = ((int)mo1 - a[1][2]) / 100;
  a[2][1] = ((int)mo2 - a[2][2]) / 100;
  EEPROM.write(0, a[0][0]);
  EEPROM.write(1, a[0][1]);
  EEPROM.write(2, a[0][2]);
  EEPROM.write(3, a[1][0]);
  EEPROM.write(4, a[1][1]);
  EEPROM.write(5, a[1][2]);
  EEPROM.write(6, a[2][0]);
  EEPROM.write(7, a[2][1]);
  EEPROM.write(8, a[2][2]);

  mx0 = mx0 * 100;
  mx1 = mx1 * 100;
  mx2 = mx2 * 100;
  int b[3][3];
  if (mx0 < 0)  {
    b[0][0] = 1;
    mx0 = -mx0;
  } else  b[0][0] = 0;
  if (mx1 < 0)  {
    b[1][0] = 1;
    mx1 = -mx1;
  } else  b[1][0] = 0;
  if (mx2 < 0)  {
    b[2][0] = 1;
    mx2 = -mx2;
  } else  b[2][0] = 0;
  b[0][2] = ((int)mx0) % 100;
  b[1][2] = ((int)mx1) % 100;
  b[2][2] = ((int)mx2) % 100;
  b[0][1] = ((int)mx0 - b[0][2]) / 100;
  b[1][1] = ((int)mx1 - b[1][2]) / 100;
  b[2][1] = ((int)mx2 - b[2][2]) / 100;
  EEPROM.write(9, b[0][0]);
  EEPROM.write(10, b[0][1]);
  EEPROM.write(11, b[0][2]);
  EEPROM.write(12, b[1][0]);
  EEPROM.write(13, b[1][1]);
  EEPROM.write(14, b[1][2]);
  EEPROM.write(15, b[2][0]);
  EEPROM.write(16, b[2][1]);
  EEPROM.write(17, b[2][2]);
}

void loadData() {
  int a[3][3];
  a[0][0] = EEPROM.read(0);
  a[0][1] = EEPROM.read(1);
  a[0][2] = EEPROM.read(2);
  a[1][0] = EEPROM.read(3);
  a[1][1] = EEPROM.read(4);
  a[1][2] = EEPROM.read(5);
  a[2][0] = EEPROM.read(6);
  a[2][1] = EEPROM.read(7);
  a[2][2] = EEPROM.read(8);
  mo0 = 100 * a[0][1] + a[0][2];
  mo1 = 100 * a[1][1] + a[1][2];
  mo2 = 100 * a[2][1] + a[2][2];
  if (a[0][0] == 1)mo0 = -mo0;
  if (a[1][0] == 1)mo1 = -mo1;
  if (a[2][0] == 1)mo2 = -mo2;

  int b[3][3];
  b[0][0] = EEPROM.read(9);
  b[0][1] = EEPROM.read(10);
  b[0][2] = EEPROM.read(11);
  b[1][0] = EEPROM.read(12);
  b[1][1] = EEPROM.read(13);
  b[1][2] = EEPROM.read(14);
  b[2][0] = EEPROM.read(15);
  b[2][1] = EEPROM.read(16);
  b[2][2] = EEPROM.read(17);
  mx0 = 100 * b[0][1] + b[0][2];
  mx1 = 100 * b[1][1] + b[1][2];
  mx2 = 100 * b[2][1] + b[2][2];
  if (b[0][0] == 1)mx0 = -mx0;
  if (b[1][0] == 1)mx1 = -mx1;
  if (b[2][0] == 1)mx2 = -mx2;

  
  mx0 = mx0 / 100;
  mx1 = mx1 / 100;
  mx2 = mx2 / 100;
}
