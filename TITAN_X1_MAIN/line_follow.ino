void lineFollow() {


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

  intcnt();

  motorWrite(25, 25);

  while (1) // Start Up - Leave Box
  {
    readLine(0);
    if ((i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7) < 5)
    {
      Ecnt++;
      if (Ecnt > (250 / pFV))
        break;
    }
    else Ecnt = 0;
    moveIR(0);
  }

  intcnt();

  lcd.clear();
  lcd.print("searchE");
  while (searchE() == 0)
  {
    readLine(0);
    moveIR(0);
  }


  breaks();
  RED(0);
  GRN(0);
  BLU(0);

}
