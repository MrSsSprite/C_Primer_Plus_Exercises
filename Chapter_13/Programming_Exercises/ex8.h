#ifndef ex8_h
#define ex8_h

#include <stdio.h>

struct file_info
{
  char *name;
  FILE *file;
};

void set_mode_cla(int argc, char **argv);

void set_mode_stdin(void);

struct file_info next_file(void);

unsigned long appear_ct(char key_ch, FILE *file);

#endif
