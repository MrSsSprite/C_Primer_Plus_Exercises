/**
 * @file    ex8.c
 * @brief   partial copy of an array
 */
#include <stdio.h>

void showarr(const int *arr, const int *const arr_ed);
void cp_arr(int *restrict tar, const int *src, const int *const src_ed);

int main(void)
{
  const int arr0[7] = {0, 1, 2, 3, 4, 5, 6};
  int arr1[3] = {99, 99, 99};

  printf("The original arrays:\n");
  printf("arr0: ");
  showarr(arr0, arr0 + 7);
  putchar('\n');
  printf("arr1: ");
  showarr(arr1, arr1 + 3);
  putchar('\n');

  cp_arr(arr1, arr0 + 2, arr0 + 2 + 3);

  printf("The modified arrays:\n");
  printf("arr0: ");
  showarr(arr0, arr0 + 7);
  putchar('\n');
  printf("arr1: ");
  showarr(arr1, arr1 + 3);
  putchar('\n');

  return 0;
}

void showarr(const int *arr, const int *const arr_ed)
{
  putchar('{');
  while (arr != arr_ed)
    printf("%d, ", *arr++);
  putchar('}');
}

void cp_arr(int *restrict tar, const int *src, const int *const src_ed)
{
  while (src != src_ed)
    *tar++ = *src++;
}
