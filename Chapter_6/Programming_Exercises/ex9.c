/**
 * @file    ex9.c
 */
#include <stdio.h>
#include <stdlib.h>

double process(float a, float b);

int main(void)
{
  float a, b;
  
  printf("Input 2 floating-point numbers: ");
  scanf("%f %f", &a, &b);

  printf("The value of their difference divided by their product is %f\n",
         process(a, b));
  return 0;
}

double process(float a, float b)
{
  return (double) abs(a - b) / (a * b);
}
