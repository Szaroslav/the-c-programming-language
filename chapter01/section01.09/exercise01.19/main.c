#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size.

int getline_(char line[], int maxline); // Used `getline_` instead of `getline` to avoid
                                        // a name conflict with function from standard library.
void reverse(char string[], int length);

/*
 * Print lines with removed trailing spaces or tabs, don't print entirely blank lines.
 */
int main() {
  int len;                 // Current line length.
  int len_accumulated = 0; // Accumulated (total) line length,
                           // in case that line length is greater than `MAXLINE` - 1.
  char line[MAXLINE];      // Current input line.

  while ((len = getline_(line, MAXLINE)) > 0) {
    reverse(line, len - 1);
    printf("%s", line);
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

void reverse(char string[], int length) {
  for (int i = 0; i < length / 2; i++) {
    char temp = string[i];
    string[i] = string[length - i - 1];
    string[length - i - 1] = temp;
  }
}
