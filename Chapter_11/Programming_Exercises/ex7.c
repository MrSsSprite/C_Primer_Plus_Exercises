/**
 * @file    ex7.c
 * @brief   write my version of strncpy, and test it
 */
#include <stdio.h>
#include <stdlib.h>

char *mystrncpy(char *dst, const char *src, size_t len);
char *get_string(void);
size_t get_len(void);
void show_string(const char *str, const char *const str_ed);

int main(void)
{
  char *source, *dest;
  size_t len;
  int ch;

  while (printf("Input a line of string (empty line to quit):\n"),
         source = get_string())
  {
    // empty string
    if (source[0] == '\0')
    {
      free(source);
      break;
    }

    printf("Your Input:\n%s\n", source);

    // get len
    if ((len = get_len()) < 0)
    {
      printf("Ending the program...\n");
      free(source);
      break;
    }

    // allot memory and copy the string
    dest = malloc(len + 1);
    mystrncpy(dest, source, len);
    dest[len] = '\0';

    // display the copied string
    show_string(dest, dest + len + 1);
    putchar('\n');

    // free mem
    free(source);
    free(dest);
    printf("\n======================\n");
  }

  return 0;
}

char *get_string(void)
{
  size_t cap = 1;
  char *string = malloc(cap), *cavity = string, *terminal = string + cap;
  int ch;

  if (string == NULL)
    return string;

  while ( (ch = getchar()) != EOF && ch != '\n')
  {
    // check for enough space
    if (cavity == terminal)
    {
      if ((string = reallocf(string, cap * 2)) == NULL)
        return string;
      cavity = string + cap;
      terminal = string + (cap *= 2);
    }
    *cavity++ = ch;
  }
  if (cavity == terminal)
  {
    if ((string = reallocf(string, cap + 1)) == NULL)
      return string;
    cavity = string + cap;
  }
  *cavity = '\0';

  return string;
}

size_t get_len(void)
{
  size_t ret;
  int ch;

  while (printf("# of characters to copy: "),
         scanf("%zd", &ret) != 1)
  {
    // consume the remnant of the line
    while ((ch = getchar()) != EOF && ch != '\n')
      continue;
    if (ch == EOF)
    {
      fprintf(stderr, "EOF detected. ");
      return -1;
    }
    printf("Invalid Input.\n");
  }
  while ((ch = getchar()) != EOF && ch != '\n')
    continue;

  return ret;
}

char *mystrncpy(char *dst, const char *src, size_t len)
{
  char *dst_ed = dst + len;

  while (dst < dst_ed && *src)
    *dst++ = *src++;

  while (dst < dst_ed)
    *dst++ = '\0';

  return dst;
}

void show_string(const char *str, const char *const str_ed)
{
  while (str < str_ed)
  {
    if (*str)
      putchar(*str);
    else
      printf("\\0");
    str++;
  }
}
