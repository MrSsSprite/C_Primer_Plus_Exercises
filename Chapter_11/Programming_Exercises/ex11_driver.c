/**
 * @file    ex11.c
 * @brief   read at most 10 strings and display in sorted order
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex11.h"


char * get_line(void);
/**
 * 1. print the original list of strings
 * 2. print the strings in ASCII collating sequence
 * 3. print the strings in order of increasing length
 * 4. print the strings in order of the length of the first word in the string
 * 5. quit
 */
int menu_prompt(void);

int main(void)
{
  char *strings[MAXSTRCT];
  char *ascii_order[MAXSTRCT], *len_order[MAXSTRCT], *fst_wd_order[MAXSTRCT];
  char **stringArr_ptr;
  int init_count;
  int cmd;

  printf("Input at most 10 lines of strings (empty line to finish prematurely):\n");
  for (init_count = 0; init_count < MAXSTRCT && (strings[init_count] = get_line()); init_count++)
    // empty line
    if (strings[init_count][0] == '\0')
    {
      free(strings[init_count]);
      break;
    }

  sort_strings(strings, ascii_order, len_order, fst_wd_order, init_count);

  while ((cmd = menu_prompt()) != 5)
  {
    switch (cmd)
    {
    case 1: stringArr_ptr = strings;
            break;
    case 2: stringArr_ptr = ascii_order;
            break;
    case 3: stringArr_ptr = len_order;
            break;
    case 4: stringArr_ptr = fst_wd_order;
            break;
    }

    for (int i = 0; i < init_count; i++)
    {
      fputs(stringArr_ptr[i], stdout);
      putchar('\n');
    }
    for (int i = 0; i < 80; i++)
      putchar('=');
    putchar('\n');
  }

  printf("Cleaning Memory...\n");
  for (int i = 0; i < init_count; i++)
    free(strings[i]);
  printf("Done!\n");

  return 0;
}

char * get_line(void)
{
  size_t cap = 1;
  char *string = malloc(cap), *cavity = string, *terminal = string + cap;
  int ch;

  if (string == NULL)
    return string;

  while ((ch = getchar()) != EOF && ch != '\n')
  {
    // guarantee enough space
    if (cavity == terminal)
    {
      string = reallocf(string, cap * 2);
      if (string == NULL)
        return string;
      cavity = string + cap;
      terminal = string + (cap *= 2);
    }

    *cavity++ = ch;
  }

  if (cavity == terminal)
  {
    string = reallocf(string, cap + 1);
    if (string == NULL)
      return string;
    cavity = string + cap;
  }

  *cavity = '\0';

  return string;
}

int menu_prompt(void)
{
  int cmd;
  int ch;

  for (int i = 0; i < 80; i++)
    putchar('*');
  putchar('\n');
  printf("Print the strings:\n");
  printf("%-39s %-40s\n%-39s %-40s\n",
         "1) in original order",
         "2) in ASCII collating sequence",
         "3) in order of increasing length",
         "4) in order of the length of the first word");
  while (printf("Input your choice (5 to quit): "),
         scanf("%d", &cmd) != 1 || cmd < 1 || cmd > 5)
  {
    while ((ch = getchar()) != EOF && ch != '\n')
      continue;
    printf("!!! Invalid Input. Please retry. !!!\n");
  }

  return cmd;
}
