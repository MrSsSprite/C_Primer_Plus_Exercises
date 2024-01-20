/**
 * @file    ex13.c
 */
#include <stdio.h>

#define SIZE 8

int main(void)
{
  int pow_of_2s[SIZE];

  for (int i = 0; i < SIZE; i++)
  {
    pow_of_2s[i] = 1;
    for (int j = 0; j < i; j++)
      pow_of_2s[i] *= 2;
  }

  int idx = 0;
  do
  {
    printf("%4d ", pow_of_2s[idx]);
  }
  while (++idx < SIZE);
  printf("\n");

  return 0;
}
