/**
 * @file    ex7.c
 * @brief   input hours worked in a week and prints gross pay, 
 *          the taxes, and the net pay.
 */
#include <stdio.h>

#define BASIC_HOURLY_PAY 10.00
#define OT_EQUIV 1.5
#define OT_MIN_HOUR 40
#define TAX_RATE_0 0.15
#define TAX_RATE_1 0.20
#define TAX_RATE_2 0.25
#define TAX_RATE_BOUND_0 300
#define TAX_RATE_BOUND_1 150

int main(void)
{
  int weekly_work_hr, adjusted_wk_hr;
  float gross_pay, tax, net_pay;

  // prompt for weekly work hour
  printf("Input the hour(s) worked in a week: ");
  // check the input
  if (scanf("%d", &weekly_work_hr) != 1)
  {
    printf("Invalid Input!\n"
           "Please ensure that your input is in whole integer.\n");
    return 1;
  }

  adjusted_wk_hr = weekly_work_hr > OT_MIN_HOUR
                     ? OT_MIN_HOUR + (weekly_work_hr - OT_MIN_HOUR) * OT_EQUIV
                     : weekly_work_hr;
  gross_pay = adjusted_wk_hr * BASIC_HOURLY_PAY;
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

  return 0;
}
