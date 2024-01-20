/**
 * @file    ex16.c
 */
#include <stdio.h>

int main(void)
{
  double daphne_balance = 100.0, deirdre_balance = 100.0;
  int year_count = 0;

  while (deirdre_balance <= daphne_balance)
  {
    daphne_balance += 10.0;
    deirdre_balance *= 1.05;
    year_count++;
  }

  printf("It takes %d year for Daphne's balance to exceed Deirdre's balance.\n", year_count);
  printf("At that year, their balances are:\n");
  printf("Daphne: $%f, and\n", daphne_balance);
  printf("Deirdre: $%f\n", deirdre_balance);
  printf("respectively.\n");

  return 0;
}
