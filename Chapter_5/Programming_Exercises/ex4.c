/**
 * @file    ex4.c
 * @brief   prompt for height in centimeter to in feet and inches
 */
#include <stdio.h>

#define CM_PER_INCH 2.54
#define INCH_PER_FOOT 12

int main(void)
{
  float cm, inch;
  int foot;

  printf("Enter a height in centimeters: ");
  scanf("%f", &cm);

  while (cm > 0)
  {
    inch = cm / CM_PER_INCH;
    foot = inch / INCH_PER_FOOT;
    inch = inch - foot * INCH_PER_FOOT;

    printf("%.1f cm = %d feet, %.1f inches\n", cm, foot, inch); 
    printf("Enter a height in centimeters (<=0 to quit): ");
    scanf("%f", &cm);
  }

  printf("bye\n");

  return 0;
}
