#include <stdio.h>

int main(void){
    int a = 10;
    int *p = &a; // p は a のアドレスを持つ

    printf("aの初期値: %d\n", a);

    *p = 20; // pがさす場所(a)の中身を20に書き換える

    printf("aの変更後: %d\n", a); // aを遠隔で操作

    return 0;
}
