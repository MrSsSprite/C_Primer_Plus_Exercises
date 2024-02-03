/**
 * @file    ex5.c
 * @brief   append a file to another
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096

void append(FILE *source, FILE *dest);

int main(int argc, char **argv)
{
  FILE *infile, *outfile;
  int source_ct = 0;
  int ch;

  if (argc < 3)
  {
    fprintf(stderr, "Usage: %s output_file input_file...\n", argv[0]);
    exit(1);
  }
  if ((outfile = fopen(argv[1], "a+")) == NULL)
  {
    fprintf(stderr, "Can't open %s for reading and appending.\n", argv[1]);
    exit(1);
  }
  if (setvbuf(outfile, NULL, _IOFBF, BUFSIZE))
  {
    fputs("Can't create output buffer.\n", stderr);
    exit(-1);
  }
  
  for (int i = 2; i < argc; i++)
  {
    printf("Appending file #%d (%s)...\n", i - 1, argv[i]);
    if (strcmp(argv[1], argv[i]) == 0)
    {
      fputs("\tError: Can't append file to itself.\n", stderr);
      continue;
    }
    if ((infile = fopen(argv[i], "r")) == NULL)
    {
      fputs("\tError: Can't open the file for reading.\n", stderr);
      continue;
    }
    if (setvbuf(infile, NULL, _IOFBF, BUFSIZE))
    {
      fputs("\tError: Can't create input buffer\n", stderr);
      continue;
    }
    append(infile, outfile);
    if (ferror(infile))
      fprintf(stderr, "\tError in reading %s.\n", argv[i]);
    if (ferror(outfile))
      fprintf(stderr, "\tError in writing to %s.\n", argv[1]);
    
    fclose(infile);
    source_ct++;
    printf("\tFile %s appended.\n", argv[i]);
  }
  printf("Done appending. %d files append.\n", source_ct);
  rewind(outfile);
  printf("%s contents:\n", argv[1]);
  while ((ch = getc(outfile)) != EOF)
    putchar(ch);
  fputs("Done Displaying.\n", stdout);
  fclose(outfile);

  return 0;
}

void append(FILE *source, FILE *dest)
{
  size_t bytes;
  static char temp[BUFSIZE];

  while ((bytes = fread(temp, sizeof (char), BUFSIZE, source)) > 0)
    fwrite(temp, sizeof (char), bytes, dest);
}
