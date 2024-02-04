/**
 * @file    ex11.c
 * @brief   search for lines in a file that contains a given string
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  FILE *file;
  char line[256];

  if (argc != 3)
  {
    fprintf(stderr, "Usage: %s string_pattern filename\n", argv[0]);
    exit(1);
  }
  if ((file = fopen(argv[2], "r")) == NULL)
  {
    fprintf(stderr, "Failed to open %s for reading.\n", argv[2]);
    exit(2);
  }

  for (unsigned long line_no = 1; fgets(line, 256, file); line_no++)
    if (strstr(line, argv[1]))
      printf("%-4lu %s", line_no, line);

  if (fclose(file))
    fprintf(stderr, "Error occurred when closing %s.\n", argv[2]);

  return 0;
}
