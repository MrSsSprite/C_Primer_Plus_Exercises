/**
 * @file    ex2.c
 */
#include <stdio.h>

void chline(char ch, int i, int j);

int main(void)
{
  char ch;
  int i, j;

  while (printf("Input ch, i, and j: "),
         scanf("%c %d %d", &ch, &i, &j) == 3)
  {
    chline(ch, i, j);
    printf("\n");
    while (getchar() != '\n')
      continue;
  }

  printf("Bye.\n");

  return 0;
}

void chline(char ch, int i, int j)
{
  int count = 0;
  for (; count < i; count++)
    printf(" ");
  for (; count < j; count++)
    printf("%c", ch);
}
