/**
 * @file    for_cube.c
 * @brief   using a for loop to make a table of cubes
 */
#include <stdio.h>

int main(void)
{
  int num;

  printf("%8s | %s\n", "n", "n cubed");
  for (num = 1; num <= 5; num++)
    printf("%8d | %d\n", num, num * num * num);

  return 0;
}
