#include <iostream>
#include <cmath>

// int combination (int n, int k) {
//   int a = 1, b = 1, i;
//   for (i = n; i >= n-k+1; a*=i, i--);
//   for (i = 2; i <= k; b*=i, i++);
//   return a/b;
// }

int main() {
  int digits[1000] = {0};
  int power, index, product;
  digits[999] = 1;
  for(power = 1, index = 999; power < 6; power++, index--) {
    product = digits[index] * 2;
    std::cout << digits[index] << " ";
    if (product < 10) {
      digits[index] = product;
      index--;
    } else {
      digits[index] = product % 10;
      digits[index-1] = 1;
    }
  }
  int sum = 0;
  std::cout << std::endl << '\n';
  for (index = 0; index < 1000; index++) {
    std::cout << digits[index];
    sum+=digits[index];
  }
  std::cout << std::endl << sum << '\n';
}
