#include <stdio.h>

int main(void)
{
  const char *first_name = "Ryan", *last_name = "Lam";

  printf("%s %s\n", first_name, last_name);
  printf("%s\n%s\n", first_name, last_name);
  printf("%s ", first_name);
  printf("%s\n", last_name);
  return 0;
}
