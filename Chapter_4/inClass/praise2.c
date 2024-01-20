/**
 * @file    praise2.c
 * @brief   modify prase1.c to discuss the property of string
 * @see     prase1.c
 */
#include <stdio.h>
#include <string.h>         // provides strlen() prototype
#define PRAISE "You are an extraordinary being."

int main(void)
{
  char name[40];
  
  printf("What's your name? ");
  scanf("%s", name);
  printf("Hello, %s. %s\n", name, PRAISE);

  printf("Your name of %zd letters occupies %zd memoery cells.\n",
         strlen(name), sizeof name);
  printf("The phrase of praise has %zd letters ", strlen(PRAISE));
  printf("and occupies %zd memory cells.\n", sizeof PRAISE);

  return 0;
}
