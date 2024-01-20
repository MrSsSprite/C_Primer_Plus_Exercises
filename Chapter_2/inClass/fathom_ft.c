/**
 * @file    fathom_ft.c
 * @brief   Convert 2 fathom to feet
 * @author  Ryan Lam
 * @date    Dec 23, 2023
 * @version 1.0
 */

#include <stdio.h>

int main(void)
{
  int feet, fathoms;

  fathoms = 2;
  feet = 6 * fathoms;
  printf("There are %d feet in %d fathoms!\n", feet, fathoms);
  printf("Yes, I said %d feet!\n", 6 * fathoms);

  return 0;
}
