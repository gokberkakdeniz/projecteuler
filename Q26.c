#include <stdio.h>
#include <stdlib.h>

int fraction_length(int n) {
  int remain = 1, i = 0;
  int *remains;
  remains = (int*)calloc(n, sizeof(int));
  while (remain != 0 && remains[remain] == 0) {
    remains[remain] = i++;
    remain = remain * 10 % n;
  }
  int fraction_length = i - remains[remain];
  free(remains);
  return remain == 0 ? 0 : fraction_length;
}

int main() {
  int ll=0, ln=0, n;
  for (size_t i = 1; i < 1000; i++) {
    n = fraction_length(i);
    if (n > 0 && n > ll) {
        ll = n;
        ln = i;
    }
  }
  printf("1/%d with %d length\n", ln, ll);
}
