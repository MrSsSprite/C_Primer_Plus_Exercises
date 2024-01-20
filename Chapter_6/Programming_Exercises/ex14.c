/**
 * @file    ex14.c
 * @brief   get nums and calculate cumulative total
 */
#include <stdio.h>

#define SIZE 8

int main(void)
{
  double inputs[SIZE], cumulative[SIZE];

  printf("Input %d numbers (could be floating-point): ", SIZE);
  for (int i = 0; i < SIZE; i++)
    if (scanf("%lf", inputs + i) == 0)
    {
      printf("Invalid Input detected!\n");
      return 1;
    }

  cumulative[0] = inputs[0];
  for (int i = 1; i < SIZE; i++)
    cumulative[i] = cumulative[i - 1] + inputs[i];

  for (int i = 0; i < SIZE; i++)
    printf("%8.2f ", inputs[i]);
  printf("\n");
  for (int i = 0; i < SIZE; i++)
    printf("%8.2f ", cumulative[i]);
  printf("\n");

  return 0;
}
