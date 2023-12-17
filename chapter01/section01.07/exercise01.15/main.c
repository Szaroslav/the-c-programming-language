#include <stdio.h>

float fahrenheit_to_celsius(float);

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step  = 20;

  printf("Fahrenheit  Celsius\n");

  fahr = lower;
  while (fahr <= upper) {
    celsius = fahrenheit_to_celsius(fahr);
    printf("%10.0f  %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

float fahrenheit_to_celsius(float x) {
  return (5.0 / 9.0) * (x - 32.0);
}
