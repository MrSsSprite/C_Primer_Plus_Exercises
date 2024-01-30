#include "ex11.h"

#include <ctype.h>
#include <string.h>
#include <stddef.h>

void selection_sort(char *arr[], char *const arr_ed[],
                    int (*cmp)(const char*, const char*));
int len_cmp(const char *s0, const char *s1);
int fst_wd_len_cmp(const char *s0, const char *s1);

void sort_strings(char *const *strings, char *ascii_order[],
                  char *len_order[], char *fst_wd_order[], int size)
{
  // copy strings to each arr
  for (int i = 0; i < size; i++)
  {
    ascii_order[i] = strings[i];
    len_order[i] = strings[i];
    fst_wd_order[i] = strings[i];
  }

  selection_sort(ascii_order, ascii_order + size, &strcmp);
  selection_sort(len_order, len_order + size, &len_cmp);
  selection_sort(fst_wd_order, fst_wd_order, &fst_wd_len_cmp);
}

void selection_sort(char *arr[], char *const arr_ed[],
                    int (*cmp)(const char*, const char*))
{
  char **ptr, **lowest;
  char *temp;

  while (arr < arr_ed)
  {
    lowest = arr;
    for (ptr = arr + 1; ptr < arr_ed; ptr++)
      if (cmp(*ptr, *lowest) < 0)
        lowest = ptr;
    temp = *arr;
    *arr = *lowest;
    *lowest = temp;
    arr++;
  }
}

int len_cmp(const char *s0, const char *s1)
{
  return strlen(s0) - strlen(s1);
}

int fst_wd_len_cmp(const char *s0, const char *s1)
{
  int len[2] = { 0, 0 };

  while (*s0 != '\0' && !isspace(*s0))
  {
    len[0]++;
    s0++;
  }
  while (*s1 != '\0' && !isspace(*s1))
  {
    len[1]++;
    s1++;
  }

  return len[0] - len[1];
}
