void pointCheck() {
  
  int kkk = 0;

  if ((Lcnt > 1) && (Rcnt > 1)) {
    kkk = 0;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;

    if (kkk > 4) mazeWrite('r');  // p
    else         mazeWrite('r');  // t

    takeRight();
  }

  else if ((Lcnt < 1) && (Rcnt > 1)) {
    kkk = 0;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;

    if (kkk > 4)
      mazeWrite('r');

    takeRight();
  }

  else if ((Lcnt > 1) && (Rcnt < 1)) {
    kkk = 0;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;

    if (kkk > 4) {
      mazeWrite('s');
      takeStraight();
    }
    else takeLeft();
  }

  intcnt();

}


void pointSolve() {

  int kkk = 0;

  if ((Lcnt > 1) && (Rcnt > 1)) {
    kkk = 0;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;

    mazeRead();
  }

  else if ((Lcnt < 1) && (Rcnt > 1)) {
    kkk = 0;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;

    if (kkk > 4)
      mazeRead();

    else takeRight();
  }

  else if ((Lcnt > 1) && (Rcnt < 1)) {
    kkk = 0;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;
    readLine(1); kkk = kkk + i2 + i3 + i4 + i5;

    if (kkk > 4)
      mazeRead();

    else takeLeft();
  }

  intcnt();

}


void spaceRem() {
  while (MazeSolution[mazn] != 'e')
  {
    MazeSolution[mazn] =  MazeSolution[mazn + 2];
    mazn++;
  }
  MazeSolution[mazn] =  MazeSolution[mazn + 2];
}



void mazeWrite(char MMMM) {
  GRN(1);
  MazeSolution[mazn] = MMMM;
  lcd.print(MMMM);
  mazn++;
}



void mazeRead() {
  GRN(1);

  mazn--;
  if (mazn >= 0) {
    if (MazeSolution[mazn] == 'r')takeLeft();
    else if (MazeSolution[mazn] == 'l')takeRight();
    else if (MazeSolution[mazn] == 's')takeStraight();
    else if (MazeSolution[mazn] == 'b')takeBack();
  }
}
