/**
 * @file    ex4.c
 * @brief   prompt for height in inches, and print in feet
 */
#include <stdio.h>

int main(void)
{
  char name[40];
  float height;

  printf("What is your name?\t");
  scanf("%s", name);
  printf("%s, what is your height in inches?\t", name);
  scanf("%f", &height);

  printf("%s, you are %.3f feet tall.\n", name, height / 12.0);

  return 0;
}
