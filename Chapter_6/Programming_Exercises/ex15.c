/**
 * @file    ex15.c
 * @brief   read a line and print in reverse order
 */
#include <stdio.h>

int main(void)
{
  char line[255], *ptr = line;

  printf("Enter a sentence:\n");
  while (scanf("%c", ptr) == 1)
    if (*ptr == '\n')
    {
      *ptr = '\0';
      break;
    }
    else
      ptr++;

  if (*ptr != '\0')
  {
    printf("Error Occured\n");
    return 1;
  }

  ptr--;
  while (ptr >= line)
    printf("%c", *ptr--);

  return 0;
}
