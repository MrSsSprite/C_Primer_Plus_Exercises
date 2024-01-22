/**
 * @file    r_drive0.c
 * @brief   test the rand0 function
 */
#include <stdio.h>

extern int rand0(void);

int main(void)
{
  int count;

  for (count = 0; count < 5; count++)
    printf("%d\n", rand0());

  return 0;
}
