#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size.

int getline_(char line[], int maxline); // Used `getline_` instead of `getline` to avoid
                                        // a name conflict with function from standard library.
void copy(char to[], char from[]);
int is_line_full(char line[], int len);

/*
 * Print the longest length of input line.
 */
int main() {
  int len;                 // Current line length.
  int len_accumulated = 0; // Accumulated (total) line length,
                           // in case that line length is greater than `MAXLINE` - 1.
  int max;                 // Maximum length seen so far.
  char line[MAXLINE];      // Current input line.
  char longest[MAXLINE];   // Longest line saved here.

  max = 0;
  while ((len = getline_(line, MAXLINE)) > 0) {
    len_accumulated += len;

    if (!is_line_full(line, len)) {
      if (len_accumulated > max) {
        max = len_accumulated;
      }
      len_accumulated = 0;
    }
  }

  if (max > 0) {// There was a line.
    printf("Longest length of input line: %d.\n", max);
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

/*
 * copy: Copy `from` into `to`; assume to is big enough.
 */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

int is_line_full(char line[], int len) {
  return len >= MAXLINE - 1 && line[MAXLINE - 1] != '\n';
}
