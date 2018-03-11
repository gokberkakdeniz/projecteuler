#include <stdio.h>
#define true 1
#define false 0
#define LENGTH_BASE10 7
#define LENGTH_BASE2 20

int is_palindrome(int number) {
  int digits[LENGTH_BASE10] = {0};
  int i;
  for(i=LENGTH_BASE10-1; i>=0; i--) {
    int digit = number % 10;
    number = (number - digit)/10;
    digits[i] = digit;
    if (number == 0) break;
  }
  int j = LENGTH_BASE10-1;
  int flag = true;
  int bound = (LENGTH_BASE10+i)/2;
  for (i=i;i<=bound; i++, j--) {
    if (i==j) break;
    if (digits[i]!=digits[j]) {
      flag = false;
      break;
    }
  }
  return flag;
}

int is_palindrome_binary(int number) {
  int digits[LENGTH_BASE2] = {0};
  int i = LENGTH_BASE2-1;
  while (number != 0) {
    digits[i] = number % 2;
    number /= 2;
    i--;
  }
  int j = LENGTH_BASE2-1;
  int flag = true;
  int bound = (LENGTH_BASE2+i)/2;
  i++;
  for (;i<=bound; i++, j--) {
    if (i==j) break;
    if (digits[i]!=digits[j]) {
      flag = false;
      break;
    }
  }
  return flag;
}

int main() {
  int sum=0;
  for (int i=0; i<1000000;i++) {
    if (is_palindrome(i) && is_palindrome_binary(i)) sum +=i;
  }
  printf("%d\n", sum);
  return 0;
}
