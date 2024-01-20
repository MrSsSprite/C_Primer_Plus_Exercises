/**
 * @file    ex3.c
 * @brief   find the largest value in an array
 */
#include <stdio.h>

int largest(const int arr[], int size);
void showarr(const int arr[], int size);

int main(void)
{
  int arr[10] = {2, 4, 5, 1, 10, -5, -10, -11, 0, 10};

  printf("The largest int in the arr ");
  showarr(arr, 10);
  printf(" is %d\n", largest(arr, 10));

  printf("The largest int in the temporary arr is %d\n",
         largest((int[3]){5, 5, -10}, 3));

  return 0;
}

int largest(const int arr[], int size)
{
  int ret = arr[0];

  for (int i = 1; i < size; i++)
    if (arr[i] > ret)
      ret = arr[i];

  return ret;
}

void showarr(const int arr[], int size)
{
  putchar('{');
  for (const int *arr_ed = arr + size; arr < arr_ed; arr++)
    printf("%d, ", *arr);
  putchar('}');
}
