#include <stdio.h>

int main(void){
    int arr[] = {10, 20, 30, 40, 50}; //arrはその配列の先頭要素のアドレスを示す定数ポインタ．arr = &arr[0]
    // ポインタpに1を足すとは，園型のサイズ分だけメモリ番地を進めるという事．
    // int *p -> p + 1はアドレスが4進む
    // char *p -> p + 1はアドレスが1進む
    // double *p -> p + 1はアドレスが8進む
    // arr[i] = *(arr + i)
    int *p = &arr[1];

    int val1 = *(p + 2); //arr[3]の値 -> 40

    int val2 = p[-1]; //arr[4]の値 -> 50...ではなく10

    p++;
    int val3 = *p; //arr[2] -> 30
    
    printf("%d, %d, %d\n", val1, val2, val3);

    return 0;

}
