#include <stdio.h>

int main(void) {
  // open file
  // "w" is write mode
  FILE *fp = fopen("data.txt", "w");

  // fault check
  // return NULL if no Authentication, full disk, etc
  if (fp == NULL) 
  {
    fprintf(stderr, "can`t open the file!\n");
    return 1;
  }

  // write
  fprintf(fp, "Hello, C File system!\n");
  fprintf(fp, "Number: %d\n", 42);

  //close
  fclose(fp);
  
  return 0;
}

/*
char buf[256];
// put char into buf from fp. max range is (sizeof(buf) -1) include \n.
while (fgets(buf, sizeof(buf), fp) != NULL) {
  printf("Read line: %s", buf);
}
*/
