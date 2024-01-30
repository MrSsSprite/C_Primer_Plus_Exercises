/**
 * @file    ex6.c
 * @brief   write a function that tests if a given char is with in the string, 
 *          and test it
 */
#include <stdio.h>
#include <stdlib.h>

int is_within(const char *str, char c);
char *get_string(void);

int main(void)
{
  char *string;
  char ch;

  while (printf("In put a string in one line (empty line to quit):\n"),
         string = get_string())
  {
    if (string[0] == '\0')
    {
      free(string);
      break;
    }
    printf("Your Input:\n\"%s\"\n", string);
    printf("Input a character: ");
    while ((ch = getchar()) != EOF && ch == '\n')
      continue;
    if (ch == EOF)
    {
      free(string);
      printf("End-of-File detected. Ending the function...\n");
      break;
    }
    printf("The character %c is %sfound in the string.\n",
           ch, is_within(string, ch) ? "" : "not ");
    
    while ((ch = getchar()) != EOF && ch != '\n')
      continue;
    free(string);
  }

  return 0;
}

int is_within(const char *str, char c)
{
  while (*str)
  {
    if (*str == c)
      return 1;
    str++;
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
