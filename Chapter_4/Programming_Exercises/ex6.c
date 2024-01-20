/**
 * @file    ex6.c
 * @brief   prompt for first name and last name. Then, format print them
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
  char first[40], last[40];
  int fsz, lsz;

  printf("What's your name? ");
  scanf("%s %s", first, last);
  fsz = strlen(first);
  lsz = strlen(last);

  printf("\n");
  printf("%s %s\n", first, last);
  printf("%*d %*d\n\n", fsz, fsz, lsz, lsz);

  printf("%s %s\n", first, last);
  printf("%-*d %-*d\n", fsz, fsz, lsz, lsz);

  return 0;
}
