/**
 * @file    ex7.c
 * @brief   alternate display each line of two files
 */
#include <stdio.h>
#include <stdlib.h>

char * get_line(FILE *file);

int main(int argc, char **argv)
{
  FILE *file[2];
  char *string[2];

  if (argc != 3)
  {
    fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
    exit(1);
  }
  if ((file[0] = fopen(argv[1], "r")) == NULL)
  {
    fprintf(stderr, "Can't open %s for reading.\n", argv[1]);
    exit(2);
  }
  if ((file[1] = fopen(argv[2], "r")) == NULL)
  {
    fprintf(stderr, "Can't open %s for reading.\n", argv[2]);
    fclose(file[0]);
    exit(2);
  }

  fputs("Part A:\n", stdout);
  while (1)
  {
    string[0] = get_line(file[0]);
    string[1] = get_line(file[1]);
    if (string[0] == NULL || string[1] == NULL)
    {
      fputs("Error to allocate memory for strings.\n", stderr);
      free(string[0]);
      free(string[1]);
      fclose(file[0]);
      fclose(file[1]);
      exit(-2);
    }

    if (string[0][0])
      puts(string[0]);
    if (string[1][0])
      puts(string[1]);
    free(string[0]);
    free(string[1]);
    
    if (feof(file[0]) && feof(file[1]))
      break;
  }
  putchar('\n');

  rewind(file[0]);
  rewind(file[1]);
  fputs("Part B:\n", stdout);
  while (1)
  {
    string[0] = get_line(file[0]);
    string[1] = get_line(file[1]);
    if (string[0] == NULL || string[1] == NULL)
    {
      fputs("Error to allocate memory for strings.\n", stderr);
      free(string[0]);
      free(string[1]);
      fclose(file[0]);
      fclose(file[1]);
      exit(-2);
    }

    if (string[0][0])
      fputs(string[0], stdout);
    if (string[1][0])
      fputs(string[1], stdout);
    putchar('\n');
    free(string[0]);
    free(string[1]);

    if (feof(file[0]) && feof(file[1]))
      break;
  }
  putchar('\n');

  fclose(file[0]);
  fclose(file[1]);
  printf("Done\n");

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
