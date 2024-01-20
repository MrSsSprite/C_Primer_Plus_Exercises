/**
 * @file    ex8.c
 * @brief   input hours worked in a week and prints gross pay, 
 *          the taxes, and the net pay.
 */
#include <stdio.h>

#define OT_EQUIV 1.5
#define OT_MIN_HOUR 40
#define TAX_RATE_0 0.15
#define TAX_RATE_1 0.20
#define TAX_RATE_2 0.25
#define TAX_RATE_BOUND_0 300
#define TAX_RATE_BOUND_1 150
#define EARNING_RATE_0  8.75
#define EARNING_RATE_1  9.33
#define EARNING_RATE_2 10.00
#define EARNING_RATE_3 11.20

void compute_earnings(int weekly_work_hr, float pay_rate);
void print_message(void)
{
  printf("*****************************************************************\n"
         "Enter the number corresponding to the desired pay rate or action:\n");
  printf("1) $%5.2f/hr\t\t2) $%5.2f/hr\n"
         "3) $%5.2f/hr\t\t4) $%5.2f/hr\n5) quit\n",
         EARNING_RATE_0, EARNING_RATE_1, EARNING_RATE_2, EARNING_RATE_3);
  printf("*****************************************************************\n");
}

int main(void)
{
  int weekly_work_hour;
  float pay_rate;

  int cmd;
  while (print_message(),
         scanf("%d", &cmd) == 1)
  {
    switch (cmd)
    {
    case 1:
      pay_rate = EARNING_RATE_0;
      break;
    case 2:
      pay_rate = EARNING_RATE_1;
      break;
    case 3:
      pay_rate = EARNING_RATE_2;
      break;
    case 4:
      pay_rate = EARNING_RATE_3;
      break;
    case 5:
      goto END_OF_LOOP;
    default:
      printf("You should enter 1-5.\n");
      continue;
    }
    printf("Input the hour(s) worked in a week: ");
    scanf("%d", &weekly_work_hour);
    compute_earnings(weekly_work_hour, pay_rate);
  }
  END_OF_LOOP:

  return 0;
}

void compute_earnings(int weekly_work_hr, float pay_rate)
{
  int  adjusted_wk_hr;
  float gross_pay, tax, net_pay;


  adjusted_wk_hr = weekly_work_hr > OT_MIN_HOUR
                     ? OT_MIN_HOUR + (weekly_work_hr - OT_MIN_HOUR) * OT_EQUIV
                     : weekly_work_hr;
  gross_pay = adjusted_wk_hr * pay_rate;
  tax = 0;
  float temp = gross_pay;
  if (gross_pay > TAX_RATE_BOUND_0)
  {
    tax += TAX_RATE_BOUND_0 * TAX_RATE_0;
    temp -= TAX_RATE_BOUND_0;
    if (temp > TAX_RATE_BOUND_1)
    {
      tax += TAX_RATE_BOUND_1 * TAX_RATE_1;
      temp -= TAX_RATE_BOUND_1;
      tax += temp * TAX_RATE_2;
    }
    else
      tax += temp * TAX_RATE_1;
  }
  else
    tax += temp * TAX_RATE_0;

  net_pay = gross_pay - tax;

  printf("Gross Pay: $%.2f\n", gross_pay);
  printf("Tax:       $%.2f\n", tax);
  printf("Net Pay:   $%.2f\n", net_pay);
}
