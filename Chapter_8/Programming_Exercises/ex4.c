/**
 * @file    ex4.c
 * @brief   read till EOF and then report the average # of letters per word.
 */
#include <ctype.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

int main(void)
{
  size_t letter_ct = 0, word_ct = 0;
  bool in_word = false;
  char ch;

  while ((ch = getchar()) != EOF)
  {
    if (isalpha(ch))
    {
      letter_ct++;
      in_word = true;
    }
    else if (isspace(ch) && in_word)
    {
      in_word = false;
      word_ct++;
    }
  }
  // handle the last word
  if (in_word)
    word_ct++;

  printf("Letters per Word: ");
  if (word_ct == 0)
    printf("Not Applicable (No word)");
  else
    printf("%.2f", (double)letter_ct / word_ct);
  printf("\n");

  return 0;
}
