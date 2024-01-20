/**
 * @file    ex7.c
 * @brief   convert your height in inches to centimeter
 */

#include <stdio.h>

int main(void)
{
  float inch;
  printf("Input your height in inches: ");
  scanf("%f", &inch);

  printf("You are %.1f inches tall or %.1f centimeters equivalently.\n",
         inch, 2.54 * inch);

  return 0;
}
