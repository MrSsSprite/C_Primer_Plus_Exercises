/**
 * @file    ex6.c
 * @brief   convert water in quart into in molecule of water
 */

#include <stdio.h>

int main(void)
{
  double quart;
  printf("Input an amount of water, in quart(s): ");
  scanf("%lf", &quart);

  printf("In %.2lf quarts of water, there are %e molecules in the that amount of water\n",
         quart, quart * 950.0 / 3.0e-23);

  return 0;
}
