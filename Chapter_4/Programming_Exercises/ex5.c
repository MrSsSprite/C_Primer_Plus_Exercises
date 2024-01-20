/**
 * @file    ex5.c
 * @brief   ask for download speed and file size, and estimate the download time
 */
#include <stdio.h>

int main(void)
{
  float size, speed;

  printf("What is the file size in megabytes? ");
  scanf("%f", &size);
  printf("What is the download speed in megabits per second? ");
  scanf("%f", &speed);

  /*
     > At 18.12 megabits per second, a file of 2.20 megabytes
     > downloads in 0.97 seconds.
   */
  // Note that in this context one byte is eight bits.
  printf("At %.2f megabits per second, a file of %.2f megabytes\n",
         speed, size);
  printf("downloads in %.2f seconds.\n", size * 8.0 / speed);

  return 0;
}
