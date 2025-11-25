#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *arr = (int *)malloc(sizeof(int) * 10); // malloc(size): 指定したバイト数のメモリブロックを確保し，その先頭アドレスを返す．
// (i *): mallocは汎用ポインタvoid*を返す->適切な型に変換するのが作法．
  if (arr == NULL ) {
    printf("メモリ確保失敗\n");
    return 1;
  }

  for (int i = 0; i < 10; i++) {
    arr[i] = i * 10;
  }

  free(arr);
  return 0;
}
