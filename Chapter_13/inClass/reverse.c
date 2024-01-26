/**
 * @file    reverse.c
 * @brief   displays a file in reverse order
 */
#include <stdio.h>
#include <stdlib.h>

#define CNTL_Z '\032'     /* eof marker in DOS text files */
#define SLEN 81

int main(void)
{
  char file[SLEN], format_string[20];
  char ch;
  int status;
  FILE *fp;
  long count, last;

  puts("Enter the name of the file to be processed:");
  status = snprintf(format_string, 20, "%%%zds", sizeof file - 1);
  if (status < 0 || status >= 20)
  {
    fprintf(stderr, "sizeof file not sufficient\n");
    return -1;
  }
  scanf(format_string, file);
  if ((fp = fopen(file, "rb")) == NULL)
  {
    printf("reverse can't open %s\n", file);
    exit(EXIT_FAILURE);
  }
  fseek(fp, 0L, SEEK_END);    /* go to end of file */
  last = ftell(fp);
  for (count = 1L; count <= last; count++)
  {
    fseek(fp, -count, SEEK_END);  /* go backward */
    ch = getc(fp);
    if (ch != CNTL_Z && ch != '\r') /* MS-DOS files */
      putchar(ch);
  }
  putchar('\n');
  fclose(fp);

  return 0;
}
