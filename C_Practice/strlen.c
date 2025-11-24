#include <stdio.h>

int my_strlen(char *str) {
    char *p = str; //p = &str[0]

    // ポインタpの中身が '\0'になるまで進める
    // int count = 0;
    while (*p != '\0') {
       // count += 1;
        p++; // 最終的にp = &str[5] アドレスは6進む
    }        

    //return count;
    return p - str;
}

int main(void) {
    char s[] = "Hello"; // もしs[]={'A', 'B', 'C'}だった場合，'\0'がないため想定よりも長い文字列が返ってくる可能性がある．
    printf("Length: %d\n", my_strlen(s));
    return 0;
}
