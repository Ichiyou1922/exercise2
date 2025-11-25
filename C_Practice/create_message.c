#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_message(void) {
  char *msg = (char *)malloc(100);
  strcpy(msg, "This is a secret message.");
  printf("%s\n", msg);
}

int main(void) {
  while (1) {
    create_message();
  }
  return 0;
}

// free()によってメモリが返却されないため，リソースが枯渇，空きメモリがゼロになりOSのOOM Killer によって強制終了される．
//
// 関数内に戻り値チェックがないためmallocがNullを返したときSegmentation Faultで死
