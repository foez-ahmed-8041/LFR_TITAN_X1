#include <Wire.h>
#include <EEPROM.h>
#include "MPU9255.h"

float f_magCount[3];
MPU9255 mpu(12, 250, 2, 6);
float mRx = 0, mRy = 0, mRz = 0, mo0 = 0, mo1 = 0, mo2 = 0, mx0 = 0, mx1 = 0, mx2 = 0, x;

void setup()
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  loadData();
  Wire.begin();
  TWBR = 24;
  Serial.begin(2000000);
  mpu.initMPU9250();
  float magCalibration[3];
  mpu.initAK8963(magCalibration);

}

int k = 0;

void loop()
{
  if (Serial.available())
  {
    char z = Serial.read();

    if (z == 'c') {
      int mnX = 500, mnY = 500, mnZ = 500, mxX = -500, mxY = -500, mxZ = -500;
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      while (k < 7500) {
        rawMag();
        if (f_magCount[0] > mxX)mxX = f_magCount[0];
        if (f_magCount[1] > mxY)mxY = f_magCount[1];
        if (f_magCount[2] > mxZ)mxZ = f_magCount[2];
        if (f_magCount[0] < mnX)mnX = f_magCount[0];
        if (f_magCount[1] < mnY)mnY = f_magCount[1];
        if (f_magCount[2] < mnZ)mnZ = f_magCount[2];
        k++;
        delay(1);
      }
      mo0 = (mxX + mnX) / 2;
      mo1 = (mxY + mnY) / 2;
      mo2 = (mxZ + mnZ) / 2;

      mx0 = 1;
      mx1 = (mxX - mo0) / (mxY - mo1);
      mx2 = (mxX - mo0) / (mxZ - mo2);

      saveData() ;

    }

  }


  updateMag();
  x = mRy / mRx;
  x = atan(x);
  if (x < 0)x = x + 3.1416;
  if (x==0 && mRx<0) x = 3.1416;
  if (mRy < 0)x = x + 3.1416;
  x = x * 31.8309 + 27;
  analogWrite(11, x);










  delay(10);

}



void rawMag() {
  mpu.readMagData(f_magCount);
}


void updateMag() {
  rawMag();
  mRx = (f_magCount[0] - mo0) * mx0;
  mRy = (f_magCount[1] - mo1) * mx1;
  mRz = (f_magCount[2] - mo2) * mx2;
}
