/**
 * @file    ex13.c
 * @brief   get 3x5 doubles and report the average(of all and of each row) and largest of all
 */
#include <stdio.h>

void showarr(size_t row, size_t col, double data[row][col]);
double arr_average(const double *arr, const double *const arr_ed);
double largest(const double *arr, const double *const arr_ed);

int main(void)
{
  double numbers[3][5];

  for (double (*ptr)[5] = numbers; ptr < numbers + 3; ptr++)
  {
  beg_loop:
    printf("Input 5 numbers: ");
    for (int i = 0; i < 5; i++)
      if (scanf("%lf", (*ptr) + i) != 1)
      {
        printf("Invalid Input detected, Please reinput this set of numbers\n");
        // clean remnant
        while (getchar() != '\n')
          continue;
        goto beg_loop;
      }
    // clean remnant
    while (getchar() != '\n')
      continue;
  }
  printf("Your input:\n");
  showarr(3, 5, numbers);
  putchar('\n');
  printf("The average of:\n");
  for (size_t i = 0; i < 3; i++)
    printf("Line %zd: %g,\n", i + 1, arr_average(numbers[i], numbers[i] + 5));
  printf("The average of all values: %g\n",
         arr_average(numbers[0], (double*) (numbers + 3)));
  printf("The largest double in the array is %g\n",
         largest(numbers[0], (double*) (numbers + 3)));

  return 0;
}

void showarr(size_t row, size_t col, double data[row][col])
{
  printf("{\n");
  for (size_t r = 0; r < row; r++)
  {
    printf("\t{");
    for (size_t c = 0; c < col; c++)
      printf("%g, ", data[r][c]);
    printf("},\n");
  }
  printf("}\n");
}

double arr_average(const double *arr, const double *const arr_ed)
{
  size_t size = arr_ed - arr;
  double total = 0;
  while (arr != arr_ed)
    total += *arr++;
  return total / size;
}

double largest(const double *arr, const double *const arr_ed)
{
  double ret = *arr++;
  while (arr != arr_ed)
  {
    if (*arr > ret)
      ret = *arr;
    arr++;
  }
  return ret;
}
