#include <stdio.h>

int main(void){
    int a = 10; //RAMのどこかにint型のサイズ分の領域が確保された．その領域に数値10のバイナリ表現を書き込んだ．

    //%d は10進数(decimal)として表示
    //%p はポインタ(pointer/address)として16進数で表示
    printf("値: %d\n", a);
    printf("アドレス: %p\n", &a);

    return 0;

}
