/**
 * @file    ex6.c
 * @brief   rewrite Listing 13.2 (reducto.c) so that it prompts for input instead
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * get_word(void);

int main(int argc, char **argv)
{
  FILE *infile, *outfile;
  char *inpath, *outpath;
  size_t len;
  int ch;
  int count = 0;

  printf("Enter the input file: ");
  if ((inpath = get_word()) == NULL)
  {
    fputs("Failed to allocate memory for inpath.\n", stderr);
    exit(-1);
  }
  if ((infile = fopen(inpath, "r")) == NULL)
  {
    fprintf(stderr, "Failed to open %s for reading.\n", inpath);
    free(inpath);
    exit(1);
  }
  if ((outpath = malloc((len = strlen(inpath)) + 5)) == NULL)
  {
    fputs("Failed to allocate memory for outpath.\n", stderr);
    exit(-1);
  }
  strcpy(outpath, inpath);
  strcat(outpath + len, ".red");
  if ((outfile = fopen(outpath, "w")) == NULL)
  {
    fprintf(stderr, "Failed to open %s for writing.\n", outpath);
    free(inpath);
    fclose(infile);
    free(outpath);
    exit(1);
  }

  // copy data
  while ((ch = getc(infile)) != EOF)
    if (count++ % 3 == 0)
      putc(ch, outfile);

  if (fclose(infile) || fclose(outfile))
    fputs("Error in closing files.\n", stderr);
  free(inpath);
  free(outpath);

  return 0;
}

char * get_word(void)
{
  size_t cap = 1;
  char *st = malloc(cap), *cav = st, *term = st + cap;
  char *temp;
  int ch;

  if (st == NULL)
    return NULL;

  while ((ch = getchar()) != EOF && isspace(ch))
    continue;

  if (ch != EOF)
    *cav++ = ch;

  while ((ch = getchar()) != EOF && !isspace(ch))
  {
    if (cav == term)
    {
      temp = realloc(st, cap * 2);
      if (temp == NULL)
      {
        free(st);
        return NULL;
      }
      st = temp;
      cav = st + cap;
      term = st + (cap *= 2);
    }

    *cav++ = ch;
  }

  if (cav == term)
  {
    temp = realloc(st, cap + 1);
    if (temp == NULL)
    {
      free(st);
      return NULL;
    }
    st = temp;
    cav = st + cap;
  }
  *cav = '\0';

  if (ch != '\n')
    while ((ch = getchar()) != EOF && ch != '\n')
      continue;

  return st;
}
