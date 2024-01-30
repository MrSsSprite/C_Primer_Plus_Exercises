/**
 * @file    ex16.c
 * @brief   read input and print with either 
 *          the same input, all char toupper, or all char tolower
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define USAGE "Usage: %s [-p | -u | -l]\n"

enum modes { normal, upper, lower };

char * get_string(void);

int main(int argc, char **argv)
{
  enum modes mode = normal;
  char *string;

  if (argc > 2)
  {
    fprintf(stderr, USAGE, argv[0]);
    return 1;
  }
  if (argc == 2)
  {
    if (argv[1][0] != '-' || argv[1][2] != '\0')
    {
      fprintf(stderr, USAGE, argv[0]);
      return 1;
    }
    switch (argv[1][1])
    {
    case 'p': break;
    case 'u': mode = upper;
              break;
    case 'l': mode = lower;
              break;
    default:
              fprintf(stderr, USAGE, argv[0]);
              return 1;
    }
  }

  // read input
  printf("Input a block of string (EOF to finish):\n");
  string = get_string();
  printf("Input finished.\n");
  for (int i = 0; i < 80; i++)
    putchar('=');
  putchar('\n');

  // display output
  printf("The Converted String:\n");
  for (const char *ptr = string; *ptr; ptr++)
    switch (mode)
    {
    case normal: putchar(*ptr);
                 break;
    case upper : putchar(toupper(*ptr));
                 break;
    case lower : putchar(tolower(*ptr));
                 break;
    }
  printf("Output finished.\n");
  for (int i = 0; i < 80; i++)
    putchar('=');
  putchar('\n');

  free(string);
  return 0;
}

char * get_string(void)
{
  size_t cap = 1;
  char *string = malloc(cap), *cavity = string, *terminal = string + cap;
  int ch;

  if (string == NULL)
    return string;

  while ((ch = getchar()) != EOF)
  {
    // guarantee enough space
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
