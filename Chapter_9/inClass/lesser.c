/**
 * @file    lesser.c
 * @brief   finds the lesser of two evils
 */
#include <stdio.h>

int imin(int, int);

int main(void)
{
  int evil0, evil1;

  printf("Enter a pair of integers (q to quit):\n");
  while (scanf("%d %d", &evil0, &evil1) == 2)
  {
    printf("The lesser of %d and %d is %d.\n",
           evil0, evil1, imin(evil0, evil1));
    printf("Enter a pair of integers (q to quit):\n");
  }
  printf("Bye.\n");

  return 0;
}

int imin(int n, int m)
{
  int min;

  if (n < m)
    min = n;
  else
    min = m;

  return min;
}
