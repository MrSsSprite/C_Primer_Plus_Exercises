/** 
 * @file    ex2.c
 * @brief   prompt for first name, and then format and print it.
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
  char first_name[30];

  printf("What's your first name?\t");
  scanf("%s", first_name);

  printf("\n\n");

  printf("Section A:\n");
  printf("\"%s\"\n\n", first_name);

  printf("Section B:\n");
  printf("\"%20s\"\n\n", first_name);

  printf("Section C:\n");
  printf("\"%-20s\"\n\n", first_name);

  printf("Section D:\n");
  printf("[%*s]\n", strlen(first_name) + 3, first_name);

  return 0;
}
