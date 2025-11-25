#include <stdio.h>

int main(void) {
  FILE *fp = fopen("filename.txt", "r");

  if (fp == NULL){
    fprintf(stderr, "Can`t open the filename.txt");
    return 1;
  }
  
  char buf[256];
  int line_num = 1;
  while(fgets(buf, sizeof(buf), fp) != NULL){
    printf("%d: %s", line_num, buf);
    line_num++;
  }
  fclose(fp);

  return 0;
}
