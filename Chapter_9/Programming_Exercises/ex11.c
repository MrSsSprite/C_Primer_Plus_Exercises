/**
 * @file    ex11.c
 * @brief   calculate Fibonacci Number
 */
#include <stdio.h>

unsigned long Fibonacci(unsigned n);

int main(void)
{
  unsigned int n;

  while (printf("Input a positive integer: "),
         scanf("%u", &n) == 1)
    printf("The %uth Fibonacci number is %lu\n",
           n, Fibonacci(n));

  printf("Bye.\n");

  return 0;
}

unsigned long Fibonacci(unsigned n)
{
  unsigned long curr = 1, prev = 1;
  unsigned long temp;

  for (int i = 3; i <= n; i++)
  {
    temp = curr;
    curr += prev;
    prev = temp;
  }

  return curr;
}
