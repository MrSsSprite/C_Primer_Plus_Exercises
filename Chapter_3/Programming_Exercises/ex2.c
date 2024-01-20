/**
 * @file    ex2.c
 * @brief   converts ASCII code to char output
 *          Write a program that asks you to enter an ASCII code value, such as `66`,
 * and then prints the character having that ASCII code.
 */

#include <stdio.h>

int main(void)
{
  char c;
  printf("Input an ASCII value: __\b\b");
  scanf("%d", &c);

  printf("The according character is \'%c\'\n", c);

  return 0;
}
