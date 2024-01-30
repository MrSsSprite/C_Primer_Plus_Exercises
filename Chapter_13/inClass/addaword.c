/**
 * @file    addaword.c
 * @brief   uses fprintf, fscanf, and rewind
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main(void)
{
  FILE *fp;
  char words[MAX];
  char format_string[20];
  int status;

  if ((fp = fopen("wordy", "a+")) == NULL)
  {
    fprintf(stdout, "Can't open \"wordy\" file.\n");
    exit(EXIT_FAILURE);
  }

  puts("Enter words to add to the file; press the #");
  puts(" key at the beginning of a line to terminate.");
  status = snprintf(format_string, sizeof format_string, "%%%zds", MAX - 1);
  if (status < 0 || status >= sizeof format_string)
  {
    fprintf(stderr, "sizeof format_string is not sufficient\n");
    return -1;
  }
  while (fscanf(stdin, format_string, words) == 1 && words[0] != '#')
    fprintf(fp, "%s\n", words);

  puts("File contents:");
  rewind(fp);           /* go back to beginning of file */
  while (fscanf(fp, "%s", words) == 1)
    puts(words);
  puts("Done!");
  if (fclose(fp) != 0)
    fprintf(stderr, "Error closing file\n");

  return 0;
}
