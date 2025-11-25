/* calc.h */

// インクルードガード
#ifndef CALC_H
#define CALC_H

typedef struct {
  int value;
  int error;
} Result;

Result safe_divide(int a, int b);

#endif
