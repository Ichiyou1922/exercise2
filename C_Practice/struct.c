#include <stdio.h>

struct Robot {
    int id;
    double x;
    double y;
};

struct Robot my_bot = {1, 0.5, 0.5};

struct Robot *p = &my_bot;
(*p).x = 1.0 //めんどい！
p->x = 1.0 //糖衣構文を使う！
