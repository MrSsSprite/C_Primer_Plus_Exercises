#include <stdio.h>
#include <ctype.h>

void to_base_n(unsigned long n, int base);

int get_non_space(void);
int get_values(unsigned long *n, unsigned int *base);

int main(void)
{
  unsigned long n;
  unsigned base;

  while (get_values(&n, &base) != -1)
  {
    printf("%d in decimal converted into base-%d is ", n, base);
    to_base_n(n, base);
    putchar('\n');
  }
}

int get_non_space(void)
{
  char ch;
  while (isspace(ch = getchar()))
    continue;
  return ch;
}

int get_values(unsigned long *n, unsigned int *base)
{
  while (printf("Input value and base (q to quit): "),
         scanf("%lu %u", n, base) != 2 
         || *base < 2 || *base > 10)
  {
    if (get_non_space() == 'q')
      return -1;
    printf("Invalid input!\n");
    while (getchar() != '\n')
      continue;
  }

  return 0;
}

void to_base_n(unsigned long n, int base)
{
  if (base < 2 || base > 10)
    printf("Invalid base!\n");

  int val = n % base;
  if (n >= base)
    to_base_n(n / base, base);
  printf("%d", val);
}
