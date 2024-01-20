/**
 * @file    ex7.c
 * @brief   discuss the difference between float and double
 */
#include <stdio.h>
#include <float.h>

int main(void)
{
  float fVal = 1.0 / 3.0;
  double dVal = 1.0 / 3.0;

  printf("float: %.4f, double: %.4f\n", fVal, dVal);
  printf("float: %.12f, double: %.12f\n", fVal, dVal);
  printf("float: %.16f, double: %.16f\n", fVal, dVal);

  printf("FLT_DIG: %d, DBL_DIG: %d\n", FLT_DIG, DBL_DIG);

  return 0;
}
