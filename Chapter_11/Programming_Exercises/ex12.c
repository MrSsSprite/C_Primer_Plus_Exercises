/**
 * @file    ex12.c
 * @brief   read input and the # of word, upper,lower case letter,
 *          punctuation letter, and digits
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int ch;
  int in_word = 0;
  enum type { word = 0, upper, lower, punc, dig };
  unsigned int counts[dig + 1];

  // initialize counts
  for (enum type i = word; i <= dig; i++)
    counts[i] = 0;

  printf("Please input a block of text (EOF to end):\n");

  while ((ch = getchar()) != EOF)
  {
    // handle character
    if (islower(ch))
      counts[lower]++;
    else if (isupper(ch))
      counts[upper]++;
    else if (isdigit(ch))
      counts[dig]++;
    else if (ispunct(ch))
      counts[punc]++;

    // handle word
    if (isspace(ch))
    {
      if (in_word)
      {
        counts[word]++;
        in_word = 0;
      }
    }
    else
      in_word = 1;
  }
  // last word
  if (in_word)
    counts[word]++;

  printf("The text has:\n");
  printf("%u words, %u uppercase letters, %u lowercase letters,\n",
         counts[word], counts[upper], counts[lower]);
  printf("%u punctuation characters, and %u digits\n",
         counts[punc], counts[dig]);

  return 0;
}
