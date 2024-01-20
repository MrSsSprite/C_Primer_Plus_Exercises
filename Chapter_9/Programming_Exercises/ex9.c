#include <stdio.h>
#include <ctype.h>

double power(double base, int pow);

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
         scanf("%d %d", base, pow) != 2 || base < 0)
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

double power(double base, int pow)
{
  if (pow == 0)
    return 1;
  else if (base == 0)
    return 0;
  else
  {
    if (pow == 1)
      return base;
    if (pow < 0)
      return power(1 / base, -pow);

    return power(base, pow - 1) * base;
  }
}
