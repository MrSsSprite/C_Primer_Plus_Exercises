/**
 * @file    ex12.c
 */
#include <stdio.h>

int main(void)
{
  int num_of_term;

  while (printf("Enter the number of terms: "),
         scanf("%d", &num_of_term) == 1 && num_of_term > 0)
  {
    double total[2] = {1.0, 1.0};
    int sign = -1;

    for (long long i = 2; i <= num_of_term; i++)
    {
      total[0] += 1.0 / (double) i;
      total[1] += 1.0 / (double) i * sign;
      sign *= -1;
    }

    printf("1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... + 1.0/%d.0 = %f\n",
           num_of_term, total[0]);
    printf("1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ... ");
    // just handling the sign, don't worry about the if/else statement here
    if ((num_of_term - 1) * -1 == -1)
      printf("-");
    else
      printf("+");
    printf(" 1.0/%d.0 = %f\n", num_of_term, total[1]);
  }

  return 0;
}
