#include <stdio.h>

double harmonic_mean(double n, double m);

int main(void)
{
  double n, m;

  while (printf("Input two numbers: "),
         scanf("%lf %lf", &n, &m) == 2)
  {
    printf("The harmonic mean of %f and %f is %f\n",
           n, m, harmonic_mean(n, m));
    while (getchar() != '\n')
      continue;
  }

  printf("Bye.\n");

  return 0;
}

double harmonic_mean(double n, double m)
{
  return 1 / ((1 / n + 1 / m) / 2);
}
