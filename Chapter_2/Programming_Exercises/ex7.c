#include <stdio.h>

int main(void)
{
  for (int i = 3; i > 0; i--) {
    for (int j = 0; j < i; j++)
      printf("Smile!");
    printf("\n");
  }

  return 0;
}
