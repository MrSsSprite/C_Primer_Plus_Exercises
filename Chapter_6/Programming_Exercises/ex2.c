/**
 * @file    ex2.c
 */
#include <stdio.h>

int main(void)
{
  for (int row = 1; row <= 5; row++) {
    for (int column = 0; column < row; column++)
      printf("$");
    printf("\n");
  }

  return 0;
}
