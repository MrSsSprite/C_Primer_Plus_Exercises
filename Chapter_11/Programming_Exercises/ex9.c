/**
 * @file    ex9.c
 * @brief   reverse the string
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str);
char *get_string(void);

int main(void)
{
  char *string;

  while (printf("Input a block of text (empty line to finish input, EOF to quit):\n"),
         (string = get_string()) && !feof(stdin))
  {
    reverse(string);
    printf("The reversed version:\n%s\n", string);

    free(string);
  }

  return 0;
}

void reverse(char *str)
{
  char *iter = str + strlen(str) - 1;
  char temp;

  while (str < iter)
  {
    *str ^= *iter;
    *iter ^= *str;
    *str++ ^= *iter--;
  }
}

char *get_string(void)
{
  size_t cap = 1;
  char *string = malloc(cap), *cavity = string, *terminal = string + cap;
  int ch, prev;

  if (string == NULL)
    return string;

  while ((ch = getchar()) != EOF)
  {
    if (ch == '\n' && prev == '\n')
      break;
    // check for enough space
    if (cavity == terminal)
    {
      string = reallocf(string, cap * 2);
      if (string == NULL)
        return string;
      cavity = string + cap;
      terminal = string + (cap *= 2);
    }
    
    // assign value
    *cavity++ = ch;
    prev = ch;
  }
  
  // assign nul at the end
  if (cavity == terminal)
  {
    if ((string = reallocf(string, cap + 1)) == NULL)
      return string;
    cavity = string + cap;
  }
  *cavity = '\0';

  return string;
}
