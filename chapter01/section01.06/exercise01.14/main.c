#include <stdio.h>

#define CHARS      26
#define MAX_LENGTH 2 * CHARS // Only displaying letters ([A-Za-z]), 2 * 26.

int main() {
  int c, max_no_words_by_char;
  max_no_words_by_char = 0;
  int no_words_by_char[MAX_LENGTH] = { };

  while ((c = getchar()) != EOF) {
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
      int index_after_offset;
      if (c >= 'A' && c <= 'Z') index_after_offset = c - 'A';
      else                      index_after_offset = c - 'a' + CHARS;

      no_words_by_char[index_after_offset]++;
      max_no_words_by_char = no_words_by_char[index_after_offset] > max_no_words_by_char
        ? no_words_by_char[index_after_offset]
        : max_no_words_by_char;
    }
  }

  // Display a histogram vertically.
  for (int i = max_no_words_by_char; i > 0; i--) {
    for (int j = 0; j < MAX_LENGTH; j++) {
      if (no_words_by_char[j] >= i) {
        printf("|");
      }
      else {
        printf(" ");
      }
    }
    printf("\n");
  }

  // Display horizontal axis.
  for (int j = 0; j < MAX_LENGTH; j++) {
    printf("%c", j < CHARS ? 'A' + j : 'a' - CHARS + j);
  }
  printf("\n");
}
