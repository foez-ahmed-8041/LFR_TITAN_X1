#define codeCnt 44

void printCode(int x) {
  if (x == 0) lcd.print("Reserved ");

  else if (x == -2)  lcd.print("Delete   ");
  else if (x == -1)  lcd.print("Insert   ");

  else if (x == 1)   lcd.print("Exit     ");
  else if (x == 2)   lcd.print("Stop     ");
  else if (x == 3)   lcd.print("Delay1S  ");
  else if (x == 4)   lcd.print("TurnLeft ");
  else if (x == 5)   lcd.print("TurnRight");
  else if (x == 6)   lcd.print("GoForward");
  else if (x == 7)   lcd.print("TakeSTRT.");
  else if (x == 8)   lcd.print("TakeLeft ");
  else if (x == 9)   lcd.print("TakeRight");
  else if (x == 10)  lcd.print("TakeBack ");

  else if (x == 11)  lcd.print("searchE  ");
  else if (x == 12)  lcd.print("searchB  ");
  else if (x == 13)  lcd.print("searchP  ");
  else if (x == 14)  lcd.print("searchT  ");
  else if (x == 15)  lcd.print("searchL  ");
  else if (x == 16)  lcd.print("searchR  ");
  else if (x == 17)  lcd.print("shortL   ");
  else if (x == 18)  lcd.print("shortR   ");
  else if (x == 19)  lcd.print("SNR_Drive");
  else if (x == 20)  lcd.print("Obstracle");


  else if (x == 21)  lcd.print("TD_1     ");
  else if (x == 22)  lcd.print("TD_2     ");
  else if (x == 23)  lcd.print("TD_4     ");
  else if (x == 24)  lcd.print("TD_10    ");
  else if (x == 25)  lcd.print("TD_20    ");
  else if (x == 26)  lcd.print("TD_40    ");
  else if (x == 27)  lcd.print("TD_100   ");
  else if (x == 28)  lcd.print("TD_200   ");
  else if (x == 29)  lcd.print("TD_400   ");
  else if (x == 30)  lcd.print("TD_1000  ");
  else if (x == 31)  lcd.print("TD_2000  ");
  else if (x == 32)  lcd.print("TD_4000  ");


  else if (x == 33)  lcd.print("RED(0)   ");
  else if (x == 34)  lcd.print("GRN(0)   ");
  else if (x == 35)  lcd.print("BLU(0)   ");
  else if (x == 36)  lcd.print("RED(1)   ");
  else if (x == 37)  lcd.print("GRN(1)   ");
  else if (x == 38)  lcd.print("BLU(1)   ");

  else if (x == 39)  lcd.print("pFV= 08.0");
  else if (x == 40)  lcd.print("pFV= 09.0");
  else if (x == 41)  lcd.print("pFV= 10.0");
  else if (x == 42)  lcd.print("pFV= 11.0");
  else if (x == 43)  lcd.print("pFV= 12.0");
  else if (x == 44)  lcd.print("pFV= 13.0");




  else               lcd.print("...      ");
}


void runCP() {

  byte itx[250];

  byte x = 0;
  while (x < 250) {
    itx[x] = EEPROM.read(500 + x);
    x++;
  }

  setpF();

  lcd.clear();
  lcd.setCursor(0, 0);    lcd.print(500 + cpPointer - 1);    lcd.print("    ");    printCode(itx[cpPointer - 1]);
  lcd.setCursor(0, 1);    lcd.print(500 + cpPointer + 0);    lcd.print(">>> ");    printCode(itx[cpPointer + 0]); lcd.print(" <<<");
  lcd.setCursor(0, 2);    lcd.print(500 + cpPointer + 1);    lcd.print("    ");    printCode(itx[cpPointer + 1]);
  lcd.setCursor(0, 3);    lcd.print(500 + cpPointer + 2);    lcd.print("    ");    printCode(itx[cpPointer + 2]);

  RED(1); GRN(0); BLU(0);
  delay(333);
  RED(1); GRN(1); BLU(0);
  delay(333);
  RED(0); GRN(1); BLU(0);
  delay(333);
  RED(0); GRN(0); BLU(0);

  while (cpPointer < 250) {

    readLine(0);

    lcd.clear();
    lcd.setCursor(0, 0);    lcd.print(500 + cpPointer - 1);    lcd.print("    ");    printCode(itx[cpPointer - 1]);
    lcd.setCursor(0, 1);    lcd.print(500 + cpPointer + 0);    lcd.print(">>> ");    printCode(itx[cpPointer + 0]); lcd.print(" <<<");
    lcd.setCursor(0, 2);    lcd.print(500 + cpPointer + 1);    lcd.print("    ");    printCode(itx[cpPointer + 1]);
    lcd.setCursor(0, 3);    lcd.print(500 + cpPointer + 2);    lcd.print("    ");    printCode(itx[cpPointer + 2]);

    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////

    if (itx[cpPointer] == 1) {
      motorWrite(0, 0);
      delay(100);
      cpPointer = 0;
      break;
    }

    else if (itx[cpPointer] == 2) {
      breaks();
    }

    else if (itx[cpPointer] == 3) {
      delay(1000);
    }

    else if (itx[cpPointer] == 4) {
      turnLeft();
    }

    else if (itx[cpPointer] == 5) {
      turnRight();
    }

    else if (itx[cpPointer] == 6) {
      TD(7);
    }

    else if (itx[cpPointer] == 7) {
      takeStraight();
    }

    else if (itx[cpPointer] == 8) {
      takeLeft();
    }

    else if (itx[cpPointer] == 9) {
      takeRight();
    }

    else if (itx[cpPointer] == 10) {
      takeBack();
    }








    else if (itx[cpPointer] == 11) {
      while (searchE() == 0)
      {
        readLine(0);
        moveIR(0);
      }
    }

    else if (itx[cpPointer] == 12) {
      while (searchB() == 0)
      {
        readLine(0);
        moveIR(0);
      }
    }

    else if (itx[cpPointer] == 13) {
      while (searchP() == 0)
      {
        readLine(0);
        moveIR(0);
      }
    }

    else if (itx[cpPointer] == 14) {
      while (searchT() == 0)
      {
        readLine(0);
        moveIR(0);
      }
    }

    else if (itx[cpPointer] == 15) {
      while (searchL() == 0)
      {
        readLine(0);
        moveIR(0);
      }
    }

    else if (itx[cpPointer] == 16) {
      while (searchR() == 0)
      {
        readLine(0);
        moveIR(0);
      }
    }

    else if (itx[cpPointer] == 17) {
      while (shortL() == 0)
      {
        readLine(0);
        moveIR(0);
      }
    }

    else if (itx[cpPointer] == 18) {
      while (shortR() == 0)
      {
        readLine(0);
        moveIR(0);
      }
    }

    else if (itx[cpPointer] == 19) {
      sonarDrive();
    }

    else if (itx[cpPointer] == 20) {
      crossObstracle();
    }









    else if (itx[cpPointer] == 21) {
      TD(1);
    }

    else if (itx[cpPointer] == 22) {
      TD(2);
    }

    else if (itx[cpPointer] == 23) {
      TD(4);
    }

    else if (itx[cpPointer] == 24) {
      TD(10);
    }

    else if (itx[cpPointer] == 25) {
      TD(20);
    }

    else if (itx[cpPointer] == 26) {
      TD(40);
    }

    else if (itx[cpPointer] == 27) {
      TD(100);
    }

    else if (itx[cpPointer] == 28) {
      TD(200);
    }

    else if (itx[cpPointer] == 29) {
      TD(400);
    }

    else if (itx[cpPointer] == 30) {
      TD(1000);
    }

    else if (itx[cpPointer] == 31) {
      TD(2000);
    }

    else if (itx[cpPointer] == 32) {
      TD(4000);
    }







    else if (itx[cpPointer] == 33) {
      RED(0);
    }

    else if (itx[cpPointer] == 34) {
      GRN(0);
    }

    else if (itx[cpPointer] == 35) {
      BLU(0);
    }

    else if (itx[cpPointer] == 36) {
      RED(1);
    }

    else if (itx[cpPointer] == 37) {
      GRN(1);
    }

    else if (itx[cpPointer] == 38) {
      BLU(1);
    }









    else if (itx[cpPointer] == 39) {
      pFV = 8;
      setpF();
    }


    else if (itx[cpPointer] == 40) {
      pFV = 9;
      setpF();
    }


    else if (itx[cpPointer] == 41) {
      pFV = 10;
      setpF();
    }


    else if (itx[cpPointer] == 42) {
      pFV = 11;
      setpF();
    }


    else if (itx[cpPointer] == 43) {
      pFV = 12;
      setpF();
    }


    else if (itx[cpPointer] == 44) {
      pFV = 13;
      setpF();
    }

    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////

    cpPointer++;
  }
}
