/**
 * @file    ex6.c
 * @breif   read input up to terminating character and report the occurance of 
 *          "ei" sequence.
 */
#include <stdio.h>
#include <stdbool.h>

#define TERMINATING_CHAR '#'

int main(void)
{
  size_t ei_cnt = 0;
  char ch;
  bool prev_is_e = false;

  while ((ch = getchar()) != TERMINATING_CHAR)
  {
    if (prev_is_e && ch == 'i')
      ei_cnt++;

    if (ch == 'e')
      prev_is_e = true;
    else
      prev_is_e = false;
  }

  printf("The \"ei\" sequence occurs in the text %zd time%s.\n",
         ei_cnt, (ei_cnt == 1 ? "" : "s"));

  return 0;
}
