/**
 * @file    ex2.c
 * @brief   three ways to copy an array
 */
#include <stdio.h>

void cpy_arr(double tar[], const double src[], int size);
void cpy_ptr(double *tar, const double *src, int size);
void cpy_ptrs(double *tar, const double *src, const double *src_ed);
void showarr(double arr[], int size);

int main(void)
{
  double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double target0[5], target1[5], target2[5];
  
  printf("The source arr: ");
  showarr(source, 5);
  putchar('\n');

  cpy_arr(target0, source, 5);
  cpy_ptr(target1, source, 5);
  cpy_ptrs(target2, source, source + 5);

  printf("target0 (cpy_arr): ");
  showarr(target0, 5);
  putchar('\n');
  printf("target1 (cpy_ptr): ");
  showarr(target1, 5);
  putchar('\n');
  printf("target2 (cpy_ptrs): ");
  showarr(target2, 5);
  putchar('\n');

  return 0;
}

void cpy_arr(double tar[], const double src[], int size)
{
  for (int i = 0; i < size; i++)
    tar[i] = src[i];
}

void cpy_ptr(double *tar, const double *src, int size)
{
  for (int i = 0; i < size; i++)
    *tar++ = *src++;
}

void cpy_ptrs(double *tar, const double *src, const double *src_ed)
{
  while (src != src_ed)
    *tar++ = *src++;
}

void showarr(double arr[], int size)
{
  putchar('{');
  for (int i = 0; i < size; i++)
    printf("%f, ", *arr++);
  putchar('}');
}
