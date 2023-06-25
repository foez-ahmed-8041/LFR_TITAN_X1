int searchE() {
  if ((i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7) > 7)
  {
    Ecnt++;
    if (Ecnt > (1200 / pFV)) {
      Ecnt = 0;
      return 1;
    }
  }
  else {
    Ecnt = 0;
    return 0;
  }
}

int searchB() {
  if ((i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7) == 0 && pos == 0)
  {
    Bcnt++;
    if (Bcnt > (600 / pFV)) {
      Bcnt = 0;
      return 1;
    }
  }
  else {
    Bcnt = 0;
    return 0;
  }
}

int searchP() {
  if ((i0 + i1) != 0 && (i1 * i2) == 0 && (i2 + i3 + i4 + i5) != 0 && (i5 * i6) == 0 && (i6 + i7) != 0)
  {
    Pcnt++;
    if (Pcnt > (200 / pFV)) {
      Pcnt = 0;
      return 1;
    }
  }
  else {
    Pcnt = 0;
    return 0;
  }
}

int searchT() {
  if ((i0 + i1) != 0 && (i2 + i3 + i4 + i5) == 0 && (i6 + i7) != 0)
  {
    Tcnt++;
    if (Tcnt > (200 / pFV)) {
      Tcnt = 0;
      return 1;
    }
  }
  else {
    Tcnt = 0;
    return 0;
  }
}

int searchL() {
  if ((i0 + i1) != 0 && (i1 * i2) == 0 && (i2 + i3 + i4 + i5) != 0 && (i5 * i6) == 0 && (i6 + i7) == 0)
  {
    Lcnt++;
    if (Lcnt > (200 / pFV)) {
      Lcnt = 0;
      return 1;
    }
  }
  else {
    Lcnt = 0;
    return 0;
  }
}

int searchR() {
  if ((i0 + i1) == 0 && (i1 * i2) == 0 && (i2 + i3 + i4 + i5) != 0 && (i5 * i6) == 0 && (i6 + i7) != 0)
  {
    Rcnt++;
    if (Rcnt > (200 / pFV)) {
      Rcnt = 0;
      return 1;
    }
  }
  else {
    Rcnt = 0;
    return 0;
  }
}

int shortL() {
  if (i0 == 1)
  {
    Lcnt++;
    if (Lcnt > (200 / pFV)) {
      Lcnt = 0;
      return 1;
    }
  }
  else {
    Lcnt = 0;
    return 0;
  }
}

int shortR() {
  if (i7 == 1)
  {
    Rcnt++;
    if (Rcnt > (200 / pFV)) {
      Rcnt = 0;
      return 1;
    }
  }
  else {
    Rcnt = 0;
    return 0;
  }
}
