/**
 * @file    ex4.c
 * @brief   function that return the index of the largest value
 */
#include <stdio.h>

unsigned int find_largest(double arr[], unsigned int size);
void showarr(double arr[], unsigned int size);

int main(void)
{
  double arr[6] = {1.1, 2.2, -1.2, 5.1, 4.2, 0.1};

  printf("The element #%u(zero indexed) is the largest one in the array ",
         find_largest(arr, 6));
  showarr(arr, 6);
  printf(".\n");

  return 0;
}

unsigned int find_largest(double arr[], unsigned int size)
{
  unsigned int ret = 0;
  for (int i = 1; i < size; i++)
    if (arr[i] > arr[ret])
      ret = i;

  return ret;
}

void showarr(double arr[], unsigned int size)
{
  putchar('{');
  for (int i = 0; i < size; i++)
    printf("%f, ", arr[i]);
  putchar('}');
}
