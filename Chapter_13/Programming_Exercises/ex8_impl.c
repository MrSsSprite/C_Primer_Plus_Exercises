#include "ex8.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum modes { cla, input };
enum modes mode;

static struct
{
  int count;
  char **vector;
} args = {0, NULL};
// zeroth: this program; first: character
static int args_counter = 2;

char * get_line(void);

void set_mode_cla(int argc, char **argv)
{
  mode = cla;

  args.count = argc;
  args.vector = argv;
}

void set_mode_stdin(void)
{
  mode = input;
}

struct file_info next_file(void)
{
  struct file_info ret;
  switch (mode)
  {
  case cla:
    if (args_counter < args.count)
    {
      if ((ret.name = malloc(strlen(args.vector[args_counter]) + 1)) == NULL)
        fputs("Failed to malloc for string of next_file.\n", stderr);
      else
        strcpy(ret.name, args.vector[args_counter++]);
    }
    else
      ret.name = NULL;

    break;
  case input:
    fputs("Input a filename (empty input to quit): ", stdout);
    if ((ret.name = get_line()) == NULL)
        fputs("Failed to malloc for string of next_file.\n", stderr);
    // empty line
    if (ret.name[0] == '\0')
    {
      free(ret.name);
      ret.name = NULL;
    }
    break;
  default:
    ret.name = NULL;
    fprintf(stderr, "Program Design Error: '%d' mode passed to next_file\n", mode);
  }

  if (ret.name)
  {
    ret.file = fopen(ret.name, "r");
    if (ret.file == NULL)
    {
      fprintf(stderr, "Failed to open %s for reading.\n", ret.name);
      free(ret.name);
      ret.name = NULL;
    }
  }
  else
    ret.file = NULL;

  return ret;
}

unsigned long appear_ct(char key_ch, FILE *file)
{
  int ch;
  unsigned long count = 0;

  while ((ch = getc(file)) != EOF)
    if (ch == key_ch)
      count++;

  return count;
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
