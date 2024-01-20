/**
 * @file    ex8.c
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  float a, b;
  
  printf("Input 2 floating-point numbers: ");
  scanf("%f %f", &a, &b);

  printf("The value of their difference divided by their product is %f\n",
         (double) abs(a - b) / (a * b));

  return 0;
}
