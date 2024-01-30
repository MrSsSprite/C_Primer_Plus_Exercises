/**
 * @file    ex13.c
 * @brief   print command-line arguments in reverse order
 */
#include <stdio.h>

int main(int argc, char **argv)
{
  int first_word = 1;
  if (argc < 2)
  {
    printf("Usage: %s ...\n(at least one argument required)\n", argv[0]);
    return 1;
  }

  for (int i = argc - 1; i > 0; i--)
  {
    if (first_word)
      first_word = 0;
    else
      putchar(' ');
    fputs(argv[i], stdout);
  }
  putchar('\n');

  return 0;
}
