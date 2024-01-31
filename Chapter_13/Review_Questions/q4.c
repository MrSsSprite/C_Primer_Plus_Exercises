#include <stdio.h>

int main(int argc, char **argv)
{
  FILE *fp;
  float value;
  float total = 0.0;
  unsigned int count = 0;

  switch (argc)
  {
  case 1:
    fp = stdin;
    break;
  case 2:
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
      fprintf(stderr, "Invalid File Path.\n");
      return 1;
    }
    break;
  default:
    fprintf(stderr, "Usage: %s [input file]\n", argv[0]);
    return 1;
  }

  while (fscanf(fp, "%f", &value) == 1)
  {
    total += value;
    count++;
  }

  if (count)
    fprintf(stdout, "The arithmetic mean: %f\n", total / count);
  else
    fprintf(stdout, "No value found.\n");

  if (argc == 2)
    fclose(fp);

  return 0;
}
