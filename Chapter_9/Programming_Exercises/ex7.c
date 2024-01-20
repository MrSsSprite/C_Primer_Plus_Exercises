#include <stdio.h>
#include <ctype.h>

int to_num_loc(char ch);

int main(void)
{
  int ch;
  int loc;
  int counter = 0;

  while ((ch = getchar()) != EOF)
  {
    loc = to_num_loc(ch);
    putchar(loc == -1 ? '0' : '1');
    if (loc != -1)
      printf("(%2d) ", loc);
    else
      printf("     ");
    if (++counter == 8)
    {
      putchar('\n');
      counter = 0;
    }
    if (ch == '\n')
      putchar('\n');
  }

  printf("\nDone!\n");

  return 0;
}

int to_num_loc(char ch)
{
  if (isupper(ch))
    return ch - 'A' + 1;
  else if (islower(ch))
    return ch - 'a' + 1;
  else
    return -1;
}
