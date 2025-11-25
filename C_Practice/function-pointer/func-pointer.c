#include <stdio.h>

int add(int a, int b) {return a + b;}
int sub(int a, int b) {return a - b;}

int main(void) {
  int (*fp)(int, int);

  fp = add;

  int result = fp(10, 5);
  printf("Add: %d\n", result);

  fp = sub;

  result = fp(10, 5);
  printf("sub: %d\n", result);

  return 0;
}
