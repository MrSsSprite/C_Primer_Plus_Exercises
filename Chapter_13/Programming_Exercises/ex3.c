/**
 * @file    ex3.c
 * @brief   copy content but all toupper
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char * get_line(FILE *fp);
int get_first_char(FILE *fp);
int file_exists(const char *filename);

int main(void)
{
  FILE *infile, *outfile;
  char *inpath, *outpath;
  char *temp;
  int ch;
  int status;
  unsigned long ch_count = 0;

  while (printf("Enter source file: "),
      (infile = fopen(inpath = get_line(stdin), "r")) == NULL)
  {
    printf("Invalid File path. Please Retry.\n");
    free(inpath);
    if (feof(stdin))
    {
      printf("EOF Detected. Closing the Program.\n");
      exit(1);
    }
  }
  while (printf("Enter output file: "),
         (status = file_exists(outpath = get_line(stdin)))
         || (outfile = fopen(outpath, "w")) == NULL)
  {
    if (status)
    {
      printf("File already exist.\n"
             "[r]: replace, [a]: append, [n]: reinput file path\n"
             "Your Choice: ");
      switch (get_first_char(stdin))
      {
      case 'r':
        printf("Opening %s in \"w\" mode\n", outpath);
        if ((outfile = fopen(outpath, "w")) == NULL)
          goto open_failed;
        goto outfile_finished;
      case 'a':
        printf("Opening %s in \"a\" mode\n", outpath);
        
        if ((outfile = fopen(outpath, "a")) == NULL)
          goto open_failed;
        goto outfile_finished;
      case 'n':
        free(outpath);
        continue;
      default:
        fprintf(stderr, "Invalid Command Detected. Closing the Program...\n");
        free(inpath);
        if (fclose(infile))
          fprintf(stderr, "Failed to close infile\n");
        free(outpath);
        exit(1);
      }
    }
    else
    {
open_failed:
      printf("Can't open %s for writing. Please try another file.\n", outpath);
      free(outpath);
    }
  }
outfile_finished:

  // content copy
  while ((ch = getc(infile)) != EOF)
    if (putc(toupper(ch), outfile) == EOF)
    {
      fprintf(stderr, "Error occurred when writing to output file.\n");
      free(inpath);
      fclose(infile);
      free(outpath);
      fclose(outfile);
      exit(2);
    }
    else
      ch_count++;

  printf("%lu characters are copied from %s to %s.\n",
         ch_count, inpath, outpath);

  free(inpath);
  free(outpath);
  fclose(infile);
  fclose(outfile);
  return 0;
}

char * get_line(FILE *fp)
{
  size_t cap = 1;
  char *st = malloc(cap), *cav = st, *term = st + cap;
  char *temp;
  int ch;

  if (st == NULL)
    return NULL;

  while ((ch = getc(fp)) != EOF && ch != '\n')
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

  return st;
}

int get_first_char(FILE *fp)
{
  int ret;
  int ch;

  while ((ret = getc(fp)) != EOF && isspace(ret))
    continue;

  while ((ch = getc(fp)) != EOF && ch != '\n')
    continue;

  return ret;
}

int file_exists(const char *filename)
{
  FILE *file = fopen(filename, "r");
  if (file)
  {
    fclose(file);
    return 1;
  }
  return 0;
}
