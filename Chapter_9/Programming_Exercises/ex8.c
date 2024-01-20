#include <stdio.h>
#include <ctype.h>

double power(unsigned int base, int pow);

int get_values(int *base, int *pow);

int main(void)
{
  int base, pow;

  while (get_values(&base, &pow) != -1)
    printf("%d raised to the power of %d is %g\n",
           base, pow, power(base, pow));

  printf("Bye.\n");

  return 0;
}

int get_values(int *base, int *pow)
{
  while (printf("Input base and power (q to quit): "),
         scanf("%d %d", base, pow) != 2)
  {
    char ch;
    while (isspace(ch = getchar()))
      continue;
    if (ch == 'q')
      return -1;
    printf("Invalid Input!\n");
    while (getchar() != '\n')
      continue;
  }

  return 0;
}

double power(unsigned int base, int pow)
{
  if (pow == 0)
    return 1;
  else if (base == 0)
    return 0;
  else
  {
    double dBase = base;
    if (pow < 0)
    {
      pow = -pow;
      dBase = 1 / dBase;
    }
    double res = dBase;
    for (int i = 1; i < pow; i++)
      res *= dBase;

    return res;
  }
}
