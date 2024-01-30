/**
 * @file    ex15.c
 * @brief   write my implementation of atoi
 */
#include <stdio.h>
#include <ctype.h>

int myatoi(const char *str);

int main(int argc, char **argv)
{
  int res;

  if (argc < 2)
  {
    fprintf(stderr, "Usage: %s (integers)...\n", argv[0]);
    return 1;
  }

  for (int i = 1; i < argc; i++)
  {
    printf("Argument %3d: \"%s\"\n", i, argv[i]);
    printf("Conversion Result: ");
    if ((res = myatoi(argv[i])))
      printf("%d", res);
    else
      printf("either 0 or invalid");
    putchar('\n');
  }

  return 0;
}

int myatoi(const char *str)
{
  int ret = 0;

  while (*str)
  {
    if (!isdigit(*str))
      return 0;
    ret = ret * 10 + (*str - '0');
    str++;
  }

  return ret;
}
