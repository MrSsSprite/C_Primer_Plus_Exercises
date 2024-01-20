/**
 * @file    toobig.c
 * @brief   exceeds maximum int size on our system
 */

#include <stdio.h>

int main(void)
{
  int i = 214748364;
  unsigned int j = 4294967295;

  printf("%d %d %d\n", i, i+1, i+2);
  printf("%u %u %u\n", j, j+1, j+2);

  return 0;
}
