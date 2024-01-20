/**
 * @file    ex1.c
 * @brief   read until # and analyze the characters read
 */
#include <stdio.h>

struct Counter {
  long space;
  int newline;
  long others;
};

int main(void)
{
  char ch;
  struct Counter count = {0, 0, 0};

  printf("Input a block of content:\n");
  while ((ch = getchar()) != '#')
  {
    switch (ch)
    {
    case ' ':
      count.space++;
      break;
    case '\n':
      count.newline++;
      break;
    default:
      count.others++;
    }
  }

  printf("The text above conaints:\n"
         "\t%ld spaces, %d newline characters, %ld other chacters\n",
         count.space, count.newline, count.others);

  return 0;
}
