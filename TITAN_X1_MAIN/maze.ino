void startMaze() {

  homePage();
  BLU(0);
  RED(1);
  GRN(0);
  delay(333);
  RED(1);
  GRN(1);
  delay(333);
  RED(0);
  GRN(1);
  delay(333);
  GRN(0);

  mazn = 0;
  intcnt();

  setpF();

  motorWrite(25, 25);

  while (1) // Start Up - Leave Box
  {
    readLine(0);
    if ((i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7) < 5)
    {
      Ecnt++;
      if (Ecnt > (200 / pFV))
        break;
    }
    else Ecnt = 0;
    moveIR(0);
  }


  lcd.clear();

  intcnt();


  while (1) // Maze Search
  {
    readLine(1);

    if (i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7 > 5) {
      Ecnt++;
      if (Ecnt > (550 / pFV))
        break;
      moveIR(0);
    }

    else {
      if (i0 == 1)
      {
        vp = 0;
        Lcnt++;
        if (Lcnt > (150 / pFV)) {
          pointCheck();
        }
      }
      else Lcnt = 0;


      if (i7 == 1)
      {
        vp = 0;
        Rcnt++;
        if (Rcnt > (150 / pFV)) {
          pointCheck();
        }
      }
      else Rcnt = 0;


      if ((i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7) == 0)
      {
        vp = 0;
        Bcnt++;
        if (Bcnt > (200 / pFV)) {
          mazeWrite('b');
          takeBack();
        }
      }
      else Bcnt = 0;

      moveIR(1);
    }

  }

  breaks();

  mazeWrite('e');

  lcd.clear();

  mazn = 0;

  while (MazeSolution[mazn] != 'e') {

    if (MazeSolution[mazn] == 'b' && mazn > 0) {

      if (MazeSolution[mazn - 1] == 'l' && MazeSolution[mazn + 1] == 'l') {
        MazeSolution[mazn - 1] = 's';
        spaceRem();
      }

      else if (MazeSolution[mazn - 1] == 'l' && MazeSolution[mazn + 1] == 'r') {
        MazeSolution[mazn - 1] = 'b';
        spaceRem();
      }

      else if (MazeSolution[mazn - 1] == 'l' && MazeSolution[mazn + 1] == 's') {
        MazeSolution[mazn - 1] = 'r';
        spaceRem();
      }

      else if (MazeSolution[mazn - 1] == 'r' && MazeSolution[mazn + 1] == 'l') {
        MazeSolution[mazn - 1] = 'b';
        spaceRem();
      }

      else if (MazeSolution[mazn - 1] == 'r' && MazeSolution[mazn + 1] == 'r') {
        MazeSolution[mazn - 1] = 's';
        spaceRem();
      }

      else if (MazeSolution[mazn - 1] == 'r' && MazeSolution[mazn + 1] == 's') {
        MazeSolution[mazn - 1] = 'l';
        spaceRem();
      }

      else if (MazeSolution[mazn - 1] == 's' && MazeSolution[mazn + 1] == 'l') {
        MazeSolution[mazn - 1] = 'r';
        spaceRem();
      }

      else if (MazeSolution[mazn - 1] == 's' && MazeSolution[mazn + 1] == 'r') {
        MazeSolution[mazn - 1] = 'l';
        spaceRem();
      }

      else if (MazeSolution[mazn - 1] == 's' && MazeSolution[mazn + 1] == 's') {
        MazeSolution[mazn - 1] = 'b';
        spaceRem();
      }

      mazn = 0;
    }
    mazn++;
  }

  mazn = 0;
  while (MazeSolution[mazn] != 'e') {
    EEPROM.write(250 + mazn, MazeSolution[mazn]);
    lcd.print(MazeSolution[mazn]);
    mazn++;
  }
  EEPROM.write(250 + mazn, MazeSolution[mazn]);
  lcd.print(MazeSolution[mazn]);

  delay(1000);


  ///////////////////////Turn Around//////////////////////

  BLU(1);
  motorWrite(25, 25);
  delay(1000 / pFV);
  motorWrite(0, 0);
  delay(10 * pFV);
  motorWrite(25, -25);
  delay(4400 / pFV);
  motorWrite(-25, 25);
  delay(440 / pFV);
  motorWrite(0, 0);
  readLine(1);

  if ((i0 + i7) == 0 && (i1 + i2 + i3 + i4 + i5 + i6) > 3)
    while ((i0 + i7) == 0) {
      readLine(1);
      moveIR(0);
    }

  intcnt();
  while (1) // Start Up - Leave Box
  {
    readLine(1);
    if ((i2 + i3 + i4 + i5) < 4 && (i3 + i4) > 0)
    {
      Ecnt++;
      if (Ecnt > (200 / pFV))
        break;
    }
    else Ecnt = 0;
    moveIR(0);
  }
  int TTXX = 0;
  while (TTXX < (1500 / pFV)) {
    readLine(1);
    moveIR(0);
    TTXX++;
  }
  BLU(0);
  intcnt();
  GRN(0);

  ////////////////////////////////////////////////////////



  solveMaze();
}

void solveMaze() {

  lcd.clear();

  mazn = 0;
  while ( EEPROM.read(250 + mazn) != 'e') {
    MazeSolution[mazn] = EEPROM.read(250 + mazn);
    lcd.print(MazeSolution[mazn]);
    mazn++;
  }
  MazeSolution[mazn] = EEPROM.read(250 + mazn);
  lcd.print(MazeSolution[mazn]);


  while (mazn > 0) // Maze Search
  {
    readLine(1);



    if (i0 == 1)
    {
      vp = 0;
      Lcnt++;
      if (Lcnt > (150 / pFV)) {
        pointSolve();
      }
    }
    else Lcnt = 0;


    if (i7 == 1)
    {
      vp = 0;
      Rcnt++;
      if (Rcnt > (150 / pFV)) {
        pointSolve();
      }
    }
    else Rcnt = 0;


    if ((i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7) == 0)
    {
      vp = 0;
      Bcnt++;
      if (Bcnt > (200 / pFV)) {
        takeBack();
      }
    }
    else Bcnt = 0;

    moveIR(1);


  }


  intcnt();

  /////////////////////////Effect/////////////////////////

  while (1) // Box or Line End
  {
    readLine(0);

    if (pcl > (1400 / pFV)) pcl = pcl / 4;

    if (searchE())break;

    if (searchB())break;

    moveIR(0);
  }

  ////////////////////////////////////////////////////////

  breaks();


}
