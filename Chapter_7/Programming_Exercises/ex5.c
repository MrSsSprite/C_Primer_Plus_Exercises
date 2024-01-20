/**
 * @file    ex5.c
 * @brief   read a block of text and replace . with !, and ! with !!
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *data;
  size_t cap, cavity;
} string;

void guarantee_cavity(string *str, size_t n);

int main(void)
{
  char ch;
  string text = {malloc(1), 1, 0};

  while ((ch = getchar()) != EOF)
  {
    switch (ch)
    {
    case '!':
      guarantee_cavity(&text, 2);
      text.data[text.cavity++] = ch;
      text.data[text.cavity++] = ch;
      break;
    case '.':
      ch = '!';
    default:
      guarantee_cavity(&text, 1);
      text.data[text.cavity++] = ch;
    }
  }
  guarantee_cavity(&text, 1);
  text.data[text.cavity++] = '\0';

  printf("The modified text:\n%s\n", text.data);

  free(text.data);
  return 0;
}

void guarantee_cavity(string *str, size_t n)
{
  size_t new_cap = str->cap;
  while (new_cap - str->cavity < n)
    new_cap *= 2;
  if (new_cap == str->cap)
    return;
  str->data = realloc(str->data, new_cap);
}
