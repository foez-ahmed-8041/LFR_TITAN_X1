#define menuCounts 9 // Last Index0

void homePage() {
  lcd.clear();
  lcd.setCursor(6, 1);
  lcd.print("TITAN-X1");
  lcd.setCursor(7, 3);
  if (pFV == 0)
    lcd.print(getVolts());
  else
    lcd.print(pFV);
  lcd.print("V   ");
  lcd.setCursor(17, 3);
  lcd.print("-Fz");
  lcd.setCursor(0, 3);
  printVolts();
}




int m = 0;
void updateInterface(int k = 0) {
startx:

  lcd.clear();
  lcd.setCursor(19, 0);
  printVolts();
  
  // EEPROM Comparator Load
  pFV = (EEPROM.read(8));
  pFV = pFV / 10;
  xFT = (EEPROM.read(9));
  setpF();
  
  lcd.setCursor(0, 0);


  if (k == 2) m = m - 1;
  if (k == 3) m = m + 1;

  if (m < 0) m = menuCounts;
  if (m > menuCounts) m = 0;

  //////////////////////////////////////////////
  if (m == 0)
  {
    lcd.print("Calibrate IR");
    k = 0;
    while (k == 0)
    {
      k = getClick();
      lcd.setCursor(6, 2);
      readLine(0);
      lcd.print(i0);
      lcd.print(i1);
      lcd.print(i2);
      lcd.print(i3);
      lcd.print(i4);
      lcd.print(i5);
      lcd.print(i6);
      lcd.print(i7);
      lcd.setCursor(9, 3);
      lcd.print((int)rp);
      lcd.print("   ");
      delay(50);
    }
    if (k != 4 && k != 1) goto startx;

    if (k == 1)
    {
      lcd.clear();

      while (getClick() == 0)
      {
        lcd.setCursor(3, 0);  lcd.print(analogRead(A5)); lcd.print(" ");  lcd.setCursor(14, 0);  lcd.print(analogRead(A12));  lcd.print(" ");
        lcd.setCursor(3, 1);  lcd.print(analogRead(A6)); lcd.print(" ");  lcd.setCursor(14, 1);  lcd.print(analogRead(A11));  lcd.print(" ");
        lcd.setCursor(3, 2);  lcd.print(analogRead(A7)); lcd.print(" ");  lcd.setCursor(14, 2);  lcd.print(analogRead(A10));  lcd.print(" ");
        lcd.setCursor(3, 3);  lcd.print(analogRead(A8)); lcd.print(" ");  lcd.setCursor(14, 3);  lcd.print(analogRead(A9));  lcd.print(" ");
        delay(50);
      }
      k = 0;
      goto startx;
    }

    else if (k == 4)
    {
      lcd.clear();
      lcd.print("Calibrating");
      delay(250);
      lcd.print(".");
      delay(250);
      lcd.print(".");
      delay(250);
      lcd.print(".");
      delay(250);
      homePage();
      calibrateLine();
      while (getClick() == 0)
        delay(1);
      k = 0;
      goto startx;
    }
  }
  //////////////////////////////////////////////



  //////////////////////////////////////////////
  else if (m == 1) {
    lcd.print("Line Follower");


    lcd.setCursor(0, 1);

    if (lnmd == 0)
      lcd.print("Black Line");
    else
      lcd.print("White Line");

    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    if (k == 1) {
      lnmd = !lnmd;
      k = 0;
      goto startx;
    }

    else if (k == 4) {
      lineFollow();
      k = 0;
      goto startx;
    }
    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    //    lcd.setCursor(0, 2);
    //
    //    if (iLFR == 0)
    //      lcd.print("Part1");
    //    else  if (iLFR == 1)
    //      lcd.print("Part2");
    //    else  if (iLFR == 2)
    //      lcd.print("Part3");
    //    else
    //      lcd.print("...");
    //
    //    if (k == 1) {
    //      iLFR++;
    //      k = 0;
    //      goto startx;
    //    }
    //
    //    else if (k == 4) {
    //
    //      if (iLFR == 0)
    //        part1();
    //      else  if (iLFR == 1)
    //        part2();
    //      else  if (iLFR == 2)
    //        part3();
    //
    //      k = 0;
    //      goto startx;
    //    }
    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

  }
  //////////////////////////////////////////////



  //////////////////////////////////////////////
  else if (m == 2) {
    lcd.print("Maze Solver");
    lcd.setCursor(0, 1);
    if (lnmd == 0)
      lcd.print("Black Line");
    else
      lcd.print("White Line");

    if (k == 1) {
      lnmd = !lnmd;
      k = 0;
      goto startx;
    }

    else if (k == 4) {
      startMaze();
      k = 0;
      goto startx;
    }
  }
  //////////////////////////////////////////////



  //////////////////////////////////////////////
  else if (m == 3) {
    lcd.print("Maze Last Solution");
    lcd.setCursor(0, 1);
    if (lnmd == 0)
      lcd.print("Black Line");
    else
      lcd.print("White Line");

    lcd.setCursor(0, 2);

    mazn = 0;
    while ( EEPROM.read(250 + mazn) != 'e') {
      MazeSolution[mazn] = EEPROM.read(250 + mazn);
      lcd.print(MazeSolution[mazn]);
      mazn++;
    }
    MazeSolution[mazn] = EEPROM.read(250 + mazn);
    lcd.print(MazeSolution[mazn]);

    if (k == 1) {
      lnmd = !lnmd;
      k = 0;
      goto startx;
    }

    else if (k == 4) {
      delay(1000);
      solveMaze();
      k = 0;
      goto startx;
    }
  }
  //////////////////////////////////////////////



  //////////////////////////////////////////////
  else if (m == 4) {
    lcd.print("Run Custom Program ");

    if (k == 4)
    {
      lcd.clear();
      k = 0;
      goto bgn2;

      int ix = 0;

      while (1) {
        ix++;
        k = getClick();
        if (k != 0) {

          if (k == 1)
          {
            goto startx;
          }

          else if (k == 2)
          {
            cpPointer--;
          }

          else if (k == 3)
          {
            cpPointer++;
          }

          else if (k == 4)
          {
            k = 0;
            runCP();
          }



bgn2:
          lcd.clear();
          lcd.setCursor(0, 0);    lcd.print(500 + cpPointer - 1);    lcd.print("    ");    printCode(EEPROM.read(500 + cpPointer - 1));
          lcd.setCursor(0, 1);    lcd.print(500 + cpPointer + 0);    lcd.print(">>> ");    printCode(EEPROM.read(500 + cpPointer + 0)); lcd.print(" <<<");
          lcd.setCursor(0, 2);    lcd.print(500 + cpPointer + 1);    lcd.print("    ");    printCode(EEPROM.read(500 + cpPointer + 1));
          lcd.setCursor(0, 3);    lcd.print(500 + cpPointer + 2);    lcd.print("    ");    printCode(EEPROM.read(500 + cpPointer + 2));

        }

        if (ix == 1000) {
          lcd.setCursor(3, 1);
          lcd.print(">   ");
          lcd.setCursor(16, 1);
          lcd.print("   <");
        }
        else  if (ix == 2000) {
          lcd.setCursor(3, 1);
          lcd.print(" >  ");
          lcd.setCursor(16, 1);
          lcd.print("  < ");
        }
        else  if (ix >= 3000) {
          ix = 0;
          lcd.setCursor(3, 1);
          lcd.print("  > ");
          lcd.setCursor(16, 1);
          lcd.print(" <  ");
        }

      }
      k = 0;
      goto startx;
    }
  }
  //////////////////////////////////////////////



  //////////////////////////////////////////////
  else if (m == 5) {
    lcd.print("Program Summery");

    if (k == 4)
    {
      lcd.clear();
      k = 0;
      goto bgn0;

      while (1) {
        k = getClick();
        if (k != 0) {

          if (k == 1)
          {
            goto startx;
          }

          else if (k == 2)
          {
            cpPointer--;
          }

          else if (k == 3)
          {
            cpPointer++;
          }

          else if (k == 4)
          {
            lcd.clear();
            k = 0;
            cpPointer = 0;

            int objx = EEPROM.read(500 + cpPointer);

            goto bgn1;

            while (1) {
              k = getClick();
              if (k != 0) {

bgn1:


                if (k == 1)
                { ////////---------------------------------------------------
                  k = 0;

                  if (objx == -1) {
                    int n = 0;
                    while ((500 + cpPointer + n) < 750) {
                      if (EEPROM.read(500 + cpPointer + n) == 1 || EEPROM.read(500 + cpPointer + n) == 255) break;
                      n++;
                    }
                    while (n > -1) {
                      EEPROM.write(500 + cpPointer + n + 1, (EEPROM.read(500 + cpPointer + n)));
                      n--;
                    }
                    objx = 255;
                    goto EDX;
                  }

                  else if (objx == -2) {
                    int n = 0;
                    while ((500 + cpPointer + n) < 750) {
                      EEPROM.write(500 + cpPointer + n, (EEPROM.read(500 + cpPointer + n + 1)));
                      n++;
                      if (EEPROM.read(500 + cpPointer + n) == 1 || EEPROM.read(500 + cpPointer + n) == 255) break;
                    }
                    EEPROM.write(500 + cpPointer + n, (EEPROM.read(500 + cpPointer + n + 1)));
                    objx = EEPROM.read(500 + cpPointer);
                    goto EDX;
                  }



                  if (EEPROM.read(500 + cpPointer) != objx) EEPROM.write(500 + cpPointer, objx);

                  cpPointer--;

                  objx = EEPROM.read(500 + cpPointer);


                } ////////---------------------------------------------------

                else if (k == 2)
                {
                  objx--;
                  if (objx < -2) objx = codeCnt;
                  else if (objx > codeCnt) objx = -2;
                }

                else if (k == 3)
                {
                  objx++;
                  if (objx < -2) objx = codeCnt;
                  else if (objx > codeCnt) objx = -2;
                }

                else if (k == 4)
                { ////////---------------------------------------------------
                  k = 0;

                  if (objx == -1) {
                    int n = 0;
                    while ((500 + cpPointer + n) < 750) {
                      if (EEPROM.read(500 + cpPointer + n) == 1 || EEPROM.read(500 + cpPointer + n) == 255) break;
                      n++;
                    }
                    while (n > -1) {
                      EEPROM.write(500 + cpPointer + n + 1, (EEPROM.read(500 + cpPointer + n)));
                      n--;
                    }
                    objx = 255;
                    goto EDX;
                  }

                  else if (objx == -2) {
                    int n = 0;
                    while ((500 + cpPointer + n) < 750) {
                      EEPROM.write(500 + cpPointer + n, (EEPROM.read(500 + cpPointer + n + 1)));
                      n++;
                      if (EEPROM.read(500 + cpPointer + n) == 1 || EEPROM.read(500 + cpPointer + n) == 255) break;
                    }
                    EEPROM.write(500 + cpPointer + n, (EEPROM.read(500 + cpPointer + n + 1)));
                    objx = EEPROM.read(500 + cpPointer);
                    goto EDX;
                  }



                  if (EEPROM.read(500 + cpPointer) != objx) EEPROM.write(500 + cpPointer, objx);

                  if (objx == 1) {
                    cpPointer++;
                    while ((500 + cpPointer) < 750) {
                      EEPROM.write(500 + cpPointer, 255);
                      cpPointer++;
                    }
                    cpPointer = 0;
                    goto bgn0;
                  }
                  cpPointer++;

                  objx = EEPROM.read(500 + cpPointer);


                } ////////---------------------------------------------------


EDX:

                lcd.clear();
                lcd.setCursor(0, 0);    lcd.print(500 + cpPointer - 2);    lcd.print("    ");    printCode(EEPROM.read(500 + cpPointer - 2));
                lcd.setCursor(0, 1);    lcd.print(500 + cpPointer - 1);    lcd.print("    ");    printCode(EEPROM.read(500 + cpPointer - 1));
                lcd.setCursor(0, 2);    lcd.print(500 + cpPointer + 0);    lcd.print(" -> ");    printCode(objx);  lcd.print(" <-");
                lcd.setCursor(0, 3);    lcd.print(500 + cpPointer + 1);    lcd.print("    ");    printCode(EEPROM.read(500 + cpPointer + 1));

              }
            }
            k = 0;
            goto startx;
          }

bgn0:
          lcd.clear();
          lcd.setCursor(0, 0);    lcd.print(500 + cpPointer + 0);    lcd.print(" ");    printCode(EEPROM.read(500 + cpPointer + 0));
          lcd.setCursor(0, 1);    lcd.print(500 + cpPointer + 1);    lcd.print(" ");    printCode(EEPROM.read(500 + cpPointer + 1));
          lcd.setCursor(0, 2);    lcd.print(500 + cpPointer + 2);    lcd.print(" ");    printCode(EEPROM.read(500 + cpPointer + 2));
          lcd.setCursor(0, 3);    lcd.print(500 + cpPointer + 3);    lcd.print(" ");    printCode(EEPROM.read(500 + cpPointer + 3));

        }
      }
      k = 0;
      goto startx;
    }
  }
  //////////////////////////////////////////////



  //////////////////////////////////////////////
  else if (m == 6) {
    lcd.print("Calibrate Compass");
    k = 0;
    while (k == 0)
    {
      k = getClick();
      lcd.setCursor(7, 2);
      float x = (readPWM(46) - 27) * 1.8;
      lcd.print(x);
      lcd.print("  ");
      delay(50);
    }
    if (k != 4) goto startx;

    if (k == 4)
    {
      lcd.clear();
      lcd.print("Calibrating");
      delay(250);
      lcd.print(".");
      delay(250);
      lcd.print(".");
      delay(250);
      lcd.print(".");
      delay(250);
      homePage();
      motorWrite(-15, 8);
      delay(1000);
      Serial3.print('c');
      delay(1000);
      while (digitalRead(46) == 0)
        delay(1);
      lcd.clear();
      lcd.print("Calibration");
      lcd.setCursor(0, 1);
      lcd.print("Complete");
      motorWrite(0, 0);
      while (getClick() == 0)
        delay(1);
      k = 0;
      goto startx;
    }
  }
  //////////////////////////////////////////////



  //////////////////////////////////////////////
  else if (m == 7) {
    lcd.print("Sonar Test");
    if (k == 1) {
      lcd.clear();
      lcd.print("                  mm");
      Serial2.print('x');
      Serial2.print('a');
      while (getClick() == 0)
      {
        lcd.setCursor(9, 1);
        lcd.print(255 - readPWM(52));
        lcd.print("  ");
        lcd.setCursor(0, 2);
        lcd.print(255 - readPWM(48));
        lcd.print("  ");
        lcd.setCursor(17, 2);
        lcd.print(255 - readPWM(50));
        lcd.print("  ");
        delay(50);
      }
      Serial2.print('x');
      k = 0;
      goto startx;
    }
    else if (k == 4) {
      lcd.clear();
      lcd.print("                  mm");
      while (getClick() == 0)
      {
        readSonar();
        lcd.setCursor(9, 1);
        lcd.print(xF);
        lcd.print("  ");
        lcd.setCursor(17, 2);
        lcd.print(xRF);
        lcd.print("  ");
        lcd.setCursor(0, 2);
        lcd.print(xLF);
        lcd.print("  ");
        lcd.setCursor(17, 3);
        lcd.print(xRB);
        lcd.print("  ");
        lcd.setCursor(0, 3);
        lcd.print(xLB);
        lcd.print("  ");
        delay(10);
      }
      k = 0;
      goto startx;
    }
  }
  //////////////////////////////////////////////



  //////////////////////////////////////////////
  else if (m == 8) {
    lcd.print("Breaking Distance:  ");
    lcd.setCursor(0, 1);
    lcd.print(xFT);
    lcd.print("mm ");

    if (k == 4)
    {
      lcd.clear();
      lcd.print("Set Distance:");
      k = 0;
      goto bgn3;
      while (1) {
        k = getClick();
        if (k != 0) {
bgn3:
          if (k == 1)
          {
            lcd.clear();
            lcd.print("Discarding Change");
            delay(250);
            lcd.print(".");
            delay(250);
            lcd.print(".");
            delay(250);
            lcd.print(".");
            delay(250);
            break;
          }

          else if (k == 4) {
            lcd.clear();
            lcd.print("Saving Change");
            EEPROM.write(9, xFT);
            xFT = EEPROM.read(9);
            delay(250);
            lcd.print(".");
            delay(250);
            lcd.print(".");
            delay(250);
            lcd.print(".");
            delay(250);
            break;
          }

          else if (k == 2) {
            xFT = xFT - 10;
            if (xFT < 0)xFT = 0;
          }

          else if (k == 3) {
            xFT = xFT + 10;
            if (xFT > 250)xFT = 250;
          }

          lcd.setCursor(0, 1);
          lcd.print(xFT);
          lcd.print("mm ");
        }
      }
      k = 0;
      goto startx;
    }
  }
  //////////////////////////////////////////////



  //////////////////////////////////////////////
  else if (m == 9) {
    lcd.print("Power Output: ");
    lcd.setCursor(0, 1);
    lcd.print(pFV);
    lcd.print("V ");

    if (k == 4)
    {
      lcd.clear();
      lcd.print("Set Power Output:");
      k = 0;
      goto bgn;
      while (1) {
        k = getClick();
        if (k != 0) {
bgn:
          if (k == 1)
          {
            lcd.clear();
            lcd.print("Discarding Change");
            delay(250);
            lcd.print(".");
            delay(250);
            lcd.print(".");
            delay(250);
            lcd.print(".");
            delay(250);
            break;
          }

          else if (k == 4) {
            lcd.clear();
            lcd.print("Saving Change");
            pFV = pFV * 10;
            EEPROM.write(8, (int)pFV);
            pFV = EEPROM.read(8);
            pFV = pFV / 10;
            delay(250);
            lcd.print(".");
            delay(250);
            lcd.print(".");
            delay(250);
            lcd.print(".");
            delay(250);
            break;
          }

          else if (k == 2) {
            pFV = pFV - 0.1;
          }

          else if (k == 3) {
            pFV = pFV + 0.1;
          }

          lcd.setCursor(0, 1);
          lcd.print(pFV);
          lcd.print("V ");
        }
      }
      k = 0;
      goto startx;
    }
  }
  //////////////////////////////////////////////




  //////////////////////////////////////////////
  else if (m == 1000) {
    lcd.print("Title Here");
    k = 0;
    while (k == 0)
    {
      k = getClick();
      //Tasks here
      delay(50);
    }
    if (k != 4) goto startx;

    if (k == 4)
    {
      lcd.clear();
      //Initiate Sequence


      //Last output
      while (getClick() == 0)
        delay(1);
      k = 0;
      goto startx;
    }
  }
  //////////////////////////////////////////////


}
