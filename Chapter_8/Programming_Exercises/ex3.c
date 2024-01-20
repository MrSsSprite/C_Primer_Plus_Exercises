/**
 * @file    ex3.c
 * @brief   report the numbers of uppercase letter, lowercase letter, and other 
 *          characters in the stdin stream.
 */
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>

int main(void)
{
  size_t up_ct = 0, low_ct = 0, other_ct = 0;
  int ch;

  while ((ch = getchar()) != EOF)
  {
    if (isupper(ch))
      up_ct++;
    else if (islower(ch))
      low_ct++;
    else
      other_ct++;
  }

  printf("Uppercase Letter: %d\n", up_ct);
  printf("Lowercase Letter: %d\n", low_ct);
  printf("Other Characters: %d\n", other_ct);

  return 0;
}
