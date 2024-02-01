/**
 * @file    ex2.c
 * @brief   copy file
 */
#include <stdio.h>

int main(int argc, char **argv)
{
  FILE *infile, *outfile;
  int byte;

  if (argc != 3)
  {
    fprintf(stderr, "Usage: %s source_file destination\n", argv[0]);
    return 1;
  }
  if ((infile = fopen(argv[1], "rb")) == NULL)
  {
    fprintf(stderr, "Cannot open source_file(%s)\n", argv[1]);
    return 1;
  }
  if ((outfile = fopen(argv[2], "wb")) == NULL)
  {
    fprintf(stderr, "Cannot open destination file (%s)\n", argv[2]);
    return 1;
  }

  while ((byte = getc(infile)) != EOF)
    putc(byte, outfile);

  if (fclose(infile))
    fprintf(stderr, "Failed to close the source_file\n");
  if (fclose(outfile))
    fprintf(stderr, "Failed to close the destination file\n");

  return 0;
}
