/**
 * @file    ex10.c
 * @brief   jump in a file and display the line.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char * get_line(FILE *file);
void print_line(FILE *dest, FILE *source);

int main(void)
{
  FILE *file;
  char *filename;
  long int offset;

  printf("Input the filename: ");
  if ((filename = get_line(stdin)) == NULL)
  {
    fputs("Failed to allocate memory for filename.\n", stderr);
    exit(-1);
  }
  if ((file = fopen(filename, "r")) == NULL)
  {
    fprintf(stderr, "Failed to open %s for reading.\n", filename);
    exit(1);
  }

  while (fputs("Enter offset (negative to quit): ", stdout),
         scanf("%ld", &offset) == 1 && offset >= 0)
  {
    if (fseek(file, offset, SEEK_SET))
    {
      fprintf(stderr, "Failed to jump to the character #%ld.\n", offset);
      continue;
    }
    print_line(stdout, file);
  }

  fputs("Done.\n", stdout);

  return 0;
}

char * get_line(FILE *file)
{
  size_t cap = 1;
  char *string = malloc(cap), *cavity = string, *terminal = string + cap;
  char *temp;
  int ch;

  if (string == NULL)
    return NULL;

  // skip preceding spaces
  while ((ch = getc(file)) != EOF && isspace(ch))
    continue;
  if (ch != EOF)
    *cavity++ = ch;

  while ((ch = getc(file)) != EOF && ch != '\n')
  {
    if (cavity == terminal)
    {
      temp = realloc(string, cap * 2);
      if (temp == NULL)
      {
        free(string);
        return NULL;
      }
      string = temp;
      cavity = string + cap;
      terminal = string + (cap *= 2);
    }

    *cavity++ = ch;
  }

  if (cavity == terminal)
  {
    temp = realloc(string, cap + 1);
    if (temp == NULL)
    {
      free(string);
      return NULL;
    }
    string = temp;
    cavity = string + cap;
  }
  *cavity = '\0';

  return string;
}

void print_line(FILE *dest, FILE *source)
{
  int ch;

  while ((ch = getc(source)) != EOF && ch != '\n')
    putc(ch, dest);

  putc('\n', dest);
}
