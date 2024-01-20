/**
 * @file    ex5.c
 * @brief   prompt for 2 ints, n and m, print the sum from n to n+m
 */
#include <stdio.h>

int main(void)
{
  int n, m;
  int result = 0;

  printf("Input 2 positive integers (separated by space): ");
  scanf("%d %d", &n, &m);

  printf("The sum (from %d to %d+%d(or equivalently %d)) = ", n, n, m, n + m);

  while (m-- >= 0)
    result += n++;

  printf("%d\n", result);

  return 0;
}
