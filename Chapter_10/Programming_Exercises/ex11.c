/**
 * @file    ex11.c
 * @brief   display the values of a 3x5 int array, double them, and display them again
 */
#include <stdio.h>

void show2darr(size_t row, size_t col, const int arr[row][col]);
void double2darr(size_t row, size_t col, int arr[row][col]);

int main(void)
{
  int arr[3][5];

  arr[0][0] = 1;
  for (int *restrict ptr = arr[0] + 1; ptr < arr[2] + 5; ptr++)
    *ptr = *(ptr - 1) * 2;

  printf("The original array:\n");
  show2darr(3, 5, arr);
  putchar('\n');

  double2darr(3, 5, arr);

  printf("The modified array:\n");
  show2darr(3, 5, arr);
  putchar('\n');

  return 0;
}

void show2darr(size_t row, size_t col, const int arr[row][col])
{
  printf("{\n");
  for (size_t r = 0; r < row; r++)
  {
    printf("\t{");
    for (size_t c = 0; c < col; c++)
      printf("%d, ", arr[r][c]);
    printf("},\n");
  }
  printf("}\n");
}

void double2darr(size_t row, size_t col, int arr[row][col])
{
  for (size_t i = 0; i < row; i++)
    for (size_t j = 0; j < col; j++)
      arr[i][j] *= 2;
}
