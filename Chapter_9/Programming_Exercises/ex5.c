#include <stdio.h>

void larger_of(double *x, double *y);

int main(void)
{
  double x = 5.1, y = 2.2;

  printf("Initially, x = %f and y = %f\n", x, y);

  larger_of(&x, &y);

  printf("Now, x = %f and y = %f\n", x, y);

  return 0;
}

void larger_of(double *x, double *y)
{
  if (*x > *y)
    *y = *x;
  else
    *x = *y;
}
