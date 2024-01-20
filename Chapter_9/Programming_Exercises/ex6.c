#include <stdio.h>

void rearrange(double *a, double *b, double *c);

int main(void)
{
  double a, b, c;

  while (printf("Input 3 doubles: "),
         scanf("%lf %lf %lf", &a, &b, &c) == 3)
  {
    printf("Initially, a = %f, b = %f, and c = %f\n", a, b, c);

    rearrange(&a, &b, &c);

    printf("Now, a = %f, b = %f, c = %f\n", a, b, c);
  }

  return 0;
}

void swap(double *lhs, double *rhs)
{
  double temp = *lhs;
  *lhs = *rhs;
  *rhs = temp;
}
void rearrange(double *a, double *b, double *c)
{
  if (*a > *b)
    swap(a, b);
  if (*b > *c)
    swap(b, c);
  if (*a > *b)
    swap(a, b);
}
