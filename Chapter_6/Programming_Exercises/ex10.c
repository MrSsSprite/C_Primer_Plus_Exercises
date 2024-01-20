/**
 * @file    ex10.c
 * @brief   sum of squares in a range
 */
#include <stdio.h>

long sum_of_squares(int a, int b);

int main(void)
{
  int a, b;

  while (printf("Enter lower and upper integer limits (q to quit): "),
         scanf("%d %d", &a, &b) == 2)
  {
    if (a < 1 || b < 1)
    {
      printf("Both values must be positive!\n");
      continue;
    }
    if (a > b)
    {
      a ^= b;     // a = a ^ b
      b ^= a;     // b = b ^ (a ^ b) = b^b ^ a = 0 ^ a = a
      a ^= b;     // a = (a ^ b) ^ a = a^a ^ b = 0 ^ b = b
    }

    printf("The sum of the squares from %d to %d is %ld\n", a, b, sum_of_squares(a, b));
  }

  return 0;
}

long sum_of_squares(int a, int b)
{
  int sum = 0;
  for (int i = a; i <= b; i++)
    sum += i * i;

  return sum;
}
