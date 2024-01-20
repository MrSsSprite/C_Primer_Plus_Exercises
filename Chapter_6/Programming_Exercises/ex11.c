/**
 * @file    ex11.c
 * @brief   read 8 integers and print in reverse order
 */
#include <stdio.h>

#define SIZE 8

int main(void)
{
  int iarr[SIZE];

  printf("Input %d integers: ", SIZE);
  for (int i = 0; i < SIZE; i++)
    scanf("%d", iarr + i);

  for (int i = SIZE - 1; i >= 0; i--)
    printf("%d, ", iarr[i]);

  return 0;
}
