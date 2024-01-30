/**
 * @file    ex8.c
 * @brief   find a string in another string
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_in(const char *body, const char *pattern);
char *get_string(void);
char *get_line(void);

int main(void)
{
  char *body, *pattern;
  char *ptr, *iter, *iter_ed;

  while (printf("Input a block of text (empty line to finish the input, EOF to quit):\n"),
         (body = get_string()) && !feof(stdin))
  {
    // get pattern
    while (printf("Input a pattern to search for (<enter> to finish):\n"),
           pattern = get_line())
    {
      if (pattern[0] == '\0')
        printf("Cannot Search for an empty pattern.\n");
      else
        break;
    }
    if (pattern == NULL)
    {
      // clean the remnant
      free(body);
      fprintf(stderr, "Error: Fail to allocate memory for pattern.\n");
      exit(-1);
    }

    ptr = string_in(body, pattern);
    if (ptr)
    {
      printf("The pattern start at the character #%td in the text.\n",
             ptr - body + 1);
      for (iter = body; iter < ptr; iter++)
        putchar(*iter);
      putchar('{');
      for (iter_ed = ptr + strlen(pattern); iter < iter_ed; iter++)
        putchar(*iter);
      putchar('}');
      while (*iter)
        putchar(*iter++);
    }
    else
      printf("The pattern is not found in the text.\n");

    free(body);
    free(pattern);
  }

  return 0;
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

int try_match(const char *body, const char *pattern)
{
  while (*pattern)
    if (*pattern++ != *body++)
      return 0;
  return 1;
}

char *string_in(const char *body, const char *pattern)
{
  while (*body)
  {
    if (*body == *pattern && try_match(body, pattern))
      return (char*) body;
    body++;
  }
  return NULL;
}
