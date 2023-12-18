#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size.

int getline_(char line[], int maxline); // Used `getline_` instead of `getline` to avoid
                                        // a name conflict with function from standard library.

/*
 * Print lines with removed trailing spaces or tabs, don't print entirely blank lines.
 */
int main() {
  int len;                 // Current line length.
  int len_accumulated = 0; // Accumulated (total) line length,
                           // in case that line length is greater than `MAXLINE` - 1.
  char line[MAXLINE];      // Current input line.

  while ((len = getline_(line, MAXLINE)) > 0) {
    int i = 0;
    while (i < len && line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
      i++;

    if (i < len) {
      printf("%s", line + i);
    }
  }

  return 0;
}

/*
 * getline: Read a line into s, return length.
 */
int getline_(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}
