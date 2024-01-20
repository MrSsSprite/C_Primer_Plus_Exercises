/**
 * @file    ex9.c
 * @brief   find prime numbers up to the input integer
 */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  unsigned int inp;

  printf("Input a positive integer: ");
  if (scanf("%u", &inp) != 1)
  {
    printf("Invalid Input\n");
    return 1;
  }

  int temp = inp, digit_num = 0;
  while (temp)
  {
    temp /= 10;
    digit_num++;
  }

  bool prime_found = false;
  printf("The prime numbers up to %u involves:\n", inp);
  int counter = 0;
  for (unsigned int i = 2; i <= inp; i++)
  {
    bool is_prime = true;
    for (unsigned int j = 2; j*j <= i; j++)
      if (i % j == 0)
      {
        is_prime = false;
        break;
      }
    if (is_prime)
    {
      printf("%*u, ", digit_num, i);
      prime_found = true;
      if (++counter == 8)
      {
        printf("\n");
        counter = 0;
      }
    }
  }
  printf("\n");

  return 0;
}
