/**
 * @file    ex1.c
 * @brief   converts time in minutes to in hours and min.
 */
#include <stdio.h>

#define MIN_PER_H 60

int main(void)
{
  int total_min, hour, min;

  do
  {
    // prompt for input
    printf("Input the total time in minutes (or 0 to leave): ");
    scanf("%d", &total_min);

    // leave check
    if (total_min <= 0) break;

    // computation
    hour = total_min / MIN_PER_H;
    min = total_min % MIN_PER_H;

    // print result
    printf("%d minutes is %d hours and %d minutes\n", total_min, hour, min);
  }
  while (1);

  return 0;
}
