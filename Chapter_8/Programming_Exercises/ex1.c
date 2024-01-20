/**
 * @file    ex1.c
 * @brief   read the # of characters till EOF
 */
#include <stdio.h>
#include <stddef.h>

int main(void)
{
  size_t count = 0;

  while (getchar() != EOF)
    count++;

  printf("Total character in the stream: %zd\n", count);

  return 0;
}
