/**
 * @file    ex10.c
 * @brief   set value in an array to the corresponding values of the other twos
 */
#include <stdio.h>

void showarr(const int *arr, const int *const arr_ed);
void sumcp_arr(int *restrict tar, const int *src0, const int *src1, size_t size);

int main(void)
{
  int src0[5] = {1, 2, 3, 4, 5};
  int src1[5] = {0, 1, 0, 1, 0};
  int tar[5];

  printf("The original arrays:\n");
  printf("src0: ");
  showarr(src0, src0 + 5);
  printf("\nsrc1: ");
  showarr(src1, src1 + 5);
  printf("\ntar (garbage values): ");
  showarr(tar, tar + 5);
  putchar('\n');

  sumcp_arr(tar, src0, src1, 5);

  printf("The modified arrays:\n");
  printf("src0: ");
  showarr(src0, src0 + 5);
  printf("\nsrc1: ");
  showarr(src1, src1 + 5);
  printf("\ntar (modified values): ");
  showarr(tar, tar + 5);
  putchar('\n');

  return 0;
}

void showarr(const int *arr, const int *const arr_ed)
{
  putchar ('{');
  while (arr != arr_ed)
    printf("%d, ", *arr++);
  putchar ('}');
}

void sumcp_arr(int *restrict tar, const int *src0, const int *src1, size_t size)
{
  const int *const tar_ed = tar + size;
  while (tar != tar_ed)
    *tar++ = *src0++ + *src1++;
}
