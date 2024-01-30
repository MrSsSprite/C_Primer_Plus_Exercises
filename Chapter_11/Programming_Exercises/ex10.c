/**
 * @file    ex10.c
 * @brief   remove space function
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void rm_space(char *str);
char *get_line(void);

int main(void)
{
  char *string;

  while (printf("Input a line of string (empty line to quit):\n"),
         string = get_line())
  {
    // empty line
    if (string[0] == '\0')
    {
      free(string);
      break;
    }

    rm_space(string);
    printf("Same string with all space removed:\n%s\n", string);

    free(string);
  }

  return 0;
}

void rm_space(char *str)
{
  size_t gap = 0;

  for (; *str; str++)
  {
    if (isspace(*str))
    {
      gap++;
      continue;
    }
    if (gap)
      *(str - gap) = *str;
  }

  *(str - gap) = '\0';
}

char *get_line(void)
{
  size_t cap = 1;
  char *string = malloc(cap), *cavity = string, *terminal = string + cap;
  int ch;

  if (string == NULL)
    return string;

  while ((ch = getchar()) != EOF && ch != '\n')
  {
    // check for enough space
    if (cavity == terminal)
    {
      string = reallocf(string, cap * 2);
      if (string == NULL)
        return string;
      cavity = string + cap;
      terminal = string + (cap *= 2);
    }

    *cavity++ = ch;
  }

  if (cavity == terminal)
  {
    string = reallocf(string, cap + 1);
    if (string == NULL)
      return string;
    cavity = string + cap;
  }

  *cavity = '\0';

  return string;
}
