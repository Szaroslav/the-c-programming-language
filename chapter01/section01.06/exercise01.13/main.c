#include <stdio.h>

#define IN         1  // Inside a word.
#define OUT        0  // Outside a word.
#define MAX_LENGTH 24 // Maximum length of word.

int main() {
  int c, word_length, max_no_words_by_length, state;
  word_length = max_no_words_by_length = 0;
  state = OUT;
  int no_words_by_length[MAX_LENGTH] = { };

  while ((c = getchar()) != EOF) {
    word_length++;

    if (c == ' ' || c == '\n' || c == '\t') {
      no_words_by_length[word_length]++;
      max_no_words_by_length = no_words_by_length[word_length] > max_no_words_by_length
        ? no_words_by_length[word_length]
        : max_no_words_by_length;
      word_length = 0;
    }
  }

  // Display a histogram vertically.
  for (int i = max_no_words_by_length; i > 0; i--) {
    for (int j = 0; j < MAX_LENGTH; j++) {
      if (no_words_by_length[j] >= i) {
        printf("|");
      }
      else {
        printf(" ");
      }
    }
    printf("\n");
  }
}
