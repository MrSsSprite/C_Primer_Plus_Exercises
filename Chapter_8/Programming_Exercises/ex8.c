/**
 * @file    ex8.c
 */
#include <stdio.h>

char menu_prompt(void);
void get_num(float val[2]);

int main(void)
{
  char ch;
  char operator;
  float val[2];
  float result;

  while ((ch = menu_prompt()) != 'q')
  {
    get_num(val);
    switch (ch)
    {
    case 'a':
      result = val[0] + val[1];
      operator = '+';
      break;
    case 's':
      result = val[0] - val[1];
      operator = '-';
      break;
    case 'm':
      result = val[0] * val[1];
      operator = '*';
      break;
    case 'd':
      while (val[1] == 0.0)
      {
        printf("Enter a number other than 0: ");
        scanf("%f", val + 1);
      }
      result = val[0] / val[1];
      operator = '/';
      break;
    default:
      printf("Error! This should never be reached!\n");
      return 1;
    }
    printf("%f %c %f = %f\n", val[0], operator, val[1], result);

    // clean the remnant
    while (getchar() != '\n')
      continue;
  }

  return 0;
}

void _menu_message(void)
{
  printf("Enter the operation of your choice:\n");
  printf("a. add             s. subtract\n");
  printf("m. multiply        d. divide\n");
  printf("q. quit\n");
}

char menu_prompt(void)
{
  char ch;

  while (1)
  {
    switch (_menu_message(), ch = getchar())
    {
    case 'a':
    case 's':
    case 'm':
    case 'd':
    case 'q':
      return ch;
    }

    printf("Invalid Input\n");
  }
}

void get_num(float val[2])
{
  while (printf("Enter the first number: "),
         scanf("%f", val) != 1)
  {
    printf("Invalid Input\n");
    while (getchar() != '\n')
      continue;
  }

  while (printf("Enter the second number: "),
         scanf("%f", val + 1) != 1)
  {
    printf("Invalid Input\n");
    while (getchar() != '\n')
      continue;
  }
}
