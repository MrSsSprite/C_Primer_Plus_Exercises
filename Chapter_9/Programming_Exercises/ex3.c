#include <stdio.h>
#include <ctype.h>

void print_block(char ch, int width, int height);

int get_nonspace(void);

int main(void)
{
  int ch;
  int width, height;

  while (printf("Input the char, width, and height:\n"),
         (ch = get_nonspace()) != EOF && scanf("%d %d", &width, &height) == 2)
  {
    print_block(ch, width, height);
    printf("\n");
  }

  printf("Bye.\n");

  return 0;
}

int get_nonspace(void)
{
  char ch;
  while (isspace(ch = getchar()))
    continue;

  return ch;
}

void print_block(char ch, int width, int height)
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
      putchar(ch);
    putchar('\n');
  }
}
