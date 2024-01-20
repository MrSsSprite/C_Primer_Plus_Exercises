/**
 * @file    ex3.c
 * @brief   reads in float and print it in different formats
 */
#include <stdio.h>

int main(void)
{
  float value;

  printf("Input a floating-point numbber: ");
  scanf("%f", &value);

  printf("\n");

  /*
     > 1. The input is `21.3` or `2.1e+001`.
     > 2. The input is `+21.290` or `2.129E+001`.
   */
  printf("Section A:\n");
  printf("The input is `%.1f` or `%.1e`.\n\n", value, value);

  printf("Section B:\n");
  printf("The input is `%+.3f` or `%.3e`.\n", value, value);

  return 0;
}
