/**
 * @file    ex5.c
 * @brief   find the difference between the largest and smallest in an array
 */
#include <stdio.h>

double lar_sml_diff(const double arr[], unsigned int size);
void showarr(const double arr[], unsigned int size);

int main(void)
{
  double arr[5] = {2.3, 4.2, 5.1, -5.2, -5.1};

  printf("The difference between the largest and smallest in the array ");
  showarr(arr, 5);
  printf(" is %g.\n", lar_sml_diff(arr, 5));

  return 0;
}

double lar_sml_diff(const double arr[], unsigned int size)
{
  double values[2] = {arr[0], arr[0]};
  const double *arr_ed = arr + size;

  while (++arr != arr_ed)
  {
    if (*arr < values[0])
      values[0] = *arr;
    if (*arr > values[1])
      values[1] = *arr;
  }

  return values[1] - values[0];
}

void showarr(const double arr[], unsigned int size)
{
  putchar('{');
  for (int i = 0; i < size; i++)
    printf("%g, ", arr[i]);
  putchar('}');
}
