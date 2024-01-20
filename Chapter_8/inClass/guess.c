/**
 * @file    guess.c
 * @brief   an inefficient and faulty number-guesser
 */
#include <stdio.h>

int main(void)
{
  int guess = 1;

  printf("Pick an integer from 1 to 100. I will try to guess ");
  printf("it.\nRespond with a y if my guess is right and with");
  printf("\nan n if it is wrong.\n");
  printf("Uh...is your number %d?\n", guess);
  while (getchar() != 'y')        /* get response, compare to y */
  {
    printf("Well, then, is is %d?\n", ++guess);

    while (getchar() != '\n')     /* consume rest of the line */
      continue;
  }
  printf("I knew I could do it!\n");

  return 0;
}
