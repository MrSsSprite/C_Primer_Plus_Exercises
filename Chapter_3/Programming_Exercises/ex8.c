/**
 * @file    ex8.c
 * @brief   convert volume from cups to (pints & ounces & tablespoons & teaspoons)
 */

#include <stdio.h>

int main(void)
{
  float vol_cup, temp;
  printf("Input the volume, in cups: ");
  scanf("%f", &vol_cup);

  printf("%.1f cups is equivalent to %.1f pints, ",
         vol_cup, vol_cup / 2.0);
  temp = vol_cup * 8.0;
  printf("%.1f ounces, ", temp); 
  temp *= 2.0;
  printf("%.1f tablespoons, and ", temp);
  temp *= 3.0;
  printf("%.1f teaspoons.\n", temp);

  return 0;
}
