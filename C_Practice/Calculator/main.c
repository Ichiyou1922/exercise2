#include <stdio.h>
#include "calc.h"

int main(void) {
  int x = 10, y = 0;
  Result r = safe_divide(x, y);

  if (r.error == 1) {
    printf("Error: Division by zero\n");
  }
  else {
    printf("Result: %d\n", r.value);
  }

  return 0;
}
