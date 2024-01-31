/**
 * @file    q5.c
 * @brief   prints every line containing a given character in a file
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string(FILE *fp);

int main(int argc, char **argv)
{
  FILE *fp;
  char *string;

  if (argc != 3)
  {
    fprintf(stderr, "Usage: %s character filename\n", argv[0]);
    return 1;
  }
  if (strlen(argv[1]) != 1)
  {
    fprintf(stderr, "The first argument must be A character.\n");
    return 1;
  }
  if ((fp = fopen(argv[2], "r")) == NULL)
  {
    fprintf(stderr, "Failed to Open %s\n", argv[2]);
    return 1;
  }
  register const char keychar = argv[1][0];

  while ((string = get_string(fp))
         && !(strlen(string) == 0 && feof(fp)))
  {
    if (strchr(string, keychar))
    {
      fputs(string, stdout);
      putchar('\n');
    }
    free(string);
  }

  fclose(fp);
  return 0;
}

char *get_string(FILE *fp)
{
  size_t cap = 1;
  char *string = malloc(cap), *cavity = string, *terminal = string + cap;
  char *temp;
  int ch;

  if (string == NULL)
    return NULL;

  while ((ch = getc(fp)) != EOF && ch != '\n')
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
