/**
 * @file    ex1.c
 * @brief   test a function that returns the smaller of 2 doubles
 */
#include <stdio.h>

int get_doubles(double dest[2]);
double smaller(double n, double m) { return (n < m ? n : m); }

int main(void)
{
  double values[2];

  while (get_doubles(values) == 0)
    printf("The smaller of %f and %f is %f\n",
           values[0], values[1], smaller(values[0], values[1]));

  printf("Bye.\n");

  return 0;
}

int get_doubles(double dest[2])
{
  int status;
  while (printf("Input two doubles (EOF to quit): "),
         (status = scanf("%lf %lf", dest, dest + 1)) != 2)
  {
    if (status == EOF)
      return 1;
    while (getchar() != '\n')
      continue;
    printf("Invalid Input!\n");
  }

  return 0;
}
