/**
 * @file    ex2.c
 * @breif   reads in a block of text, and print their respective ASCII code
 */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define TERMINATING_CHAR '#'
#define CODE_PER_LINE 8

int main(void)
{
  char ch;
  char *content = malloc(1);
  size_t content_size = 1, content_cavity = 0;
  
  while ((ch = getchar()) != TERMINATING_CHAR)
  {
    if (content_cavity == content_size)
      content = realloc(content, (content_size *= 2));

    *(content + content_cavity++) = ch;
  }

  int counter = 0;
  for (size_t i = 0; i < content_cavity; i++)
  {
    if (content[i] == '\n')
      printf("%2s", "\\n");
    else
      printf("%2c", content[i]);
    printf("(%3d) ", content[i]);
    if (++counter == 8)
    {
      printf("\n");
      counter = 0;
    }
  }

  free(content);
  return 0;

}
