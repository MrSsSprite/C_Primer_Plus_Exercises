/**
 * @file    ex1.c
 * @brief   a function that fetches the next n characters from input, and driver
 */
#include <stdio.h>
#include <stdlib.h>

int getnchar(char *restrict str, int size);

int main(void)
{
  char *str = malloc(2);
  int counter = 2;
  int status;

  while ((status = getnchar(str, counter)) == counter)
  {
    printf("================================\n");
    printf("%d characters read:\n", status - 1);
    printf("%s\n", str);
    printf("================================\n");
    str = realloc(str, counter = (counter - 1) * 2 + 1);
  }
  if (status)
  {
    printf("================================\n");
    printf("%d characters read:\n", status - 1);
    printf("%s\n", str);
    printf("================================\n");
  }

  free(str);

  return 0;
}

int getnchar(char *restrict str, int size)
{
  int ch;
  int counter = 0;

  while (counter < size - 1 && (ch = getchar()) != EOF)
  {
    *str++ = ch;
    counter++;
  }
  *str = '\0';
  counter++;

  return counter;
}
