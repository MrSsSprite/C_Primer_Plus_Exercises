/**
 * @file    ex3.c
 * @brief   prompt for the number of days and convert to weeks + days
 */
#include <stdio.h>

#define DAY_PER_WEEK 7

int main(void)
{
  int total_days, weeks, days;

  do
  {
    printf("Input the total number of days: ");
    scanf("%d", &total_days);

    if (total_days <= 0) break;

    weeks = total_days / DAY_PER_WEEK;
    days = total_days % DAY_PER_WEEK;
    printf("%d days are %d weeks, %d days.\n", total_days, weeks, days);
  }
  while (1);

  return 0;
}
