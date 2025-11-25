#include <stdio.h>

int main(int argc, char **argv) {

  char *p = argv[1];
  char *q = argv[2];

  printf("%c\n", *p);
  printf("%c\n", *(p + 1));
  printf("%c\n", *q);

  char *r = *(argv + 1);

  printf("%s\n", r);

  return 0;
}
