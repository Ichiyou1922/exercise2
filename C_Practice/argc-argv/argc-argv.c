#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("引数の数; %d\n", argc);

  for (int i = 0; i < argc; i++) {
//    if (*argv[i] == (int)) 
//    {
//      int num = atoi(argv[i]);
//      printf("argv[%d]: %d\n", i, num);
      printf("argv[%d]: %s\n", i, argv[i]);
//    }
//    else 
//    {  
//      printf("argv[%d]: %s\n", i, argv[i]);
//    }

  }
  return 0;
}
