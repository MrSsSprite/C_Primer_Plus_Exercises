/**
 * @file    ex6.c
 */
#include <stdio.h>

int main(void)
{
  int low_bound, up_bound;

  printf("Input the lower and upper limits: ");
  scanf("%d %d", &low_bound, &up_bound);

  if (low_bound < 0 || up_bound < 0)
  {
    printf("Both limits must be positive!\n");
    return 1;
  }
  if (low_bound > up_bound)
  {
    printf("Lower limit cannot exceed upper limit!\n");
    return 1;
  }

  printf("%6s %6s %6s\n", "Value", "Square", "Cube");

  for (int i = low_bound; i <= up_bound; i++)
    printf("%6d %6d %6d\n", i, i*i, i*i*i);

  return 0;
}
