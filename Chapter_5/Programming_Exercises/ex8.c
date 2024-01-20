/**
 * @file    ex8.c
 * @brief   calculate remainder
 */
#include <stdio.h>

int main(void)
{
  int base, denominator;

  printf("This program computes moduli.\n");
  printf("Enter an integer to serve as the second operand: ");
  scanf("%d", &base);
  printf("Now enter the first operand: ");
  scanf("%d", &denominator);

  while (denominator != 0) {  // little modification to allow negative denominator
    printf("%d %% %d is %d\n", denominator, base, denominator % base);
    printf("Enter next number for first operand (<= 0 to quit): ");
    scanf("%d", &denominator);
  }

  return 0;
}
