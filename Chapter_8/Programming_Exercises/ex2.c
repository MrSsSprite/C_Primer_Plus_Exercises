/**
 * @file    ex2.c
 * @brief   take input and shows corresponding ASCII code for each character
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int ch;
  char equiv[3];
  int counter = 0;

  while ((ch = getchar()) != EOF)
  {
    switch (ch)
    {
    case '\n':
      equiv[0] = '\\';
      equiv[1] = 'n';
      equiv[2] = '\0';
      break;
    case '\t':
      equiv[0] = '\\';
      equiv[1] = 't';
      equiv[2] = '\0';
      break;
    default:
      if (iscntrl(ch))
      {
        equiv[0] = '^';
        equiv[1] = ch + 64;
        equiv[2] = '\0';
      }
      else
      {
        equiv[0] = ch;
        equiv[1] = '\0';
      }
    }

    printf("%3s(%3d) ", equiv, ch);
    if (++counter == 10 || ch == '\n')
    {
      printf("\n");
      counter = 0;
    }
  }

  return 0;
}
