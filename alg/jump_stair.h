#pragma once

#include "common.h"

// F(N) = F(N-1) + F(N-2) + F(N-3)
// last jumb number could be 1, 2 or 3, hence F(N) = ...
int kind(const int N) {
  if (N <= 1) return 1;
  else if (N == 2) return 1+1;
  else if (N == 3) return 1+2+1;
  int a = 1, b = 2, c = 4;
  for (int n = 0; n < N-3; ++n) {
    int d = a + b + c;
    a = b;
    b = c;
    c = d;
  }
  return b;
}

int kindR(const int N) {
  if (N <= 1) return 1;
  else if (N == 2) return 2;
  else if (N == 3) return 4;
  return kindR(N-1) + kindR(N-2) + kindR(N-3);
}
