#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != EOF)
    printf("Read a char '%c', value of getchar() != EOF: %d\n", c, c != EOF);
  printf("End of file, value of getchar() != EOF: %d\n", c != EOF);
}
