/**
 * @file    ex4.c
 * @brief   read a block of text and replace . with !, and ! with !!
 */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
  char *data;
  size_t size;
  size_t cavity;
} string;

int main(void)
{
  string text = {malloc(1), 1, 0};
  char ch;

  printf("Input the original text:\n");
  while ((ch = getchar()) != EOF)
  {
    if (ch == '.')
    {
      if (text.cavity == text.size)
        text.data = realloc(text.data, (text.size *= 2));
      text.data[text.cavity++] = '!';
    }
    else if (ch == '!')
    {
      size_t new_size = text.size;
      while (new_size - text.cavity < 2)
        new_size *= 2;
      if (new_size != text.size)
        text.data = realloc(text.data, new_size);
      text.data[text.cavity++] = ch;
      text.data[text.cavity++] = ch;
    }
    else
    {
      if (text.cavity == text.size)
        text.data = realloc(text.data, (text.size *= 2));
      text.data[text.cavity++] = ch;
    }
  }
  if (text.cavity == text.size)
    text.data = realloc(text.data, (text.size *= 2));
  text.data[text.cavity++] = '\0';

  printf("The modified text:\n%s\n", text.data);

  free(text.data);
  return 0;
}
