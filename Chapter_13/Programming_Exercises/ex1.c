/**
 * @file    ex1.c
 * @brief   modify Listing 13.1 so that it ask for input instead of using 
 *          command-line arguments
 */
#include <stdio.h>
#include <stdlib.h>

char * get_line(void);

int main(void)
{
  unsigned long count = 0;
  int ch;
  FILE *fp;
  char *string;

  while (printf("Input the filename: "),
         (fp = fopen(string = get_line(), "r")) == NULL)
  {
    fprintf(stderr, "Invalid Filename. Please Retry.\n");
    free(string);
  }

  while ((ch = getc(fp)) != EOF)
  {
    putc(ch, stdout);
    count++;
  }
  fclose(fp);
  printf("File %s has %lu characters\n", string, count);
  free(string);

  return 0;
}

char * get_line(void)
{
  size_t cap = 1;
  char *string = malloc(cap), *cavity = string, *terminal = string + cap;
  char *temp;
  int ch;

  if (string == NULL)
    return NULL;

  while ((ch = getchar()) != EOF && ch != '\n')
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
