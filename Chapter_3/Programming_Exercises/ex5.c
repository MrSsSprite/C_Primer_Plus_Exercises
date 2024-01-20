/**
 * @file    ex5.c
 * @brief   convert your age in years to seconds
 */

#include <stdio.h>

int main(void)
{
  int age;
  printf("Input your age: __\b\b");
  scanf("%d", &age);

  printf("You are %d year", age);
  if (age != 1) printf("s");
  printf(" old, which is approximately %.3e seconds\n",
         (double)age * 3.156e7);

  return 0;
}
