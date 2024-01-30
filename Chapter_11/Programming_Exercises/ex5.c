/**
 * @file    ex5.c
 * @brief   write my implementation of strchr
 */
#include <stdio.h>
#include <stdlib.h>

char *find_c(const char *str, int c);
char *get_string(void);

int main(void)
{
  char *string, *ptr;
  char ch;

  while (printf("Input a sentence (empty line to quit):\n"),
         string = get_string())
  {
    if (string[0] == '\0')
    {
      free(string);
      break;
    }
    printf("Your Input: \"%s\"\n", string);
    printf("Input a character to wipe the character(s) before: ");
    while ((ch = getchar()) != EOF && ch == '\n')
      continue;
    if (ch == EOF)
    {
      free(string);
      break;
    }
    ptr = find_c(string, ch);
    if (ptr)
      printf("The result sentence:\n%s\n", ptr);
    else
      printf("'%c' Not Found!\n", ch);
    while ((ch = getchar()) != EOF && ch != '\n')
      continue;
    free(string);
  }

  return 0;
}

char *get_string(void)
{
  size_t capacity = 1;
  char *string = malloc(capacity), *cavity = string, *terminal = string + 1;
  int ch;

  if (string == NULL)
    return string;

  while ((ch = getchar()) != EOF && ch != '\n')
  {
    if (cavity == terminal)
    {
      if ((string = reallocf(string, capacity * 2)) == NULL)
        return string;
      cavity = string + capacity;
      terminal = string + (capacity *= 2);
    }
    *cavity++ = ch;
  }
  if (cavity == terminal)
  {
    if ((string = reallocf(string, capacity + 1)) == NULL)
      return string;
    cavity = string + capacity;
  }
  *cavity = '\0';

  return string;
}

char *find_c(const char *str, int c)
{
  char *ptr = (char*) str;
  while (*ptr)
  {
    if (*ptr == c)
      return ptr;
    ptr++;
  }
  return NULL;
}
