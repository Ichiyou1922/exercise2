/* calc.h */

//インクルードガード
#ifndef CALC_H //もしCALC_Hが未定義ならば
#define CALC_H //定義して以下を読む

typedef struct {
  int value;
  int error;
} Result;

Result safe_divide(int a, int b);

#endif

