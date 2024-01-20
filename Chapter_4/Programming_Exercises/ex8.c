/**
 * @file    ex8.c
 * @brief   input miles traveled and gallons consumed, output efficiency in both US and European
 */
#include <stdio.h>

#define LITER_PER_GALLON 3.785
#define KM_PER_MILE 1.609

int main(void)
{
  float miles_traveled, gallon_consumption;

  printf("How many miles your car has traveled? ");
  scanf("%f", &miles_traveled);
  printf("How many gallons of gasoline it has consumed? ");
  scanf("%f", &gallon_consumption);
  printf("\n");

  printf("miles-per-gallon: %.1f\n", miles_traveled / gallon_consumption);
  printf("liters-per-100-km: %.1f\n",
         (gallon_consumption * LITER_PER_GALLON) /
         (miles_traveled * KM_PER_MILE / 100));

  return 0;
}
