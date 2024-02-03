/**
 * @file    ex8.c
 * @brief   count the occurence of a character in the given files
 *
 *          compiled with ex8_impl.c
 */
#include <stdio.h>
#include <stdlib.h>

#include "ex8.h"

int main(int argc, char **argv)
{
  struct file_info file;
  unsigned long count;

  if (argc < 2)
  {
    fprintf(stderr, "Usage: %s [character] [filename]...\n", argv[0]);
    exit(1);
  }
  if (argv[1][1] != '\0')
  {
    fputs("The first argument must be A character.\n", stderr);
    exit(1);
  }

  if (argc == 2)
    set_mode_stdin();
  else
    set_mode_cla(argc, argv);

  while ((file = next_file()).file)
  {
    count = appear_ct(argv[1][0], file.file);
    printf("The character '%c' appears in %s %lu time%s.\n",
           argv[1][0], file.name, count, count == 1 ? "" : "s");
    if (fclose(file.file))
      fputs("Failed to close %s.\n", stderr);
    free(file.name);
  }

  fputs("Done.\n", stdout);

  return 0;
}
