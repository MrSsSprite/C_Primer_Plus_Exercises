/**
 * @file    ex12.c
 * @brief   modify the inclass rain.c with the main tasks packed into functions
 * @see     ../inClass/rain.c
 */
#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12
#define YEARS   5

float *year_avg(const float data[YEARS][MONTHS]);
float *month_avg(const float data[YEARS][MONTHS]);

int main(void)
{
  // initializing rainfall data for 2010 - 2014
  const float rain[YEARS][MONTHS] =
  {
    {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
    {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
    {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
    {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
    {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
  };
  float total;
  float *res_ptr;

  res_ptr = year_avg(rain);
  printf("%5s %15s\n",
         "YEAR",
         "RAINFALL  (inches)");
  total = 0;
  for (int year = 0; year < YEARS; year++)
  {
    total += res_ptr[year];
    printf("%5d %15.1f\n", 2010 + year, res_ptr[year]);
  }
  printf("\nThe yearly average is %.1f inches.\n\n",
         total / YEARS);
  free(res_ptr);

  res_ptr = month_avg(rain);
  printf("MONTHLY AVERAGES:\n\n");
  printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
  printf(" Nov  Dec\n");
  for (int month = 0; month < MONTHS; month++)
    printf("%4.1f ", res_ptr[month]);
  putchar('\n');
  free(res_ptr);

  return 0;
}

float *year_avg(const float data[YEARS][MONTHS])
{
  float *ret = malloc(YEARS * sizeof (float));
  for (int i = 0; i < YEARS; i++)
  {
    ret[i] = 0.0;
    for (int j = 0; j < MONTHS; j++)
      ret[i] += data[i][j];
  }

  return ret;
}

float *month_avg(const float data[YEARS][MONTHS])
{
  float *ret = malloc(MONTHS * sizeof (float));
  for (int i = 0; i < MONTHS; i++)
  {
    ret[i] = 0.0;
    for (int j = 0; j < YEARS; j++)
      ret[i] += data[j][i];
  }

  return ret;
}
