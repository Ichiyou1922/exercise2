#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/*
void qsort(
  void *base, // 配列の先頭アドレス
  size_t nmemb, //要素数
  size_t size_t,
  int (*compar)(const void *, const void *) //比較関数のポインタ
);
*/

/*
a: 型はconst void *
(int *)a: (int *)でコンパイラにint型(4バイト)読み込めばイイと教えている．型はconst int *となった．
*(...): 型はintになる．
*/
int compare_desc(const void *a, const void *b){
  int val_a = *(int *)a;
  int val_b = *(int *)b;
  //return (val_b - val_a);
  if (val_a > val_b) return -1;
  if (val_a < val_b) return 1;
  return 0;
  }

int main(void){
  int values[] = { 40, 10, 100, 90, 20, 25};
  int values_size = sizeof(values) / sizeof(values[0]);

  qsort(values, values_size, sizeof(int), compare_desc);
  for (int i = 0; i < values_size; i++){
    printf("%d ", values[i]);
  }
  printf("\n");
  return 0;
}
