/**
 * @file    ex4.c
 */
#include <stdio.h>

int main(void)
{
  char c = 'A';
  for (int row = 0; row < 6; row++)
  {
    for (int col = 0; col <= row; col++)
      printf("%c", c++);
    printf("\n");
  }

  return 0;
}
