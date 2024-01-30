/**
 * @file    ex2.c
 * @brief   modify ex1.c so that it also stop after whitespace character
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getnchar(char *restrict str, int n);

int main(void)
{
  char str[5];
  int status;

  while ((status = getnchar(str, 5)) != -1)
  {
    printf("================================\n");
    printf("%d characters read:\n", status - 1);
    printf("%s\n", str);
    printf("================================\n");
  }
  if (status != -1)
  {
    printf("================================\n");
    printf("%d characters read:\n", status - 1);
    printf("%s\n", str);
    printf("================================\n");
  }
  
  return 0;
}

int getnchar(char *restrict str, int n)
{
  int ch;
  int counter = 0;

  if (n == 0)
    return 0;

  while (counter < n - 1 && (ch = getchar()) != EOF)
  {
    *str++ = ch;
    counter++;
    if (isspace(ch))
      break;
  }
  *str = '\0';
  counter++;

  return ch == EOF ? -1 : counter;
}
