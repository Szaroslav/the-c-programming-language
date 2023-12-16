#include <stdio.h>

int main() {
  int c;
  int no_spaces, no_tabs, no_newlines;
  no_spaces = no_tabs = no_newlines = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      no_spaces++;
    }
    else if (c == '\t') {
      no_tabs++;
    }
    else if (c == '\n') {
      no_newlines++;
    }
  }

  printf("Number of spaces:   %d\n", no_spaces);
  printf("Number of tabs:     %d\n", no_tabs);
  printf("Number of newlines: %d\n", no_newlines);
}
