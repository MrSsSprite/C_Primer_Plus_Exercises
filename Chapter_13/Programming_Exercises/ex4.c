/**
 * @file    ex4.c
 * @brief   print the contents of files in command line arguments
 */
#include <stdio.h>

int main(int argc, char **argv)
{
  FILE *infile;
  int ch;

  if (argc == 1)
  {
    printf("Usage: %s [filename]...\n", argv[0]);
    return 1;
  }

  for (int i = 1; i < argc; i++)
  {
    for (int j = 0; j < 80; j++)
      putchar('=');
    putchar('\n');

    if ((infile = fopen(argv[i], "r")) == NULL)
    {
      printf("Failed to open file #%d (%s).\n", i, argv[i]);
      continue;
    }

    // print header
    printf("// File #%d (%s)\n", i, argv[i]);

    // print content
    while ((ch = getc(infile)) != EOF)
      putchar(ch);
    putchar('\n');

    fclose(infile);
  }

  return 0;
}
