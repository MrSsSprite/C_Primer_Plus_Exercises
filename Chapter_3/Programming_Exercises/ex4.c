/**
 * @file    ex4.c
 * @brief   read in a float and print in decimal & exponential & p notations
 */

#include <stdio.h>

int main(void)
{
  float value;
  printf("Input a float:\n");
  scanf("%f", &value);

  printf("Decimal:\t%f\n", value);
  printf("Exponential:\t%e\n", value);
  printf("P Notation:\t%a\n", value);

  return 0;
}
