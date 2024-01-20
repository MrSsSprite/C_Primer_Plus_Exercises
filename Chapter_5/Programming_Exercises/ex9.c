/**
 * @file    ex9.c
 * @brief   convert temperature in Fahrenheit to Celsius and Kelvin
 */
#include <stdio.h>

void Temperatures(double fahrenheit);

int main(void)
{
  double fahrenheit;

  printf("Input a Fahrenheit temperature: ");
  while (scanf("%lf", &fahrenheit) == 1) {
    Temperatures(fahrenheit);
    printf("Input a Fahrenheit temperature(or 'q' to leave): ");
  }

  return 0;
}

void Temperatures(double fahrenheit) {
  const double base_modifier = -32, scale_modifier = 5.0 / 9.0, 
               kelvin_modifier = 273.16;
  double celsius = (fahrenheit + base_modifier) * scale_modifier,
         kelvin = celsius + kelvin_modifier;
  printf("%.2f Fahrenheit is %.2f Celsius (or %.2f Kelvin).\n",
         fahrenheit, celsius, kelvin);
}
