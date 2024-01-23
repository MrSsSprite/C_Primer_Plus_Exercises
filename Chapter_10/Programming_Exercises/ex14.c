/**
 * @file    ex14.c
 * @brief   repeat ex13.c but use VLA
 */
#include <stdio.h>

void get_numbers(size_t row, size_t col, double arr[row][col]);
void show2darr(size_t row, size_t col, const double arr[row][col]);
void print_avg(size_t row, size_t col, const double arr[row][col]);
double largest(size_t row, size_t col, const double arr[row][col]);

int main(void)
{
  double numbers[3][5];

  get_numbers(3, 5, numbers);
  
  printf("Your input:\n");
  show2darr(3, 5, numbers);
  putchar('\n');

  print_avg(3, 5, numbers);
  printf("The largest among the array is %f\n", largest(3, 5, numbers));

  return 0;
}

void get_numbers(size_t row, size_t col, double arr[row][col])
{
  for (double (*ptr)[col] = arr; ptr < arr + row; ptr++)
  {
  beg_loop_body:
    printf("Input %zd numbers: ", col);
    for (size_t i = 0; i < col; i++)
      if (scanf("%lf", *ptr + i) != 1)
      {
        printf("Invalid Input detected. Entire line discarded.\n");
        while (getchar() != '\n')
          continue;
        goto beg_loop_body;
      }
    while (getchar() != '\n')
      continue;
  }
}

void show2darr(size_t row, size_t col, const double arr[row][col])
{
  printf("{\n");
  for (size_t r = 0; r < row; r++)
  {
    printf("\t{");
    for (size_t c = 0; c < col; c++)
      printf("%f, ", arr[r][c]);
    printf("},\n");
  }
  printf("}\n");
}

void print_avg(size_t row, size_t col, const double arr[row][col])
{
  double total = 0, subtotal;
  
  printf("The average of:\n");
  for (size_t r = 0; r < row; r++)
  {
    subtotal = 0;
    for (size_t c = 0; c < col; c++)
      subtotal += arr[r][c];
    printf("Line %zd: %g,\n", r, subtotal / col);
    total += subtotal;
  }
  putchar('\n');
  printf("The total average is: %g\n", total / (row * col));
}

double largest(size_t row, size_t col, const double arr[row][col])
{
  double ret = arr[0][0];
  for (size_t r = 0; r < row; r++)
    for (size_t c = 0; c < col; c++)
      if (arr[r][c] > ret)
        ret = arr[r][c];
  return ret;
}
