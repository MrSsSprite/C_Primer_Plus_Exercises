/**
 * @file    ex3.c
 */
#include <stdio.h>

int main(void)
{
  for (char last = 'F'; last >= 'A'; last--) {
    for (char first = 'F'; first >= last; first--)
      printf("%c", first);
    printf("\n");
  }

  return 0;
}
