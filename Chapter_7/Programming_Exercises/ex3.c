/**
 * @file    ex3.c
 * @brief   read integers until 0, report the average of the even ones and odd
 * ones
 */
#include <stdio.h>

int main(void)
{
  long even_sum = 0L, odd_sum = 0L;
  int even_cnt = 0, odd_cnt = 0;
  int value;

  while (printf("Input an integer: "),
         scanf("%d", &value) == 1 && value != 0)
  {
    if (value % 2) // odd value
    {
      odd_cnt++;
      odd_sum += value;
    }
    else
    {
      even_cnt++;
      even_sum += value;
    }
  }

  printf("There are %d even numbers and %d odd numbers.\n", even_cnt, odd_cnt);
  printf("The average of even number is %d, and\n", even_sum / even_cnt);
  printf("The average of odd number is %d.\n", odd_sum / odd_cnt);

  return 0;
}
