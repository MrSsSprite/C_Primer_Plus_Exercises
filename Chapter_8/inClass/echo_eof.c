/**
 * @file    echo_eof.c
 * @brief   repeats input to end of file
 */
#include <stdio.h>

int main(void)
{
  int ch;

  while ((ch = getchar()) != EOF)
    putchar(ch);

  return 0;
}
