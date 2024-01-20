/**
 * @file    ex3.c
 * @brief   sounds an alert and print text
 *
 *          Write a program that sounds an alert and then prints the following text:
 *          ```terminal
 *          Started by the sudden sound, Sally shouted,
 *          "By the Great Pumpkin, what was that!"
 *          ```
 */

#include <stdio.h>

int main(void)
{
  printf("\a");
  printf("Started by the sudden sound, Sally shouted,\n");
  printf("\"By the Great Pumpkin, what was that!\"\n");

  return 0;
}
