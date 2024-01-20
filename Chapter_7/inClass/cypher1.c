/**
 * @file    cypher1.c
 * @brief   alters input, preserving spaces
 */
#include <stdio.h>
#define SPACE ' '

int main(void)
{
  char ch;                // that's quote-space-quote

  ch = getchar();         // read a character
  while (ch != '\n')      // while not end of line
  {
    if (ch == SPACE)      // leave the space
      putchar(ch);        // character unchanged
    else
      putchar(ch + 1);    // change other characters
    ch = getchar();       // get next character
  }
  putchar(ch);            // print the newline

  return 0;
}
