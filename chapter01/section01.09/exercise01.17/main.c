#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size.
#define MINLINE 80   // Minimum input line size to print.

int getline_(char line[], int maxline); // Used `getline_` instead of `getline` to avoid
                                        // a name conflict with function from standard library.
int is_line_full(char line[], int len);

/*
 * Print lines longer than `MINLINE` characters.
 */
int main() {
  int len;                 // Current line length.
  int len_accumulated = 0; // Accumulated (total) line length,
                           // in case that line length is greater than `MAXLINE` - 1.
  char line[MAXLINE];      // Current input line.

  while ((len = getline_(line, MAXLINE)) > 0) {
    len_accumulated += len;

    if (len_accumulated > MINLINE) {
      printf("%s", line);
    }

    if (!is_line_full(line, len)) {
      len_accumulated = 0;
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

int is_line_full(char line[], int len) {
  return len >= MAXLINE - 1 && line[MAXLINE - 1] != '\n';
}
