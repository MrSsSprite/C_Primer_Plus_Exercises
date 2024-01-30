/**
 * @file    ex3.c
 * @brief   a function that read the first word and discard the rest of the line
 */
#include <stdio.h>
#include <ctype.h>

// get the first word and discard the rest of the line, 
// returns the terminating char inserted
char *get_word(char *restrict str, int size);

int main(void)
{
  char string[50];
  
  while (printf("Input a word (EOF to leave):\n"),
         get_word(string, 50))
    printf("the word is: %s\n", string);

  return 0;
}

char *get_word(char *restrict str, int size)
{
  char *const term = str + size - 1;
  int ch;

  // skip preceding whitespaces
  while ((ch = getchar()) != EOF && isspace(ch))
    continue;
  // handle the last ch
  if (ch != EOF && str < term)
    *str++ = ch;
  else
    return NULL;

  while (str < term && (ch = getchar()) != EOF && !isspace(ch))
    *str++ = ch;

  *str = '\0';

  // if EOF or newline, free to go
  // otherwise, consume the rest
  if (!(ch == '\n' || ch == EOF))
    while (getchar() != '\n')
      continue;
  return str;
}
