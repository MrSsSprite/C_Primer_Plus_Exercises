/**
 * @file    ex17.c
 */
#include <stdio.h>

int main(void)
{
  double balance = 1e6;
  int year_count = 0;

  while (balance > 0)
  {
    balance -= 100e3;
    balance *= 1.08;
    year_count++;
  }

  printf("It takes %d years for Chuckie to empty his account.\n", year_count);

  return 0;
}
