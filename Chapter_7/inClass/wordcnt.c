/**
 * @file    wordcnt.c
 * @brief   counts characters, words, and lines
 */
#include <stdio.h>
#include <ctype.h>      // for isspace()
#include <stdbool.h>    // for bool, true, and false

#define STOP '|'

int main(void)
{
  char c;               // read in character
  char prev;            // previous character read
  long n_chars = 0L;    // number of characters
  int n_lines = 0;      // number of lines
  int n_words = 0;      // number of words
  int p_lines = 0;      // number of partial lines
  bool inword = false;  // == true if c is in word

  printf("Enter text to be analyzed (| to terminate):\n");
  prev = '\n';
  while ((c = getchar()) != STOP)
  {
    n_chars++;        // count characters
    if (c == '\n')    // count lines
      n_lines++;
    if (!isspace(c) && !inword)
    {
      inword = true;  // starting a new word
      n_words++;      // count word
    }
    if (isspace(c) && inword)
      inword = false; // reached end of word
    prev = c;
  }

  if (prev != '\n')
    p_lines = 1;
  printf("characters = %ld, words = %d, lines = %d, ",
         n_chars, n_words, n_lines);
  printf("partial lines = %d\n", p_lines);

  return 0;
}
