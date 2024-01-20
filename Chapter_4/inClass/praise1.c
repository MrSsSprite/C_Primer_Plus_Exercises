/**
 * @file    praise1.c
 * @brief   uses an assortment of strings
 */
#include <stdio.h>
#define PRAISE "You are an extraordinary beging."

int main(void)
{
  char name[40];
  
  printf("What's your name? ");
  scanf("%s", name);
  printf("Hello, %s. %s\n", name, PRAISE);

  return 0;
}
