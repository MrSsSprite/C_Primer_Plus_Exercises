/**
 * @file    ex1.c
 * @brief   an array of 26 lowercase letters
 */
#include <stdio.h>

int main(void)
{
  char letters[26];

  for (char c = 'a'; c <= 'z'; c++)
    letters[c - 'a'] = c;

  for (int idx = 0; idx < 26; idx++)
    printf("%c ", letters[idx]);
  printf("\n");

  return 0;
}
