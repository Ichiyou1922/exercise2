#include <stdio.h>
#include <limits.h>

int main(void){
    int max = 2147483647;
    char c = 127;
    
    printf("現在: max = %d, c = %d\n", max, c);

    max = max + 1; //overflow
    c = c + 1;

    printf("加算後: max = %d, c = %d\n", max, c);

    return 0;
}
