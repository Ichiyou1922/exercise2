#include <stdio.h>
#include "calc.h"

Result safe_divide(int a, int b) {
  Result res;

  if (b == 0) {
    res.error = 1;
    res.value = 0;
    return res;
  }

  res.value = a / b;
  res.error = 0;
  return res;
}
