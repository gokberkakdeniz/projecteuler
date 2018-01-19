#include <iostream>
#define NUMBER 2000000

// using namespace boost::multiprecision;
int main() {
  int i, isPrime=1;
  long long int sum = 0;
  for (i=2; i < NUMBER; i++) {
    int j;
    isPrime=1;
    for (j=2; j*j<=i; j++) {
      if (i % j == 0) {
        isPrime = 0;
        break;
      }
    }
    if (isPrime) {
      sum+=i;
    }
  }
  std::cout << sum;
  return 0;
}
