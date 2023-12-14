#include <stdio.h>

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = -100;
  upper = 100;
  step  = 10;

  printf("Celsius  Fahrenheit\n");

  celsius = lower;
  while (celsius <= upper) {
    fahr = (9.0 / 5.0) * celsius + 32.0;
    printf("%7.0f  %4.0f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
