/**
 * @file    ex9.c
 * @brief   store words in a file
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STORAGE_FILE "wordy"

char * get_word(FILE *file);

int main(void)
{
  FILE *file;
  char *word;

  if ((file = fopen(STORAGE_FILE, "a+")) == NULL)
  {
    fprintf(stdout, "Can't open \"%s\" file.\n", STORAGE_FILE);
    exit(EXIT_FAILURE);
  }

  puts("Enter words to add to the file; press '#' key");
  puts("at the beginning of a line to terminate.");
  while ((word = get_word(stdin)) && (word[0] != '#'))
  {
    fprintf(file, "%s\n", word);
    free(word);
  }

  fputs("File contents:\n", stdout);
  rewind(file);
  for (unsigned long i = 1; word = get_word(file), !(feof(file) || ferror(file)); i++)
  {
    printf("%5lu: %s\n", i, word);
    free(word);
  }
  puts("Done!");
  if (fclose(file))
    fputs("Error closing file\n", stderr);

  return 0;
}

char * get_word(FILE *file)
{
  int cap = 1;
  char *string = malloc(cap), *cavity = string, *terminal = string + cap;
  char *temp;
  int ch;

  if (string == NULL)
    return NULL;

  // consume spaces before
  while ((ch = getc(file)) != EOF && isspace(ch))
    continue;
  if (ch != EOF)
    *cavity++ = ch;

  while ((ch = getc(file)) != EOF && !isspace(ch))
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
