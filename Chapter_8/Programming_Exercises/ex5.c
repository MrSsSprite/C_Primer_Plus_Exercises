/**
 * @file    ex5.c
 * @brief   guess number
 */
#include <stdio.h>
#include <ctype.h>

int get_nonspace(void);

int main(void)
{
  int low = 1, high = 101, mid = (low + high) / 2;
  int ch;

  printf("Think an integer between 1 and 100, inclusive\n"
         "Now, tell me if my guess is too high, low, or just correct\n"
         "(Input h for high, l for low, c for correct)\n");

  while (printf("Is it %d? ", mid),
         low != high && (ch = get_nonspace()) != 'c')
  {
    switch (ch)
    {
    case 'h':
      high = mid;
      break;
    case 'l':
      low = mid + 1;
      break;
    default:
      printf("Invalid Input\n(Input h for high, l for low, c for correct)\n");
      continue;
    }
    mid = (low + high) / 2;
  }

  if (low == high)
    printf("No way, you definitely messed up something!\n");
  else
    printf("I knew I can do it!\n");

  return 0;
}

int get_nonspace(void)
{
  int ret;
  while (isspace(ret = getchar()))
    continue;
  return ret;
}
