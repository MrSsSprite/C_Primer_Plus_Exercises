/**
 * @file    ex1.c
 * @brief   experiment on int & float (overflow | underflow)
 *
 *          Find out what your system does with integer overflow, floating-point
 * overflow, and floating-point underflow. by using the experimental approach;
 * that is, write programs having these problems. (You can check the discussion
 * in Chapter 4 of `limits.h` and `float.h` to get guidance on the largest and
 * smallest values.)
 */

#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
  printf("Max. int value: %d\n", INT_MAX);
  printf("int overflow: %d + 1 = %d\n", INT_MAX, INT_MAX + 1);
  printf("Max. float value: %e\n", FLT_MAX);
  printf("float overflow: %e * 10 = %e\n", FLT_MAX, (float)FLT_MAX * (float)10);
  printf("Min. float value: %e\n", FLT_MIN);
  printf("float underflow: %e / 10 = %e\n", FLT_MIN, (float)FLT_MIN / (float)10);

  return 0;
}
