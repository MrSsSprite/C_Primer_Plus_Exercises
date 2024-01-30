/**
 * @file    ex14.c
 * @brief   take two args and raise arg1 to the power of arg2, and report the result
 */
#include <stdio.h>
#include <stdlib.h>

double to_power(double value, long pow);

int main(int argc, char **argv)
{
  char *ptr;
  double value;
  long pow;

  if (argc != 3)
  {
    fprintf(stderr, "Usage: %s value power\n", argv[0]);
    return 1;
  }

  if (value = strtod(argv[1], &ptr), ptr == argv[1])
  {
    fprintf(stderr, "The first argument must be double (floating-point value)\n");
    return 1;
  }
  if (pow = strtol(argv[2], &ptr, 10), ptr == argv[2])
  {
    fprintf(stderr, "The second argument must be integer type\n");
    return 1;
  }

  printf("%g raised to the power of %ld is %g\n",
         value, pow, to_power(value, pow));

  return 0;
}

double to_power(double value, long pow)
{
  double result = value;

  if (pow < 0)
    return to_power(1.0 / value, -pow);
  if (pow == 0)
    return 1.0;
  if (value == 0)
    return 0;

  for (long i = 1; i < pow; i++)
    result *= value;

  return result;
}
