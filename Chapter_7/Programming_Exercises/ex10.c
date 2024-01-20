/**
 * @file    ex10.c
 * @brief   Calculate the tax based on 1988 US Federal Tax Schedule
 */
#include <stdio.h>

void print_message(void)
{
  printf("****************************************\n");
  printf("Please enter your category:\n");
  printf("1) Single           2) Head of Household\n"
         "3) Married, Joint   4) Married, Separate\n"
         "5) Quit\n");
  printf("****************************************\n");
}

int main(void)
{
  const float tax_rate_base = 0.15, tax_rate_excess = 0.28;
  const float income_boundary[4] =
  {
    17850, 23900, 29750, 14875
  };
  int cmd;
  float income, tax;

  while (1)
  {
    print_message();
    if (scanf("%d", &cmd) != 1 || cmd < 1 || cmd > 5)
    {
      printf("You should enter 1-5\n");
      continue;
    }
    if (cmd == 5)
      break;

    printf("Enter your taxable income: ");
    scanf("%f", &income);

    if (income > income_boundary[cmd])
      tax = income_boundary[cmd] * tax_rate_base
            + (income - income_boundary[cmd]) * tax_rate_excess;
    else
      tax = income * tax_rate_base;

    printf("Tax: $%.2f\n", tax);
  }

  return 0;
}
