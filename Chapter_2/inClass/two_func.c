/**
 * @file    two_func.c
 * @brief   a program using two functions in one file
 * @author  Ryan Lam
 * @version 1.0
 * @date    Dec 23, 2023
 */

#include <stdio.h>

void butler(void);

int main(void) {
  printf("I will summon the butler function.\n");
  butler();
  printf("Yes. Bring me some tea and writeable DVDs.\n");

  return 0;
}

void butler(void) { printf("You rang, sir?\n"); }
