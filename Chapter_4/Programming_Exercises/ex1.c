/**
 * @file    ex1.c
 * @brief   prompt for first name and last name, then print them
 */
#include <stdio.h>

int main(void)
{
  char first[30], last[30];

  printf("Tell me your first name and last name, separated by whitespace:\n");
  scanf("%s %s", first, last);

  printf("%s, %s\n", last, first);

  return 0;
}
