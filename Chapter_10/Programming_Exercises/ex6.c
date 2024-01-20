/**
 * @file    ex6.c
 * @brief   reverse an array of double
 */
#include <stdio.h>

void reverse(double arr[], unsigned int size);
void showarr(const double arr[], unsigned int size);

int main(void)
{
  double arr0[5] = {1.1, 2.2, 3.3, 4.4, 5.678};
  double arr1[6] = {1.1, 2.2, 3.3, 4.4, 5.678, 9.87654};

  printf("Originally, arr0ay are ");
  showarr(arr0, 5);
  printf(", and\n");
  showarr(arr1, 6);
  putchar('\n');

  reverse(arr0, 5);
  reverse(arr1, 6);

  printf("After reversing, the arr0ay is ");
  showarr(arr0, 5);
  printf(", and\n");
  showarr(arr1, 6);
  putchar('\n');

  return 0;
}

void swap(double *lhs, double *rhs)
{
  double temp = *lhs;
  *lhs = *rhs;
  *rhs = temp;
}

void reverse(double arr[], unsigned int size)
{
  int last = size - 1;
  for (int i = 0, ed = size / 2; i < ed; i++)
    swap(arr + i, arr + (last - i));
}

void showarr(const double arr[], unsigned int size)
{
  putchar('{');
  for (int i = 0; i < size; i++)
    printf("%g, ", arr[i]);
  putchar('}');
}
