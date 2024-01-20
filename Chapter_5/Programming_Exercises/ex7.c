/**
 * @file    ex7.c
 * @brief   prompt for a double and print the cube of it
 */
#include <stdio.h>

void print_cube(double value);

int main(void)
{
  double value;

  printf("Input a floating-point number: ");
  scanf("%lf", &value);
  print_cube(value);

  return 0;
}

void print_cube(double value)
{
  printf("%f\n", value * value * value);
}
