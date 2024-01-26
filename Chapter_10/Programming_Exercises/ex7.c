/**
 * @file    ex7.c
 * @brief   copy a two dimensional double array
 */
#include <stdio.h>

void cp_arr(double *restrict tar, const double *restrict src, const double *restrict src_ed);
void show2darr(size_t row, size_t col, const double arr[row][col]);

int main(void)
{
  double source[5][20], target[5][20];
  double *iter = source[0];

  for (int i = 0; i < 5 * 20; i++)
    *(iter + i) = i;

  printf("source arr: ");
  show2darr(5, 20, source);

  for (int i = 0; i < 5; i++)
    cp_arr(target[i], source[i], source[i] + 20);

  printf("target arr: ");
  show2darr(5, 20, source);

  return 0;
}

void show2darr(size_t row, size_t col, const double arr[row][col])
{
  printf("{\n");

  for (size_t r = 0; r < row; r++)
  {
    printf("\t{");
    for (size_t c = 0; c < col; c++)
      printf("%2g, ", arr[r][c]);
    printf("},\n");
  }
  
  printf("}\n");
}

void cp_arr(double *restrict tar, const double *restrict src, const double *restrict src_ed)
{
  while (src != src_ed)
    *tar++ = *src++;
}
