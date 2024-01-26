/**
 * @file    ex9.c
 * @brief   use VLA based function to copy a 3x5 array
 */
#include <stdio.h>

void show2darr(size_t row, size_t col, const double arr[row][col]);
void cp_2darr(size_t row, size_t col, double tar[row][col], const double src[row][col]);

int main(void)
{
  double source[3][5], target[3][5];
  source[0][0] = 1.1;

  for (double *iter = source[0] + 1; iter != source[2] + 5; iter++)
    *iter = *(iter - 1) * *(iter - 1);

  printf("The original arrays:\n");
  printf("source:\n");
  show2darr(3, 5, source);
  putchar('\n');
  printf("target (should be garbage values):\n");
  show2darr(3, 5, target);
  putchar('\n');

  cp_2darr(3, 5, target, source);

  printf("The modified arrays:\n");
  printf("source:\n");
  show2darr(3, 5, source);
  putchar('\n');
  printf("target (should be garbage values):\n");
  show2darr(3, 5, target);
  putchar('\n');

  return 0;
}

void show2darr(size_t row, size_t col, const double arr[row][col])
{
  printf("{\n");
  for (int r = 0; r < row; r++)
  {
    printf("\t{");
    for (int c = 0; c < col; c++)
      printf("%g, ", arr[r][c]);
    printf("},\n");
  }
  printf("}\n");
}

void cp_2darr(size_t row, size_t col, double tar[row][col], const double src[row][col])
{
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      tar[i][j] = src[i][j];
}
