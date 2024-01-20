/**
 * @file    ex5.c
 */
#include <stdio.h>

int main(void)
{
  char inp_letter;
  
  printf("Input an uppercase letter: ");
  scanf("%c", &inp_letter);
  if (inp_letter < 'A' || inp_letter > 'Z') {
    printf("Invalid Input\n");
    return 1;
  }

  for (int row = 0, tot_row = inp_letter - 'A';
       row <= tot_row; row++)
  {
    for (int i = 0, space_num = inp_letter - 'A' - row;
         i < space_num; i++)
      printf(" ");
    char c = 'A';
    const char last_char = 'A' + row;
    while (c < last_char)
      printf("%c", c++);
    while (c >= 'A')
      printf("%c", c--);
    for (int i = 0, space_num = inp_letter - 'A' - row;
         i < space_num; i++)
      printf(" ");
    printf("\n");
  }

  return 0;
}
