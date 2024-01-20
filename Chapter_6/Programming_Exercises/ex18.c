/**
 * @file    ex18.c
 */
#include <stdio.h>

int main(void)
{
  int friends = 5;
  int week_count = 0;

  while (friends <= 150)
  {
    friends = (friends - ++week_count) * 2;
    printf("After %d weeks, Rabnud's friend count is %d\n", week_count, friends);
  }


  return 0;
}
