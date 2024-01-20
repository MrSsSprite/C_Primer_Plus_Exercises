/**
 * @file    ex2.c
 * @brief   prompt for an int and output count numbers starting from the input int
 */
#include <stdio.h>

#define COUNT 10

int main(void)
{
  int val;

  printf("Input an Integer: ");
  scanf("%d", &val);

  for (int i = 0; i <= 10; i++)
    printf("%-4d", val + i);

  printf("\n");

  return 0;
}
