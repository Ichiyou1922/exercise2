#include <stdio.h>
#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Write your filename!");
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");

  if (fp == NULL){
    fprintf(stderr, "Can`t open file: %s\n", argv[1]);
    return 1;
  }
  
  char buf[BUFFER_SIZE];
  int line_num = 1;
  while(fgets(buf, sizeof(buf), fp) != NULL){
    printf("%d: %s", line_num, buf);
    line_num++;
  }
  
  fclose(fp);
  return 0;
}
